#include<stdio.h>
#include<stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *get_new_node(struct node *head, int data)  // Insertion in an empty list
{
    struct node *temp = malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

struct node *add_at_end(struct node *head, int data)
{
    struct node *temp1, *temp2;
    temp1 = (struct node*)malloc(sizeof(struct node));
    temp1->prev = NULL;
    temp1->data = data;
    temp1->next = NULL;
    temp2 = head;
    while(temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
    temp1->prev = temp2;
    return head;
}

struct node *create_list(struct node *head)
{
    int n, data, i;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    if(n == 0)
    {
        return head;
    }
    printf("Enter the element for the node 1: ");
    scanf("%d", &data);
    head = get_new_node(head, data);

    for(i=1; i<n; i++)
    {
        printf("Enter the element for the node %d: ", i+1);
        scanf("%d", &data);
        head = add_at_end(head, data);
    }
    return head;
}

struct node *reverse_list(struct node *head)
{
    struct node *ptr1 = head;
    struct node *ptr2 = ptr1->next;

    ptr1->next = NULL;
    ptr1->prev = ptr2;

    while(ptr2 != NULL)
    {
        ptr2->prev = ptr2->next;
        ptr2->next = ptr1;
        ptr1 = ptr2;
        ptr2 = ptr2->prev;
    }
    head = ptr1;
    return head;
}

void Print(struct node *head)
{
	struct node* temp = head;
	printf("List is : ");
	while(temp != NULL)
    {
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}


int main()
{

    struct node *head;
    head = NULL;

    head = create_list(head);
    Print(head);

    head = reverse_list(head);
    printf("After reversing the list\n");
    Print(head);

}

/*

Enter the number of nodes: 5
Enter the element for the node 1: 1
Enter the element for the node 2: 2
Enter the element for the node 3: 3
Enter the element for the node 4: 4
Enter the element for the node 5: 5
List is : 1 2 3 4 5
After reversing the list
List is : 5 4 3 2 1
*/
