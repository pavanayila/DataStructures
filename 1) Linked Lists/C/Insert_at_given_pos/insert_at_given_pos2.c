#include<stdio.h>
#include<stdlib.h>


struct node
{
    int data;
    struct node *next;
};


void Print(struct node *head)
{
    struct node *temp = head;
    printf("List is : ");
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct node *insert_at_pos(struct node *head, int data, int pos)
{
    int i;
    struct node *temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->data = data;
    temp1->next =NULL;
    if(pos == 1)
    {
        temp1->next = head;
        head = temp1;
        return;
    }
    struct node *temp2 = head;
    for(i=0; i<pos-2; i++)
    {
        temp2 = temp2->next;
    }
    temp1->next = temp2->next;
    temp2->next = temp1;
    return head;
}
int main()
{
    struct node *head;
    head = NULL;  //empty list
    head = insert_at_pos(head, 2, 1);  // List : 2
    head = insert_at_pos(head, 3, 2);  // List : 2, 3
    head = insert_at_pos(head, 4, 1);  // List : 4, 2, 3
    head = insert_at_pos(head, 5, 2);  // List : 4, 5, 2, 3
    Print(head);
}
