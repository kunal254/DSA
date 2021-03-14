#include <stdio.h>
#include <stdlib.h>

typedef struct stackNode
{
    int data;
    struct stackNode *next;
}stackNode;

stackNode *newNode(int data)
{
    stackNode *tempStack=(stackNode *)malloc(sizeof(stackNode));
    tempStack->data=data;
    tempStack->next=NULL;
    return tempStack;
}

int isEmpty(stackNode* top)
{
    return !top;
}

void push(stackNode **top,int data)
{
    stackNode *stack=newNode(data);
    stack->next=*top;
    *top=stack;
    printf("%d pushed to stack\n",data);
}
int pop(stackNode** top)
{
    if(isEmpty(*top))
        return -1;
    stackNode *temp=*top;
    *top=(*top)->next;
    int popped=temp->data;
    free(temp);

    return popped;
}

int peek(stackNode *top)
{
    if(isEmpty(top))
        return -1;
    return top->data;
}

int main()
{
    stackNode *top=NULL;
    push(&top,10);
    push(&top,20);
    push(&top,30);

    printf("%d popped from stack\n",pop(&top));
    printf("Top element is %d\n",peek(top));

    return 0;
}
