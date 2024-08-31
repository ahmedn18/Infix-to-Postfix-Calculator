# Infix Expression Calculator

This project is a command-line tool that evaluates arithmetic expressions written in infix notation. It supports basic arithmetic operations such as addition, subtraction, multiplication, division, and exponentiation. The project also converts infix expressions to postfix (Reverse Polish Notation) before evaluating them.

## Features
- **Infix to Postfix Conversion**: The program converts infix expressions to postfix notation for easier evaluation.
- **Postfix Evaluation**: The program evaluates the postfix expression to compute the result.
- **Balanced Expression Check**: The program checks if the input infix expression has balanced parentheses before processing it.
- **Supported Operators**:
  - Addition (`+`)
  - Subtraction (`-`)
  - Multiplication (`*`)
  - Division (`/`)
  - Modulus (`%`)
  - Exponentiation (`^`)
- **Parentheses**: The program supports nested parentheses for grouping operations.

## Getting Started

### Prerequisites
- A C compiler such as GCC.

### Compilation
To compile the program, navigate to the project directory and use the following command:

```bash
gcc -o infix_calculator main.c -lm
```
The '-lm' flag is required to link the math library for exponentiation

## Running the Program

After compilation, you can run the program using the following command:

```bash
./infix_calculator
```


