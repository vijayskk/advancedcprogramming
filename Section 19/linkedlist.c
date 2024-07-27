#include <stdio.h>
#include <stdlib.h>

int length = 0;
typedef struct node
{
    int data;
    struct node *next;
} node_t;

void insertFirst(node_t **head, int value);
void insert(node_t **head, int value);
void printList(node_t *head);

int main(int argc, char const *argv[])
{
    node_t *head = NULL;
    while (1 == 1)
    {
        int choice = 0;
        int item = 0;

        printf("Options:\n\t1.Insert\n\n:: ");
        scanf("%d", &choice);
        printf("\nData: ");
        scanf("%d", &item);

        switch (choice)
        {
        case 1:
            if (length < 1)
            {
                insertFirst(&head, item);
            }else{
                insert(&head,item);
            }
            printList(head);
            
            
            break;

        default:
            break;
        }
    }

    return 0;
}

void insertFirst(node_t ** head, int value)
{
    node_t * new_node = malloc(sizeof(node_t));
    length = 1;
    new_node->data = value;
    new_node->next = NULL;
    *head = new_node;
}

void insert(node_t ** head, int value)
{
    node_t * new_node = malloc(sizeof(node_t));
    length++;
    new_node->data = value;
    new_node->next = *head;
    *head = new_node;
}

void printList(node_t *head)
{
    node_t * currptr = head;
    for (int i = 0; i < length; i++)
    {
        node_t curr = *currptr;
        printf("%d\t", curr.data);
        currptr = curr.next;
    }
    printf("\n");
}