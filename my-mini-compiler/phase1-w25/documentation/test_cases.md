# Backwards C Test Cases and Expected Output

## 1. Test Cases

### 1.1 Valid Input

```c
// Valid Backwards C program example
tni niam(diov) {
    tni x = 42;
    rahc* gnirts = "Hello World!";
    taolf y = 3.14;
    
    fi (x > 0) {
        elihw (x > 0) {
            x = x - 1;
            fi (x == 25) {
                eunitnoc;
            }
            fi (x == 10) {
                kaerb;
            }
        }
    } esle {
        x = 0;
    }

    tcurts tniop {
        tni x;
        tni y;
    } p1;

    // Test different types
    elbuod z = 1.23456;
    rahc c = 'A';
    gnol gnol_mun = 123456789;
    trohs trohs_mun = 12345;

    nruter 0;
}
```

### 1.2 Invalid Input

```c
// Invalid Backwards C program with lexical errors
tni niam(diov) {
    // Invalid identifier with special character
    tni x@ = 42;

    // Unterminated string
    rahc* gnirts = "Hello World;

    // Invalid number format
    tni y = 042.1.2;

    // Invalid operators (consecutive)
    x === 5;

    // Invalid character in identifier
    tni my#var = 10;

    // Invalid escape sequence in string
    rahc* rts = "Hello\k World";

    // String that's too long (over token limit)
    rahc* gnol_gnirts = "This is a very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very very long string";

    nruter 0;
}
```

## 2. Expected outputs

### 2.1 Valid Input

