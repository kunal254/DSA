#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

typedef struct node
{
    int data;
    struct node *next,*prev;
}node;

node *create()
{
    node *h,*r,*q;
    char ch;

    h=(node*)malloc(sizeof(node));
    printf("\nEnter data ");
    scanf("%d",&h->data);
    h->next=NULL;

        h->prev=NULL;

    q=h;

    printf("\nMore? (y/n)\n");
    ch=getch();
    while(ch == 'y')
    {
        r=(node*)malloc(sizeof(node));
        printf("\nEnter data ");
        scanf("%d",&r->data);
        r->next=NULL;
            r->prev=q;
        q->next=r;
        q=r;

        printf("\nMore ?(y/n)\n");
        ch=getch();
    }

    return h;
}

void traverse(node *h)
{
    printf("\nLinked List head to tail----");
    while(h->next!=NULL)
    {
        printf("%5d",h->data);
        h=h->next;
    }
        printf("%5d",h->data);
    printf("\nLinked List from tail to head----");
    while(h!=NULL)
    {
        printf("%5d",h->data);
        h=h->prev;
    }
}

node *insFirst(node *h)
{
    node *n;
    n=(node *)malloc(sizeof(node));
    printf("\nEnter data for inserting at first  ");
    scanf("%d",&n->data);
    n->next=h;
        n->prev=NULL;
        h->prev=n;
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
        n->prev=z;

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
                n->prev=z;
                n->next->prev=n;
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
                n->prev=z;
                n->next->prev=n;
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
    h->prev=NULL;
    free(t);

    return h;
}
node *delLast(node *h)
{
    node *t,*z;
    z=h;
    while(z->next->next!=NULL)
    z=z->next;

    t=z->next;
    z->next=NULL;
    free(t);

    return h;
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
            t->next->prev=z;
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

    h->prev=b;
    while(b!=NULL)
    {
        b->next=a;
        b->prev=c;
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
    b->prev=z;
    return a;
}


int main()
{
    node *a,*b;
    a=create();
    traverse(a);
    b=create();
    traverse(b);
    a=concat(a,b);
    traverse(a);
    return 0;
}
