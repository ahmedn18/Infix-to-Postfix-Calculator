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

## Follow the on-screen instructions:

-  Calculate expression: Enter 1 to input an infix expression and get the postfix conversion and evaluation result.
- Exit: Enter 2 to exit the program.


## Code Explanation

### Stack Operations:

- `initialize()`: Initializes a new stack.
- `NewNode(float data)`: Creates a new node for the stack.
- `isEmpty(Stack *s)`: Checks if the stack is empty.
- `peek(Stack *s)`: Returns the top value of the stack without removing it.
- `pop(Stack *s)`: Removes and returns the top value of the stack.
- `push(Stack *s, float value)`: Pushes a new value onto the stack.
- `destructStack(Stack *s)`: Frees all nodes in the stack and the stack itself.

### Infix to Postfix Conversion:

- `infixToPostfix(char *infix)`: Converts an infix expression to postfix notation using the Shunting-yard algorithm.

### Postfix Evaluation:

- `evaluatePostfix(char *postfixExpression)`: Evaluates a postfix expression.

### Expression Validation:

- `isMatchingPair(char character0, char character2)`: Checks if two characters are matching parentheses.
- `isBalancedExpression(char *exp)`: Checks if the expression has balanced parentheses.

### Menu and Calculator Functions:

- `menu()`: Displays a menu and gets user choice.
- `calculator()`: Manages user interaction, processes expressions, and displays results.

## Example

Input:

```plaintext
( 3 + 4 ) * 5 - 6 / 2
```

Output:

```plaintext
Output (Postfix): 3 4 + 5 * 6 2 / - 
Value : 19.00
```

## License

This project is licensed under the MIT License - see the LICENSE file for details.

## Contact

For any questions or issues, please contact es-ahmed.nader2027@alexu.edu.eg.

