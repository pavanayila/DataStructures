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

struct node *del_first_node_method2(struct node *head)
{
    head = head->next;
    free(head->prev);
    head->prev = NULL;
    return head;
}

struct node *del_last_node(struct node *head)
{
    struct node *temp = head;
    struct node *temp2;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp2 = temp->prev;
    temp2->next = NULL;
    free(temp);
    return head;
}

struct node *del_at_given_pos(struct node *head, int position)
{
    struct node *temp = head;
    struct node *temp2 = NULL;
    if(position == 1)
    {
        head = del_first_node_method2(head);
        return head;
    }
    while(position > 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL)
    {
        head = del_last_node(head);
    }
    else
    {
        temp2 = temp->prev;
        temp2->next = temp->next;
        temp->next->prev = temp2;
        free(temp);
        temp = NULL;
    }
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
    int pos;
    struct node *head;
    head = NULL;

    head = create_list(head);
    Print(head);

    printf("Enter the position of the node to delete: ");
    scanf("%d", &pos);
    head = del_at_given_pos(head, pos);
    printf("After deleting node at position %d ", pos);
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
Enter the position of the node to delete: 3
After deleting node at position 3 List is : 1 2 4 5
*/