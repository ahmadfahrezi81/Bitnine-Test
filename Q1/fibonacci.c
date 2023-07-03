#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{
    ADD,
    SUB,
    MUL,
    DIV,
    VALUE
} TypeTag;

typedef struct Node
{
    TypeTag type;
    union
    {
        int value;
        struct
        {
            struct Node *left;
            struct Node *right;
        } operands;
    };
} Node;

Node *makeFunc(TypeTag type)
{
    Node *node = malloc(sizeof(Node));
    node->type = type;
    node->operands.left = NULL;
    node->operands.right = NULL;
    return node;
}

Node *makeValue(int value)
{
    Node *node = malloc(sizeof(Node));
    node->type = VALUE;
    node->value = value;
    return node;
}

int calcValue(Node *node)
{
    if (node->type == VALUE)
    {
        return node->value;
    }
    else
    {
        return -1;
    }
}

int calcAdd(Node *node)
{
    return calcValue(node->operands.left) + calcValue(node->operands.right);
}

int calcSub(Node *node)
{
    return calcValue(node->operands.left) - calcValue(node->operands.right);
}

int calcMul(Node *node)
{
    return calcValue(node->operands.left) * calcValue(node->operands.right);
}

int calcDiv(Node *node)
{
    return calcValue(node->operands.left) / calcValue(node->operands.right);
}

int calcFibonacci(Node *node)
{
    if (node->type == VALUE)
    {
        return node->value;
    }
    else if (node->type == SUB)
    {
        Node *left = node->operands.left;
        Node *right = node->operands.right;
        return calcFibonacci(left) - calcFibonacci(right);
    }
    else
    {
        printf("Invalid operation: not a Fibonacci sequence\\n");
        exit(1);
    }
}

void calc(Node *node)
{
    int result = 0;
    switch (node->type)
    {
    case ADD:
        result = calcAdd(node);
        printf("add : %d\n", result);
        break;
    case SUB:
        result = calcSub(node);
        printf("sub : %d\n", result);
        break;
    case MUL:
        result = calcMul(node);
        printf("mul : %d\n", result);
        break;
    case DIV:
        result = calcDiv(node);
        printf("div : %d\n", result);
        break;
    default:
        if (node->type == SUB)
        {
            result = calcFibonacci(node);
            printf("fibonacci : %d\n", result);
        }
        else
        {
            printf("Invalid operation\n");
            exit(1);
        }
        break;
    }
}

int main()
{
    Node *add = makeFunc(ADD);
    add->operands.left = makeValue(10);
    add->operands.right = makeValue(6);

    Node *mul = makeFunc(MUL);
    mul->operands.left = makeValue(5);
    mul->operands.right = makeValue(4);

    Node *sub = makeFunc(SUB);
    sub->operands.left = mul;
    sub->operands.right = add;

    Node *fibo = makeFunc(SUB);
    fibo->operands.left = sub;
    fibo->operands.right = makeValue(0);

    calc(add);
    calc(mul);
    calc(sub);
    calc(fibo);

    free(add);
    free(mul);
    free(sub);
    free(fibo);

    return 0;
}