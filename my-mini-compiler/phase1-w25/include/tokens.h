//
// Created by Youssef
//

/* tokens.h */
#ifndef TOKENS_H
#define TOKENS_H

/* Token types that need to be recognized by the lexer
 * TODO: Add more token types as per requirements:
 * - Keywords or reserved words (if, repeat, until)
 * - Identifiers
 * - String literals
 * - More operators
 * - Delimiters
 */
typedef enum {
    TOKEN_EOF,
    TOKEN_NUMBER,     // e.g., "123", "456"
    TOKEN_FLOAT,      // e.g., "1.23", "0.123"
    TOKEN_OPERATOR,   // e.g., "+", "-", "*", "/"
    TOKEN_ERROR,      // Error token
    TOKEN_IDENTIFIER, // Variable names
    TOKEN_KEYWORD,    // Reserved words
    TOKEN_STRING,     // String literals
    TOKEN_CHAR,       // Character literals
    TOKEN_DELIMITER,  // Separators and delimiters
    TOKEN_COMMENT,    // Comments
    TOKEN_POINTER,    // Pointer operator *
    TOKEN_SKIP        // Token to indicate skipping during error recovery
} TokenType;

/* List of reversed C keywords */
#define NUM_KEYWORDS 32
static const char* keywords[] = {
    "fi",       // if
    "tni",      // int
    "rahc",     // char
    "diov",     // void
    "nruter",   // return
    "rof",      // for
    "elihw",    // while
    "od",       // do
    "kaerb",    // break
    "eunitnoc", // continue
    "hctiws",   // switch
    "esac",     // case
    "tluafed",  // default
    "otog",     // goto
    "foezis",   // sizeof
    "citats",   // static
    "nretxe",   // extern
    "tsnoc",    // const
    "elitalov", // volatile
    "tcurts",   // struct
    "noinu",    // union
    "mune",     // enum
    "fedepyt",  // typedef
    "dengisnu", // unsigned
    "dengis",   // signed
    "trohs",    // short
    "gnol",     // long
    "taolf",    // float
    "elbuod",   // double
    "esle",     // else
    "diov*",    // void*
    "tni*"      // int*
};

/* Error types for lexical analysis
 * TODO: Add more error types as needed for your language - as much as you like !!
 */
typedef enum {
    ERROR_NONE,
    ERROR_INVALID_CHAR,
    ERROR_INVALID_NUMBER,
    ERROR_CONSECUTIVE_OPERATORS,
    ERROR_UNTERMINATED_STRING,
    ERROR_UNTERMINATED_CHAR,
    ERROR_INVALID_IDENTIFIER,
    ERROR_STRING_TOO_LONG,
    ERROR_INVALID_ESCAPE_SEQUENCE,
    ERROR_EMPTY_CHAR_LITERAL,
    ERROR_MULTI_CHAR_LITERAL,
    ERROR_INVALID_FLOAT,
    ERROR_RECOVERY_MODE
} ErrorType;

/* Error recovery modes */
typedef enum {
    RECOVERY_NONE,
    RECOVERY_TO_SEMICOLON,    // Recover until next semicolon
    RECOVERY_TO_NEWLINE,      // Recover until next newline
    RECOVERY_TO_DELIMITER     // Recover until next delimiter
} RecoveryMode;

/* Token structure to store token information
 * TODO: Add more fields if needed for your implementation
 * Hint: You might want to consider adding line and column tracking if you want to debug your lexer properly.
 * Don't forget to update the token fields in lexer.c as well
 */
typedef struct {
    TokenType type;
    char lexeme[100];      // Actual text of the token
    int line;              // Line number in source file
    int column;            // Column number in source file
    ErrorType error;       // Error type if any
    RecoveryMode recovery; // Recovery mode if error
} Token;

#endif /* TOKENS_H */
