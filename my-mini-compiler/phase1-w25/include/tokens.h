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
    TOKEN_OPERATOR,   // e.g., "+", "-"
    TOKEN_LITERAL,    // e.g., "Hello", "World", "Reverse C" 
    TOKEN_PUNCTUATOR, // e.g., , , {, }, [, ], (, )
    TOKEN_KEYWORD,    // e.g., "fi", "tni", "esle", "rof", "elihw"  
    TOKEN_ERROR
} TokenType;

/* Error types for lexical analysis
 * TODO: Add more error types as needed for your language - as much as you like !!
 */
typedef enum {
    ERROR_NONE,
    ERROR_INVALID_CHAR,
    ERROR_INVALID_NUMBER,
    ERROR_INVALID_KEYWORD, 
    ERROR_INVALID_PUNCTUATOR,
    ERROR_INVALID_STRING_LITERAL, 
    ERROR_CONSECUTIVE_OPERATORS
} ErrorType;

/* Token structure to store token information
 * TODO: Add more fields if needed for your implementation
 * Hint: You might want to consider adding line and column tracking if you want to debug your lexer properly.
 * Don't forget to update the token fields in lexer.c as well
 */
typedef struct {
    TokenType type;
    char lexeme[100];   // Actual text of the token
    int line;           // Line number in source file
    int column;         // Track the Column Number in Source File
    ErrorType error;    // Error type if any
} Token;

#endif /* TOKENS_H */
