#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;
int is_Full()
{
    if (top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_Empty()
{
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(int data)
{
    if (is_Full())
    {
        printf("Stack Overflow\n");
        return;
    }
    else
    {
        top= top+1;
        stack_arr[top] = data;
    }
}
int pop()
{
    int value;
    if (is_Empty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        value = stack_arr[top];
        top=top-1;
        return value;
    }
}
int peek()
{
    if (is_Empty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack_arr[top];
}

void print()
{
    int i;
    if (top == -1)
    {
        printf("Stack underflow\n");
        return;
    }
    for (i = top; i >= 0; i--)
    
        printf("%d ", stack_arr[i]);
    
    printf("\n");
}

int main()
{
    int choice, data;
    while (1)
    {
        printf("\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Print the top element\n");
        printf("4. Print all the elements of the stack\n");
        printf("5. Quit\n");
        printf("Please Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be pushed: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            data = pop();
            printf("Deleted element is %d\n", data);
            break;
        case 3:
            printf("The top most element is %d", peek());
            break;
        case 4:
            print();
            break;
        case 5:
            exit(1);
        default:
            printf("Wrong choice");
        }
    }
    return 0;
}