```
==============================
TESTING FILE: test/input_valid.txt
==============================
Input:
// Valid backwards C program example
tni niam(diov) {
    tni x = 42;
    rahc* gnirts = "Hello World!";
    taolf y = 3.14;

    fi (x > 0) {
        elihw (x > 0) {
            x = x - 1;
            fi (x == 25) {
                eunitnoc;
            }
            fi (x == 10) {
                kaerb;
            }
        }
    } esle {
        x = 0;
    }

    tcurts tniop {
        tni x;
        tni y;
    } p1;

    // Test different types
    elbuod z = 1.23456;
    rahc c = 'A';
    gnol gnol_mun = 123456789;
    trohs trohs_mun = 12345;

    nruter 0;
}

Token: COMMENT | Lexeme: ' Valid backwards C program example' | Line: 1 | Column: 1
Token: KEYWORD | Lexeme: 'tni' | Line: 1 | Column: 1
Token: IDENTIFIER | Lexeme: 'niam' | Line: 2 | Column: 5
Token: DELIMITER | Lexeme: '(' | Line: 2 | Column: 9
Token: KEYWORD | Lexeme: 'diov' | Line: 2 | Column: 10
Token: DELIMITER | Lexeme: ')' | Line: 2 | Column: 14
Token: DELIMITER | Lexeme: '{' | Line: 2 | Column: 16
Token: KEYWORD | Lexeme: 'tni' | Line: 2 | Column: 5
Token: IDENTIFIER | Lexeme: 'x' | Line: 3 | Column: 9
Token: OPERATOR | Lexeme: '=' | Line: 3 | Column: 11
Token: NUMBER | Lexeme: '42' | Line: 3 | Column: 13
Token: DELIMITER | Lexeme: ';' | Line: 3 | Column: 15
Token: KEYWORD | Lexeme: 'rahc' | Line: 3 | Column: 5
Token: POINTER | Lexeme: '*' | Line: 4 | Column: 9
Token: IDENTIFIER | Lexeme: 'gnirts' | Line: 4 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 4 | Column: 18
Token: STRING | Lexeme: 'Hello World!' | Line: 4 | Column: 20
Token: DELIMITER | Lexeme: ';' | Line: 4 | Column: 34
Token: KEYWORD | Lexeme: 'taolf' | Line: 4 | Column: 5
Token: IDENTIFIER | Lexeme: 'y' | Line: 5 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 5 | Column: 13
Token: FLOAT | Lexeme: '3.14' | Line: 5 | Column: 15
Token: DELIMITER | Lexeme: ';' | Line: 5 | Column: 19
Token: KEYWORD | Lexeme: 'fi' | Line: 5 | Column: 5
Token: DELIMITER | Lexeme: '(' | Line: 7 | Column: 8
Token: IDENTIFIER | Lexeme: 'x' | Line: 7 | Column: 9
Token: OPERATOR | Lexeme: '>' | Line: 7 | Column: 11
Token: NUMBER | Lexeme: '0' | Line: 7 | Column: 13
Token: DELIMITER | Lexeme: ')' | Line: 7 | Column: 14
Token: DELIMITER | Lexeme: '{' | Line: 7 | Column: 16
Token: KEYWORD | Lexeme: 'elihw' | Line: 7 | Column: 9
Token: DELIMITER | Lexeme: '(' | Line: 8 | Column: 15
Token: IDENTIFIER | Lexeme: 'x' | Line: 8 | Column: 16
Token: OPERATOR | Lexeme: '>' | Line: 8 | Column: 18
Token: NUMBER | Lexeme: '0' | Line: 8 | Column: 20
Token: DELIMITER | Lexeme: ')' | Line: 8 | Column: 21
Token: DELIMITER | Lexeme: '{' | Line: 8 | Column: 23
Token: IDENTIFIER | Lexeme: 'x' | Line: 8 | Column: 13
Token: OPERATOR | Lexeme: '=' | Line: 9 | Column: 15
Token: IDENTIFIER | Lexeme: 'x' | Line: 9 | Column: 17
Token: OPERATOR | Lexeme: '-' | Line: 9 | Column: 19
Token: NUMBER | Lexeme: '1' | Line: 9 | Column: 21
Token: DELIMITER | Lexeme: ';' | Line: 9 | Column: 22
Token: KEYWORD | Lexeme: 'fi' | Line: 9 | Column: 13
Token: DELIMITER | Lexeme: '(' | Line: 10 | Column: 16
Token: IDENTIFIER | Lexeme: 'x' | Line: 10 | Column: 17
Token: OPERATOR | Lexeme: '==' | Line: 10 | Column: 19
Token: NUMBER | Lexeme: '25' | Line: 10 | Column: 22
Token: DELIMITER | Lexeme: ')' | Line: 10 | Column: 24
Token: DELIMITER | Lexeme: '{' | Line: 10 | Column: 26
Token: KEYWORD | Lexeme: 'eunitnoc' | Line: 10 | Column: 17
Token: DELIMITER | Lexeme: ';' | Line: 11 | Column: 25
Token: DELIMITER | Lexeme: '}' | Line: 11 | Column: 13
Token: KEYWORD | Lexeme: 'fi' | Line: 12 | Column: 13
Token: DELIMITER | Lexeme: '(' | Line: 13 | Column: 16
Token: IDENTIFIER | Lexeme: 'x' | Line: 13 | Column: 17
Token: OPERATOR | Lexeme: '==' | Line: 13 | Column: 19
Token: NUMBER | Lexeme: '10' | Line: 13 | Column: 22
Token: DELIMITER | Lexeme: ')' | Line: 13 | Column: 24
Token: DELIMITER | Lexeme: '{' | Line: 13 | Column: 26
Token: KEYWORD | Lexeme: 'kaerb' | Line: 13 | Column: 17
Token: DELIMITER | Lexeme: ';' | Line: 14 | Column: 22
Token: DELIMITER | Lexeme: '}' | Line: 14 | Column: 13
Token: DELIMITER | Lexeme: '}' | Line: 15 | Column: 9
Token: DELIMITER | Lexeme: '}' | Line: 16 | Column: 5
Token: KEYWORD | Lexeme: 'esle' | Line: 17 | Column: 7
Token: DELIMITER | Lexeme: '{' | Line: 17 | Column: 12
Token: IDENTIFIER | Lexeme: 'x' | Line: 17 | Column: 9
Token: OPERATOR | Lexeme: '=' | Line: 18 | Column: 11
Token: NUMBER | Lexeme: '0' | Line: 18 | Column: 13
Token: DELIMITER | Lexeme: ';' | Line: 18 | Column: 14
Token: DELIMITER | Lexeme: '}' | Line: 18 | Column: 5
Token: KEYWORD | Lexeme: 'tcurts' | Line: 19 | Column: 5
Token: IDENTIFIER | Lexeme: 'tniop' | Line: 21 | Column: 12
Token: DELIMITER | Lexeme: '{' | Line: 21 | Column: 18
Token: KEYWORD | Lexeme: 'tni' | Line: 21 | Column: 9
Token: IDENTIFIER | Lexeme: 'x' | Line: 22 | Column: 13
Token: DELIMITER | Lexeme: ';' | Line: 22 | Column: 14
Token: KEYWORD | Lexeme: 'tni' | Line: 22 | Column: 9
Token: IDENTIFIER | Lexeme: 'y' | Line: 23 | Column: 13
Token: DELIMITER | Lexeme: ';' | Line: 23 | Column: 14
Token: DELIMITER | Lexeme: '}' | Line: 23 | Column: 5
Token: IDENTIFIER | Lexeme: 'p1' | Line: 24 | Column: 7
Token: DELIMITER | Lexeme: ';' | Line: 24 | Column: 9
Token: COMMENT | Lexeme: ' Test different types' | Line: 26 | Column: 5
Token: KEYWORD | Lexeme: 'elbuod' | Line: 26 | Column: 5
Token: IDENTIFIER | Lexeme: 'z' | Line: 27 | Column: 12
Token: OPERATOR | Lexeme: '=' | Line: 27 | Column: 14
Token: FLOAT | Lexeme: '1.23456' | Line: 27 | Column: 16
Token: DELIMITER | Lexeme: ';' | Line: 27 | Column: 23
Token: KEYWORD | Lexeme: 'rahc' | Line: 27 | Column: 5
Token: IDENTIFIER | Lexeme: 'c' | Line: 28 | Column: 10
Token: OPERATOR | Lexeme: '=' | Line: 28 | Column: 12
Token: CHAR | Lexeme: 'A' | Line: 28 | Column: 14
Token: DELIMITER | Lexeme: ';' | Line: 28 | Column: 17
Token: KEYWORD | Lexeme: 'gnol' | Line: 28 | Column: 5
Token: IDENTIFIER | Lexeme: 'gnol_mun' | Line: 29 | Column: 10
Token: OPERATOR | Lexeme: '=' | Line: 29 | Column: 19
Token: NUMBER | Lexeme: '123456789' | Line: 29 | Column: 21
Token: DELIMITER | Lexeme: ';' | Line: 29 | Column: 30
Token: KEYWORD | Lexeme: 'trohs' | Line: 29 | Column: 5
Token: IDENTIFIER | Lexeme: 'trohs_mun' | Line: 30 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 30 | Column: 21
Token: NUMBER | Lexeme: '12345' | Line: 30 | Column: 23
Token: DELIMITER | Lexeme: ';' | Line: 30 | Column: 28
Token: KEYWORD | Lexeme: 'nruter' | Line: 30 | Column: 5
Token: NUMBER | Lexeme: '0' | Line: 32 | Column: 12
Token: DELIMITER | Lexeme: ';' | Line: 32 | Column: 13
Token: DELIMITER | Lexeme: '}' | Line: 32 | Column: 1
Token: EOF | Lexeme: 'EOF' | Line: 33 | Column: 2

End of test/input_valid.txt
==============================
```

