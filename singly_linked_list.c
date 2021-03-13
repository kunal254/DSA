#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *next;
}node;

node *create()
{
    node *h,*r,*q;
    char ch;

    h=(node*)malloc(sizeof(node));
    printf("\nEnter data ");
    scanf("%d",&h->data);
    h->next=NULL;
    q=h;

    printf("\nMore? (y/n)\n");
    ch=getch();
    while(ch == 'y')
    {
        r=(node*)malloc(sizeof(node));
        printf("\nEnter data ");
        scanf("%d",&r->data);
        r->next=NULL;

        q->next=r;
        q=r;

        printf("\nMore ?(y/n)\n");
        ch=getch();
    }

    return h;
}

void traverse(node *h)
{
    printf("\nLinked List----");
    while(h!=NULL)
    {
        printf("%5d",h->data);
        h=h->next;
    }
}

node *insFirst(node *h)
{
    node *n;
    n=(node *)malloc(sizeof(node));
    printf("\nEnter data for inserting at first  ");
    scanf("%d",&n->data);
    n->next=h;
    h=n;

    return h;
}

node *insLast(node *h)
{
    node *n,*z;
    n=(node *)malloc(sizeof(node));
    printf("\nEnter data for inserting at last  ");
    scanf("%d",&n->data);
    n->next=NULL;
    z=h;
    while(z->next != NULL)
    z=z->next;
    z->next=n;

    return h;

}

node *insPosBefore(node *h)
{
    int pos,c=0;
    node *n,*z;
    n=(node *)malloc(sizeof(node));
    printf("\n Enter data IPB!! ");
    scanf("%d",&n->data);
    n->next=NULL;
    printf("\n Enter position ");
    scanf("%d",&pos);

    z=h;
    while(z!=NULL)
    {
        c++;
        if(c==pos-1)
        {
            n->next=z->next;
            z->next=n;
            break;
        }
        z=z->next;
    }

    return h;
}

node *insPosAfter(node *h)
{
    int pos,c=0;
    node *n,*z;
    n=(node *)malloc(sizeof(node));
    printf("\n Enter data IPA!! ");
    scanf("%d",&n->data);
    n->next=NULL;
    printf("\n Enter position ");
    scanf("%d",&pos);

    z=h;
    while(z!=NULL)
    {
        c++;
        if(c==pos)
        {
            n->next=z->next;
            z->next=n;
            break;
        }
        z=z->next;
    }

    return h;
}
node *delFirst(node *h)
{
    node *t;
    t=h;
    h=h->next;
    free(t);

    return h;
}
void *delLast(node *h)
{
    node *t,*z;
    z=h;
    while(z->next->next!=NULL)
    z=z->next;
    t=z->next;
    z->next=NULL;
    free(t);

   // return h;
}

node *delPos(node *h)
{
    node *t,*z;
    int c=0,pos;
    printf("\n Enter position ");
    scanf("%d",&pos);
    z=h;
    while(z!=NULL)
    {
        c++;
        if(c==pos-1)
        {
            t=z->next;
            z->next=t->next;
            free(t);
            break;
        }
        z=z->next;
    }
    return h;
}

node *rev(node *h)
{
    node *a,*b,*c;
    a=h;
    b=a->next;
    c=b->next;

    while(b!=NULL)
    {
        b->next=a;
        a=b;
        b=c;
        if(c!=NULL)
        c=c->next;
    }
    h->next=NULL;
    h=a;

    return h;
}

node *concat(node *a, node *b)
{
    node *z;
    z=a;
    while(z->next!=NULL)
    z=z->next;
    z->next=b;
    return a;
}


int main()
{
    node *start;
    start=create();
    traverse(start);
    start=rev(start);
    traverse(start);f
    return 0;
}
