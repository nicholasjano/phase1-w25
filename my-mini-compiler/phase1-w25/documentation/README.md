# Backwards C Lexical Analyzer

## Overview

A lexical analyzer for "Backwards C". In this variant, all they keywords are in reverse.

## Key Features

1. Token Recognition

   - Reversed C keywords (e.g., 'if' -> 'fi')
   - Identifiers (variable names, function names)
   - Numbers (integers and floating-point)
   - String literals with escape sequences
   - Character literals
   - Operators (single and compound)
   - Comments (single-line)
   - Delimiters and special symbols

2. Error Handling

   - Detailed error messages with line/column information
   - Smart error recovery mechanisms
   - Continuation after errors
   - Multiple error types

3. Implementation Features
   - Line/column tracking for precise error reporting
   - Buffer management for string literals
   - Smart state tracking
   - Efficient error recovery strategies

## Design Decisions

### 1. Token Structure

- Fixed-size lexeme buffer (100 chars)
- Integrated error information
- Position tracking in token
- Recovery mode indication

### 2. Error Recovery Strategy

- Skip-to-delimiter recovery
- State reset on newlines
- Error cascading prevention
- Context-aware recovery modes

### 3. Memory Management

- Static buffer sizing
- No dynamic allocation
- Fixed-size token structure
- Efficient string handling

### 4. Performance Considerations

- Single-pass tokenization
- Minimal backtracking
- Efficient keyword lookup
- Optimized string handling

### 5. State Management

- Line/column counters
- Last token type memory
- Error recovery flags
- Token context awareness

See grammar.md for detailed language specifications and error_codes.md for complete error handling documentation.
