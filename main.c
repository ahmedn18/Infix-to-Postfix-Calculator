// 8963 Mazen Tarek Adel Group 4 section 2
// 9168 Ahmed Nader Adly Group 1 section 2
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_TOKEN_LENGTH 50
typedef struct Node {
    float data;
    struct Node *next;
} Node;

typedef struct {
    Node *top;
} Stack;

Stack *initialize() {
    Stack *s = malloc(sizeof(Stack));
    s->top = NULL;

    return s;
}

Node *NewNode(float data) {
    Node *n = malloc(sizeof(Node));
    n->next = NULL;
    n->data = data;
    return n;
}

int isEmpty(Stack *s) {
    return s->top == NULL;
}

float peek(Stack *s) {
    if (!isEmpty(s))
        return s->top->data;
    else
        return -1;
}

float pop(Stack *s) {
    if (!isEmpty(s)) {
        Node *temp = s->top;
        s->top = s->top->next;
        float popped = temp->data;
        free(temp);
        return popped;
    } else {
        printf("stack is empty");
        return -1;
    }
}

void push(Stack *s, float value) {
    Node *n = NewNode(value);
    if (isEmpty(s)) {
        s->top = n;
    } else {
        n->next = s->top;
        s->top = n;
    }
}

void destructStack(Stack *s) {
    while (!isEmpty(s)) {
        pop(s);
    }
    free(s);
}

int precedence_of_operator(char operator) {
    if (operator == '(')
        return 0;
    if (operator == '+' || operator == '-')
        return 1;
    if (operator == '*' || operator == '/' || operator == '%')
        return 2;
    if (operator == '^')
        return 3;
    return 0;
}

char *infixToPostfix(char *infix) {
    Stack *s = initialize();
    char *postfix_arr = malloc(strlen(infix) + 1);
    int pos_in_postfix_arr = 0;
    char *token = strtok(infix, " ");
    while (token != NULL) {
        if (isdigit(token[strlen(token) - 1])) { // as negative is token[0] in negative nums
            strcpy(postfix_arr + pos_in_postfix_arr, token);
            pos_in_postfix_arr += strlen(token);
            postfix_arr[pos_in_postfix_arr++] = ' ';
        } else if (token[0] == '(') {
            push(s, (float) '(');
        } else if (token[0] == ')') {
            while (!isEmpty(s) && peek(s) != (float) '(') {
                postfix_arr[pos_in_postfix_arr++] = ((char) pop(s));
                postfix_arr[pos_in_postfix_arr++] = ' ';
            }
            pop(s); // Discard '('
        } else {
            while (!isEmpty(s) && precedence_of_operator(peek(s)) >= precedence_of_operator(token[0])) {
                postfix_arr[pos_in_postfix_arr++] = ((char) pop(s));
                postfix_arr[pos_in_postfix_arr++] = ' ';
            }
            push(s, token[0]);
        }
        token = strtok(NULL, " ");
    }
    while (!isEmpty(s)) {
        postfix_arr[pos_in_postfix_arr++] = (char) pop(s);
        postfix_arr[pos_in_postfix_arr++] = ' ';
    }
    postfix_arr[pos_in_postfix_arr - 1] = '\0';
    destructStack(s);
    return postfix_arr;
}

float evaluatePostfix(char *postfixExpression) {
    Stack *s = initialize();
    float sum = 0;
    //    printf("postfix expression is :%s",postfixExpression);
    char *token = strtok(postfixExpression, " ");
    while (token != NULL) {
        if (isdigit(token[strlen(token) - 1])) {
            push(s, atof(token)); // ascii to float func , if digit then push to stack
        } else if (token[0] == '+') {
            sum = pop(s) + pop(s);
            push(s, sum);
        } else if (token[0] == '-') {
            float operand2 = pop(s);
            float operand1 = pop(s);
            sum = operand1 - operand2;
            push(s, sum);
        } else if (token[0] == '*') {
            sum = pop(s) * pop(s);
            push(s, sum);
        } else if (token[0] == '/') {
            float operand2 = pop(s);
            float operand1 = pop(s);
            sum = operand1 / operand2;
            push(s, sum);
        } else if (token[0] == '^') {
            float operand2 = pop(s);
            float operand1 = pop(s);
            sum = pow(operand1, operand2);
            push(s, sum);
        }
        token = strtok(NULL, " ");
    }
    sum = pop(s);
    destructStack(s);
    return sum;
}

int menu() {
    int choice = -1;
    char input[50];

    while (choice != 1 && choice != 2) {
        printf("Enter a choice from [1-2]: \n");
        printf("1) Calculate expression\n");
        printf("2) Exit\n");

        fgets(input, sizeof(input), stdin);
        if (sscanf(input, "%d", &choice) !=
            1) // func used to attempt to parse input into int to check it's not a letter to avoid infinite loop on entering letters
        {
            printf("Incorrect input, please enter a valid integer.\n");
            continue;
        }

        if (choice != 1 && choice != 2) {
            printf("Incorrect input, please enter 1 or 2.\n");
        }
    }

    return choice;
}


int isMatchingPair(char ch1, char ch2) {
    if (ch1 == '(' && ch2 == ')')
        return 0;
    else if (ch1 == '{' && ch2 == '}')
        return 0;
    else if (ch1 == '[' && ch2 == ']')
        return 0;
    else
        return -1;
}

int isBalancedExpression(char *exp) {
    int i = 0;
    Stack *s = initialize();

    while (exp[i] != '\0') {
        if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[')
            push(s, exp[i]);
        if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') {
            if (isEmpty(s) || (!isMatchingPair((char) pop(s), exp[i])))
                return 0;
        }
        i++;
    }

    // If something is left in the stack then the expression is unbalanced (trivial)
    if (isEmpty(s))
        return 1; // balanced
    else
        return 0; // not balanced
}


void calculator() {
    int choice;
    do {
        choice = menu();
        if (choice == 1) {
            char input_expression[MAX_TOKEN_LENGTH];
            printf("Input (Infix): "); // with spaces between everything
            fgets(input_expression, sizeof(input_expression), stdin);
            if (isBalancedExpression(input_expression)) {
                input_expression[strcspn(input_expression, "\n")] = 0;
                char *output_expression = infixToPostfix(input_expression);
                printf("Output (Postfix): %s\n", output_expression);
                float value_of_expression = evaluatePostfix(output_expression);
                printf("\n");
                printf("Value : %.2f\n", value_of_expression);
            } else
                printf("Invalid Expression ... Try again\n");
        } else
            break;
    } while (choice == 1);
}

int main() {
    calculator();
    return 0;
}