### 2.2 Invalid Input

```
==============================
TESTING FILE: test/input_invalid.txt
==============================
Input:
// Invalid backwards C program with lexical errors
tni niam(diov) {
    // Invalid identifier with special character
    tni x@ = 42;

    // Unterminated string
    rahc* gnirts = "Hello World;

    // Invalid number format
    tni y = 042.1.2;

    // Invalid operators (consecutive)
    x === 5;

    // Invalid character in identifier
    tni my#var = 10;

    // Invalid escape sequence in string
    rahc* rts = "Hello\k World";

    // String that's too long (over token limit)
    rahc* gnol_gnirts = "This is a very very very very very very very very very very very very very very very very very very very 
very very very very very very very very very very very very very very very very very very very very very very very very very very 
very very very long string";

    nruter 0;
}

Token: COMMENT | Lexeme: ' Invalid backwards C program with lexical errors' | Line: 1 | Column: 1
Token: KEYWORD | Lexeme: 'tni' | Line: 1 | Column: 1
Token: IDENTIFIER | Lexeme: 'niam' | Line: 2 | Column: 5
Token: DELIMITER | Lexeme: '(' | Line: 2 | Column: 9
Token: KEYWORD | Lexeme: 'diov' | Line: 2 | Column: 10
Token: DELIMITER | Lexeme: ')' | Line: 2 | Column: 14
Token: DELIMITER | Lexeme: '{' | Line: 2 | Column: 16
Token: COMMENT | Lexeme: ' Invalid identifier with special character' | Line: 3 | Column: 5
Token: KEYWORD | Lexeme: 'tni' | Line: 3 | Column: 5
Token: IDENTIFIER | Lexeme: 'x' | Line: 4 | Column: 9
Lexical Error at line 4: Invalid character '@'
Token: DELIMITER | Lexeme: ';' | Line: 4 | Column: 16
Token: COMMENT | Lexeme: ' Unterminated string' | Line: 6 | Column: 5
Token: KEYWORD | Lexeme: 'rahc' | Line: 6 | Column: 5
Token: POINTER | Lexeme: '*' | Line: 7 | Column: 9
Token: IDENTIFIER | Lexeme: 'gnirts' | Line: 7 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 7 | Column: 18
Lexical Error at line 7: Unterminated string literal
Token: COMMENT | Lexeme: ' Invalid number format' | Line: 9 | Column: 5
Token: KEYWORD | Lexeme: 'tni' | Line: 9 | Column: 5
Token: IDENTIFIER | Lexeme: 'y' | Line: 10 | Column: 9
Token: OPERATOR | Lexeme: '=' | Line: 10 | Column: 11
Lexical Error at line 10: Invalid float format
Token: DELIMITER | Lexeme: ';' | Line: 10 | Column: 20
Token: COMMENT | Lexeme: ' Invalid operators (consecutive)' | Line: 12 | Column: 5
Token: IDENTIFIER | Lexeme: 'x' | Line: 12 | Column: 5
Token: OPERATOR | Lexeme: '==' | Line: 13 | Column: 7
Lexical Error at line 13: Consecutive operators not allowed
Token: DELIMITER | Lexeme: ';' | Line: 13 | Column: 12
Token: COMMENT | Lexeme: ' Invalid character in identifier' | Line: 15 | Column: 5
Token: KEYWORD | Lexeme: 'tni' | Line: 15 | Column: 5
Token: IDENTIFIER | Lexeme: 'my' | Line: 16 | Column: 9
Lexical Error at line 16: Invalid character '#'
Token: DELIMITER | Lexeme: ';' | Line: 16 | Column: 20
Token: COMMENT | Lexeme: ' Invalid escape sequence in string' | Line: 18 | Column: 5
Token: KEYWORD | Lexeme: 'rahc' | Line: 18 | Column: 5
Token: POINTER | Lexeme: '*' | Line: 19 | Column: 9
Token: IDENTIFIER | Lexeme: 'rts' | Line: 19 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 19 | Column: 15
Lexical Error at line 19: Invalid escape sequence
Token: DELIMITER | Lexeme: ';' | Line: 19 | Column: 32
Token: COMMENT | Lexeme: ' String that's too long (over token limit)' | Line: 21 | Column: 5
Token: KEYWORD | Lexeme: 'rahc' | Line: 21 | Column: 5
Token: POINTER | Lexeme: '*' | Line: 22 | Column: 9
Token: IDENTIFIER | Lexeme: 'gnol_gnirts' | Line: 22 | Column: 11
Token: OPERATOR | Lexeme: '=' | Line: 22 | Column: 23
Lexical Error at line 22: String literal too long
Token: DELIMITER | Lexeme: ';' | Line: 22 | Column: 288
Token: KEYWORD | Lexeme: 'nruter' | Line: 22 | Column: 5
Token: NUMBER | Lexeme: '0' | Line: 24 | Column: 12
Token: DELIMITER | Lexeme: ';' | Line: 24 | Column: 13
Token: DELIMITER | Lexeme: '}' | Line: 24 | Column: 1
Token: EOF | Lexeme: 'EOF' | Line: 25 | Column: 2

End of test/input_invalid.txt
==============================
```