#include <stdio.h>
#include <stdlib.h>
 
struct node
{
    int data;
    struct node *link;
}*top = NULL;
 
#define MAX 5

void push();
void pop();
void empty();
void stack_full();
void stack_count();
int st_count();
void destroy();
void print_top();
 
void main()
{
    int choice;
 
    while (1)
    {
        printf("\n1. push an element \n");
        printf("2. pop an element \n");
        printf("3. check if stack is empty \n");
        printf("4. check if stack is full \n");
        printf("5. count/display elements present in stack \n");
        printf("6. empty and destroy stack \n");
        printf("7. Print top of the stack \n");
        printf("8. exit \n");
        printf("Enter your choice \n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:    
            push();
            break;         
        case 2:    
            pop();
            break;         
        case 3:    
            empty();
            break;         
        case 4:    
            stack_full();
            break;         
        case 5:    
            stack_count();
            break;         
        case 6:    
            destroy();
            break;         
        case 7:    
            print_top();
            break;
        case 8:    
            exit(0);
        default:
            printf("wrong choice\n");         
        }
    }
}

void push()
{
    int value , count;
    struct node *temp;
    temp = (struct node*)malloc(sizeof(struct node));
 
    count = st_count();
    if (count <= MAX - 1)
    {
        printf("\nEnter Your Value :\n");
        scanf("%d",&value);
        temp->data = value;
        temp->link = top;
        top = temp;
    }
    else
        printf("Stack Is Full!\n");
}

void pop()
{
    struct node *temp;
    if (top == NULL)
        printf("Stack Is Empty\n");
    else
    {
        temp = top;
        printf("Value Popped Is %d \n",temp->data);
        top = top->link;
        free(temp);
    }
}

void empty()
{
    if (top == NULL)
        printf("Stack Is Empty!\n");
    else
        printf("Stack Is NOT Empty \n");
}

void stack_full()
{
    int count;
 
    count = st_count();
    if (count == MAX)
    {
        printf("Stack Is Full\n");
    }
    else
        printf("Stack Is NOT Full \n");
}

void stack_count()
{
    int count = 0;
    struct node *temp;
 
    temp = top;
    while (temp != NULL)
    {
        printf(" %d\n",temp->data);
        temp = temp->link;
        count++;
    }
    printf("Size of Stack = %d \n",count);
}
 
int st_count()
{
    int count = 0;
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        temp = temp->link;
        count++;
    }
    return count;
}

void destroy()
{
    struct node *temp;
    temp = top;
    while (temp != NULL)
    {
        pop();
        temp = temp->link;
    }
    printf("Stack Destroyed\n");
}

void print_top()
{
    if (top == NULL)
        printf("\nThere is no Top in an EMPTY stack\n");
    else
        printf("\nTop of the Stack = %d \n",top->data);
}