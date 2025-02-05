# Backwards C Error Codes and Error Handling

## 1. Error Type Enumeration

### ERROR_NONE (0)

- Normal token processing state
- No error condition present

```c
Token token = {TOKEN_NUMBER, "42", 1, 1, ERROR_NONE};
```

### ERROR_INVALID_CHAR (1)

- Unexpected character in input stream
- Example: Special characters in identifiers

```c
tni my@var = 10;  // '@' triggers ERROR_INVALID_CHAR
x#y = 20;         // '#' also triggers ERROR_INVALID_CHAR
```

### ERROR_INVALID_NUMBER (2)

- Malformed numeric literal
- Examples:

```c
123.;    // Missing decimal digits
.123     // Missing integer part
```

### ERROR_CONSECUTIVE_OPERATORS (3)

- Multiple operators appearing sequentially
- Examples:

```c
x +* y;   // Consecutive operators +*
x === y;  // Extra = after ==
```

### ERROR_UNTERMINATED_STRING (4)

- String literal missing closing quote
- Examples:

```c
"Hello    // Missing closing quote
"Multi
line"     // Newline in string
```

### ERROR_UNTERMINATED_CHAR (5)

- Character literal missing closing quote
- Examples:

```c
'a       // Missing closing quote
'\       // Incomplete escape sequence
```

### ERROR_INVALID_IDENTIFIER (6)

- Malformed identifier
- Examples:

```c
123abc    // Starts with number
_$name    // Contains invalid character
```

### ERROR_STRING_TOO_LONG (7)

- String literal exceeds maximum length
- Example: String longer than 100 characters

```c
"This string is way too long and continues beyond the allowed limit..."
```

### ERROR_INVALID_ESCAPE_SEQUENCE (8)

- Invalid escape sequence in string/char
- Examples:

```c
"Hello\k"   // \k is invalid
'\z'        // \z is invalid
```

### ERROR_EMPTY_CHAR_LITERAL (9)

- Empty character literal
- Example:

```c
''          // Nothing between quotes
```

### ERROR_MULTI_CHAR_LITERAL (10)

- Multiple characters in char literal
- Example:

```c
'ab'        // More than one character
```

### ERROR_INVALID_FLOAT (11)

- Malformed floating-point number
- Examples:

```c
123.456.789  // Multiple decimal points
42.          // Missing decimal part
```

## 2. Recovery Modes

### RECOVERY_NONE (0)

- Default state
- No recovery needed
- Continue normal processing

### RECOVERY_TO_SEMICOLON (1)

- Skip until next semicolon
- Used for statement-level errors

```c
tni x@ = 42;  // Skip to ; after invalid char
```

### RECOVERY_TO_NEWLINE (2)

- Skip until next newline
- Used for string/char errors

```c
"unterminated
next_line    // Skip to next line
```

### RECOVERY_TO_DELIMITER (3)

- Skip to next delimiter character
- Used for number/identifier errors

```c
123.45.67;   // Skip to ; after invalid float
```

## 3. Implementation Details

### 3.1 Error Token Structure

```c
typedef struct {
    TokenType type;        // Token type
    char lexeme[100];      // Actual text
    int line;              // Line number
    int column;            // Column number
    ErrorType error;       // Error type
    RecoveryMode recovery; // Recovery strategy
} Token;
```

### 3.2 Error Recovery Process

1. Error Detection

```c
if (!isalnum(c) && c != '_') {
    token.error = ERROR_INVALID_CHAR;
    token.recovery = RECOVERY_TO_DELIMITER;
}
```

2. Error Reporting

```c
if (token.error != ERROR_NONE) {
    print_error(token.error, token.line, token.lexeme);
}
```

3. Recovery Strategy

```c
if (token.recovery != RECOVERY_NONE) {
    switch (token.recovery) {
        case RECOVERY_TO_SEMICOLON:
            skip_until(input, pos, ";");
            break;
        // ... other cases
    }
}
```

## 4. Error Prevention Strategies

### 4.1 Buffer Overflow Prevention

```c
if (i >= sizeof(token.lexeme) - 1) {
    token.error = ERROR_STRING_TOO_LONG;
    return token;
}
```

### 4.2 State Validation

```c
if (last_token_type == 'o') {
    token.error = ERROR_CONSECUTIVE_OPERATORS;
    return token;
}
```

### 4.3 Input Validation

```c
if (!isalpha(c) && c != '_') {
    token.error = ERROR_INVALID_IDENTIFIER;
    return token;
}
```

## 5. Best Practices

### 5.1 Error Reporting

- Include line and column numbers
- Provide context in error messages
- Show invalid lexeme
- Suggest possible fixes

### 5.2 Recovery Strategies

- Choose appropriate recovery mode
- Prevent error cascading
- Maintain lexer state
- Continue processing where possible

### 5.3 Error Prevention

- Validate input early
- Check buffer boundaries
- Verify state transitions
- Maintain context information

## 6. Common Error Patterns

### 6.1 Syntax Errors

```c
tni x@ = 42;    // Invalid character in identifier
fi (x == y      // Missing closing parenthesis
"Hello          // Unterminated string
```

### 6.2 Recovery Examples

```c
x +* y;         // Recover at semicolon
123.45.67       // Recover at delimiter
'ab' + 'cd'     // Recover at operator
```

### 6.3 Error Cascading Prevention

```c
if (in_error_recovery) {
    skip_until(input, pos, ";\n");
    return TOKEN_SKIP;
}
```
