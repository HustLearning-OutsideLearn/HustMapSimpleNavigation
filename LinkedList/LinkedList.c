#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};

typedef struct node LinkedList;

void isempty(LinkedList *head){
    if(head == NULL) printf("NULL\n");
    else printf("NOT NULL\n");
}

LinkedList* init(){
    LinkedList *head = NULL;
    return head;
}

void append(LinkedList **head, int val)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = NULL;
    
    if(*head == NULL)
        *head = newNode;
    else
    {
        struct node *lastNode = *head;
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

void addfront(LinkedList **head, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = *head;
    *head = newNode;
}

void insertafter(struct node * prev, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = val;
    newNode->next = prev->next;
    prev->next = newNode;
}
void insertbefore(struct node * bef, int val){
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->next = bef->next;
    bef->next = newNode;
    newNode->data = bef->data;
    bef->data = val;
}

void del(LinkedList **head){
    struct node *base = *head;
    struct node *next;
    while(base != NULL){
        next = base->next;
        free(base);
        base = next;
    }
    *head = NULL;
}
void printList(struct node *head)
{
    struct node *temp = head;
    while(temp != NULL)
    {
         printf("%d->", temp->data);
         temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    LinkedList *head = init();
    isempty(head);
    append(&head,10);
    append(&head,20);
    append(&head,30);

    printList(head);
    isempty(head);
    
    addfront(&head, 40);
    printList(head);
    
    
    insertafter(head->next, 100);
    printList(head);
    
    insertbefore(head->next, 200);
    printList(head);
    
    del(&head);
    isempty(head);

    return 0;
}