/* lexer.c */
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "../../include/tokens.h"

// Line and column tracking
static int current_line = 1;
static int current_column = 1;
static char last_token_type = 'x'; // For checking consecutive operators
static int in_error_recovery = 0;  // Flag for error recovery mode

/* Reset the lexer state */
static void reset_lexer() {
    current_line = 1;
    current_column = 1;
    last_token_type = 'x';
    in_error_recovery = 0;
}

/* Advance position and update column count */
static void advance_position(int *pos) {
    (*pos)++;
    current_column++;
}

/* Skip until the next character that matches any in the given string */
static void skip_until(const char *input, int *pos, const char *delimiters) {
    while (input[*pos] != '\0' && !strchr(delimiters, input[*pos])) {
        if (input[*pos] == '\n') {
            current_line++;
            current_column = 1;
        } else {
            current_column++;
        }
        (*pos)++;
    }
}

/* Check if a string is a keyword */
static int is_keyword(const char *str) {
    for (int i = 0; i < NUM_KEYWORDS; i++) {
        if (strcmp(str, keywords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

/* Print error messages for lexical errors */
void print_error(ErrorType error, int line, const char *lexeme) {
    printf("Lexical Error at line %d: ", line);
    switch (error) {
        case ERROR_INVALID_CHAR:
            printf("Invalid character '%s'\n", lexeme);
            break;
        case ERROR_INVALID_NUMBER:
            printf("Invalid number format\n");
            break;
        case ERROR_CONSECUTIVE_OPERATORS:
            printf("Consecutive operators not allowed\n");
            break;
        case ERROR_UNTERMINATED_STRING:
            printf("Unterminated string literal\n");
            break;
        case ERROR_UNTERMINATED_CHAR:
            printf("Unterminated character literal\n");
            break;
        case ERROR_INVALID_IDENTIFIER:
            printf("Invalid identifier format\n");
            break;
        case ERROR_STRING_TOO_LONG:
            printf("String literal too long\n");
            break;
        case ERROR_INVALID_ESCAPE_SEQUENCE:
            printf("Invalid escape sequence\n");
            break;
        case ERROR_EMPTY_CHAR_LITERAL:
            printf("Empty character literal\n");
            break;
        case ERROR_MULTI_CHAR_LITERAL:
            printf("Multi-character literal not allowed\n");
            break;
        case ERROR_INVALID_FLOAT:
            printf("Invalid float format\n");
            break;
        case ERROR_RECOVERY_MODE:
            printf("Skipping invalid input\n");
            break;
        default:
            printf("Unknown error\n");
    }
}

/* Print token information
 *
 *  TODO Update your printing function accordingly
 */

void print_token(Token token) {
    if (token.type == TOKEN_SKIP) {
        return;
    }
    
    if (token.error != ERROR_NONE) {
        print_error(token.error, token.line, token.lexeme);
        return;
    }

    printf("Token: ");
    switch (token.type) {
        case TOKEN_NUMBER:
            printf("NUMBER");
            break;
        case TOKEN_FLOAT:
            printf("FLOAT");
            break;
        case TOKEN_OPERATOR:
            printf("OPERATOR");
            break;
        case TOKEN_IDENTIFIER:
            printf("IDENTIFIER");
            break;
        case TOKEN_KEYWORD:
            printf("KEYWORD");
            break;
        case TOKEN_STRING:
            printf("STRING");
            break;
        case TOKEN_CHAR:
            printf("CHAR");
            break;
        case TOKEN_DELIMITER:
            printf("DELIMITER");
            break;
        case TOKEN_COMMENT:
            printf("COMMENT");
            break;
        case TOKEN_POINTER:
            printf("POINTER");
            break;
        case TOKEN_EOF:
            printf("EOF");
            break;
        default:
            printf("UNKNOWN");
    }
    printf(" | Lexeme: '%s' | Line: %d | Column: %d\n",
           token.lexeme, token.line, token.column);
}

/* Handle the escape sequences in strings and chars */
static char handle_escape_sequence(char c) {
    switch (c) {
        case 'n': return '\n';
        case 't': return '\t';
        case 'r': return '\r';
        case '0': return '\0';
        case '\\': return '\\';
        case '\'': return '\'';
        case '\"': return '\"';
        default: return 0;
    }
}

/* Handle string literals */
static Token handle_string(const char *input, int *pos) {
    Token token = {TOKEN_STRING, "", current_line, current_column, ERROR_NONE, RECOVERY_NONE};
    int i = 0;
    advance_position(pos); // Skip opening quote
    
    while (input[*pos] != '\0' && input[*pos] != '"' && input[*pos] != '\n') {
        if (i >= sizeof(token.lexeme) - 1) {
            token.error = ERROR_STRING_TOO_LONG;
            token.recovery = RECOVERY_TO_NEWLINE;
            skip_until(input, pos, "\n\"");
            return token;
        }
        
        if (input[*pos] == '\\') {
            advance_position(pos);
            char escaped = handle_escape_sequence(input[*pos]);
            if (escaped == 0) {
                token.error = ERROR_INVALID_ESCAPE_SEQUENCE;
                token.recovery = RECOVERY_TO_NEWLINE;
                skip_until(input, pos, "\n\"");
                return token;
            }
            token.lexeme[i++] = escaped;
        } else {
            token.lexeme[i++] = input[*pos];
        }
        advance_position(pos);
    }
    
    if (input[*pos] != '"') {
        token.error = ERROR_UNTERMINATED_STRING;
        token.recovery = RECOVERY_TO_NEWLINE;
        return token;
    }
    
    advance_position(pos); // Skip closing quote
    token.lexeme[i] = '\0';
    return token;
}

/* Handle character literals */
static Token handle_char(const char *input, int *pos) {
    Token token = {TOKEN_CHAR, "", current_line, current_column, ERROR_NONE, RECOVERY_NONE};
    advance_position(pos); // Skip opening quote
    
    if (input[*pos] == '\'') {
        token.error = ERROR_EMPTY_CHAR_LITERAL;
        advance_position(pos);
        return token;
    }
    
    int i = 0;
    if (input[*pos] == '\\') {
        advance_position(pos);
        char escaped = handle_escape_sequence(input[*pos]);
        if (escaped == 0) {
            token.error = ERROR_INVALID_ESCAPE_SEQUENCE;
            token.recovery = RECOVERY_TO_NEWLINE;
            skip_until(input, pos, "\n\'");
            return token;
        }
        token.lexeme[i++] = escaped;
        advance_position(pos);
    } else {
        token.lexeme[i++] = input[*pos];
        advance_position(pos);
    }
    
    if (input[*pos] != '\'') {
        if (input[*pos] != '\0' && input[*pos] != '\n') {
            token.error = ERROR_MULTI_CHAR_LITERAL;
        } else {
            token.error = ERROR_UNTERMINATED_CHAR;
        }
        token.recovery = RECOVERY_TO_NEWLINE;
        skip_until(input, pos, "\n\'");
        return token;
    }
    
    advance_position(pos); // Skip closing quote
    token.lexeme[i] = '\0';
    return token;
}

/* Handle comments */
static Token handle_comment(const char *input, int *pos) {
    Token token = {TOKEN_COMMENT, "", current_line, current_column, ERROR_NONE, RECOVERY_NONE};
    int i = 0;
    
    // Skip '//'
    *pos += 2;
    current_column += 2;
    
    while (input[*pos] != '\0' && input[*pos] != '\n') {
        if (i < sizeof(token.lexeme) - 1) {
            token.lexeme[i++] = input[*pos];
        }
        advance_position(pos);
    }
    
    token.lexeme[i] = '\0';
    return token;
}

/* Handle numbers */
static Token handle_number(const char *input, int *pos) {
    Token token = {TOKEN_NUMBER, "", current_line, current_column, ERROR_NONE, RECOVERY_NONE};
    int i = 0;
    int decimal_count = 0;
    
    // Get digits before decimal
    while (isdigit(input[*pos])) {
        token.lexeme[i++] = input[*pos];
        advance_position(pos);
    }
    
    // Check for decimal points
    if (input[*pos] == '.') {
        token.lexeme[i++] = input[*pos];
        advance_position(pos);
        
        if (!isdigit(input[*pos])) {
            token.error = ERROR_INVALID_NUMBER;
            token.recovery = RECOVERY_TO_DELIMITER;
            skip_until(input, pos, ";,) \t\n");
            return token;
        }
        
        decimal_count++;
        while (isdigit(input[*pos]) || input[*pos] == '.') {
            if (input[*pos] == '.') {
                decimal_count++;
                if (decimal_count > 1) {
                    token.error = ERROR_INVALID_FLOAT;
                    token.recovery = RECOVERY_TO_DELIMITER;
                    skip_until(input, pos, ";,) \t\n");
                    return token;
                }
            }
            token.lexeme[i++] = input[*pos];
            advance_position(pos);
        }
    }
    
    token.lexeme[i] = '\0';
    if (decimal_count == 1) {
        token.type = TOKEN_FLOAT;
    }
    return token;
}

/* Get next token from input */
Token get_next_token(const char *input, int *pos) {
    Token token = {TOKEN_ERROR, "", current_line, current_column, ERROR_NONE, RECOVERY_NONE};
    char c;

    // Skip whitespace and track line numbers
    while ((c = input[*pos]) != '\0' && (c == ' ' || c == '\n' || c == '\t')) {
        if (c == '\n') {
            current_line++;
            current_column = 1;
            in_error_recovery = 0;  // Reset error recovery at new line
        } else {
            current_column++;
        }
        (*pos)++;
    }

    if (input[*pos] == '\0') {
        token.type = TOKEN_EOF;
        strcpy(token.lexeme, "EOF");
        return token;
    }

    // If in error recovery mode, skip until appropriate delimiter
    if (in_error_recovery) {
        token.type = TOKEN_SKIP;
        token.error = ERROR_RECOVERY_MODE;
        skip_until(input, pos, ";\n");
        in_error_recovery = 0;
        return token;
    }

    c = input[*pos];
    token.column = current_column;

    // TODO: Add comment handling here
    // Handle comments
    if (c == '/' && input[*pos + 1] == '/') {
        return handle_comment(input, pos);
    }

    // Handle character literals
    if (c == '\'') {
        return handle_char(input, pos);
    }

    // Handle numbers
    if (isdigit(c)) {
        return handle_number(input, pos);
    }

    // TODO: Add keyword and identifier handling here
    // Hint: You'll have to add support for keywords and identifiers, and then string literals
    if (isalpha(c) || c == '_') {
        int i = 0;
        do {
            token.lexeme[i++] = c;
            advance_position(pos);
            c = input[*pos];
        } while ((isalnum(c) || c == '_') && i < sizeof(token.lexeme) - 1);

        token.lexeme[i] = '\0';
        
        if (is_keyword(token.lexeme)) {
            token.type = TOKEN_KEYWORD;
            last_token_type = 'k';
        } else {
            token.type = TOKEN_IDENTIFIER;
            last_token_type = 'i';
        }
        
        return token;
    }

    // TODO: Add string literal handling here
    if (c == '"') {
        return handle_string(input, pos);
    }

    // Handle pointer operator (special case)
    if (c == '*' && (last_token_type == 'k' || last_token_type == 'i')) {
        token.type = TOKEN_POINTER;
        token.lexeme[0] = c;
        token.lexeme[1] = '\0';
        advance_position(pos);
        last_token_type = 'p';
        return token;
    }

    // Handle operators
    if (strchr("+-*/=<>!&|", c)) {
        if (last_token_type == 'o') {
            token.error = ERROR_CONSECUTIVE_OPERATORS;
            token.lexeme[0] = c;
            token.lexeme[1] = '\0';
            token.recovery = RECOVERY_TO_DELIMITER;
            advance_position(pos);
            in_error_recovery = 1;
            return token;
        }
        
        token.type = TOKEN_OPERATOR;
        token.lexeme[0] = c;
        
        // Check for two-character operators
        char next = input[*pos + 1];
        if ((c == '=' && next == '=') ||
            (c == '!' && next == '=') ||
            (c == '<' && next == '=') ||
            (c == '>' && next == '=') ||
            (c == '&' && next == '&') ||
            (c == '|' && next == '|')) {
            token.lexeme[1] = next;
            token.lexeme[2] = '\0';
            *pos += 2;
            current_column += 2;
        } else {
            token.lexeme[1] = '\0';
            advance_position(pos);
        }
        
        last_token_type = 'o';
        return token;
    }

    // TODO: Add delimiter handling here
    if (strchr("(){}[];,", c)) {
        token.type = TOKEN_DELIMITER;
        token.lexeme[0] = c;
        token.lexeme[1] = '\0';
        advance_position(pos);
        last_token_type = 'd';
        return token;
    }

    // Handle invalid characters
    token.error = ERROR_INVALID_CHAR;
    token.lexeme[0] = c;
    token.lexeme[1] = '\0';
    token.recovery = RECOVERY_TO_DELIMITER;
    advance_position(pos);
    in_error_recovery = 1;
    return token;
}

/* Process test files */
void process_test_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        printf("Error: Could not open file %s\n", filename);
        return;
    }
    
    // Reset lexer state for new file
    reset_lexer();
    
    char buffer[2048];
    size_t len = fread(buffer, 1, sizeof(buffer) - 1, file);
    buffer[len] = '\0';
    fclose(file);
    
    int position = 0;
    Token token;
    printf("\n==============================\n");
    printf("TESTING FILE: %s\n", filename);
    printf("==============================\n");
    printf("Input:\n%s\n\n", buffer);
    
    do {
        token = get_next_token(buffer, &position);
        print_token(token);
        
        if (token.recovery != RECOVERY_NONE) {
            in_error_recovery = 1;
        }
    } while (token.type != TOKEN_EOF);
    
    printf("\nEnd of %s\n", filename);
    printf("==============================\n");
}

// This is a complete lexer for Backwards C

int main() {
    process_test_file("test/input_valid.txt");
    process_test_file("test/input_invalid.txt");
    return 0;
}
