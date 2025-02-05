# Backwards C Grammar Specification

## 1. Lexical Grammar

### 1.1 Basic Elements

```bnf
letter     ::= [a-zA-Z]
digit      ::= [0-9]
whitespace ::= ' ' | '\t' | '\n'
```

### 1.2 Identifiers

```bnf
identifier ::= (letter | '_') (letter | digit | '_')*
```

Examples:

- Valid: `counter`, `myVar_1`, `_temp`
- Invalid: `1var`, `my@var`, `if`

### 1.3 Keywords

All C keywords reversed:

```
Original -> Reversed
if       -> fi
int      -> tni
char     -> rahc
void     -> diov
return   -> nruter
for      -> rof
while    -> elihw
do       -> od
break    -> kaerb
continue -> eunitnoc
switch   -> hctiws
case     -> esac
...etc
```

### 1.4 Numbers

```bnf
number    ::= integer | float
integer   ::= digit+
float     ::= digit+ '.' digit+
```

Examples:

- Valid: `123`, `3.14`, `0.123`
- Invalid: `123.`, `.123`, `1.2.3`

### 1.5 Characters

```bnf
char_literal ::= '\'' char_char '\''
char_char    ::= escape_seq | any_char_except_quote_or_newline
escape_seq   ::= '\\' ('n' | 't' | 'r' | '0' | '\\' | '\'' | '\"')
```

Examples:

- Valid: `'a'`, `'\n'`, `'\t'`
- Invalid: `'ab'`, `''`, `'`

### 1.6 Strings

```bnf
string      ::= '"' string_char* '"'
string_char ::= escape_seq | any_char_except_quote_or_newline
```

Examples:

- Valid: `"Hello"`, `"Line\n"`, `"Tab\there"`
- Invalid: `"Unterminated`, `"Invalid\k"`

### 1.7 Operators

```bnf
operator    ::= arithmetic | relational | logical | assignment
arithmetic  ::= '+' | '-' | '*' | '/'
relational  ::= '==' | '!=' | '<' | '>' | '<=' | '>='
logical     ::= '&&' | '||' | '!'
assignment  ::= '='
```

### 1.8 Delimiters

```bnf
delimiter ::= '(' | ')' | '{' | '}' | '[' | ']' | ';' | ','
```

### 1.9 Comments

```bnf
comment ::= '//' any_char* newline
```

## 2. Token Patterns

### 2.1 Regular Expressions

```
IDENTIFIER: [a-zA-Z_][a-zA-Z0-9_]*
INTEGER:    [0-9]+
FLOAT:      [0-9]+\.[0-9]+
OPERATOR:   [+\-*/=<>!]=?|&&|\|\|
DELIMITER:  [()\[\]{},;]
COMMENT:    //.*\n
```

### 2.2 Precedence Rules

1. Keywords take precedence over identifiers
2. Longest match for operators
3. Comments consume to end of line
4. Whitespace is ignored except as separator

## 3. Complete Program Example

```c
// Valid backwards C program
tni niam(diov) {
    tni x = 42;
    rahc* gnirts = "Hello";

    fi (x > 0) {
        elihw (x > 0) {
            x = x - 1;
        }
    }

    nruter 0;
}
```

## 4. Token Sequence

Example token sequence for:

```c
tni x = 42;
```

```
TOKEN_KEYWORD    'tni'
TOKEN_IDENTIFIER 'x'
TOKEN_OPERATOR   '='
TOKEN_NUMBER     '42'
TOKEN_DELIMITER  ';'
```

## 5. Special Cases

### 5.1 Pointer Declarations

```c
rahc* rts;  // Recognized as: KEYWORD POINTER IDENTIFIER DELIMITER
tni*  p;    // Recognized as: KEYWORD POINTER IDENTIFIER DELIMITER
```

### 5.2 Compound Operators

```c
x == y  // Single token: OPERATOR "=="
x += 1  // Two tokens: OPERATOR "+" OPERATOR "="
```

### 5.3 String Escapes

```c
"Hello\n"  // '\n' recognized as newline escape
"Path\\File"  // '\\' recognized as backslash escape
```
