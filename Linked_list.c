#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
void Traversal(struct node *head)
{
    struct node *ptr;
    ptr = head;
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {

        while (ptr != NULL)
        {
            printf("%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}
void add_end(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    struct node *ptr;
    ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
struct node *add_first(struct node *head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = head;
    head = temp;
    return head;
}
void add_pos(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = NULL;
    pos--;
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    temp->next = ptr->next;
    ptr->next = temp;
}

struct node *del_begg(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else
    {
        struct node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }
}
void del_last(struct node *head)
{
    if (head == NULL)
    {
        printf("The linked list is empty");
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }

    else
    {
        struct node *ptr1 = head;
        struct node *ptr2 = head;
        while (ptr1->next != NULL)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->next;
        }
        ptr2->next = NULL;
        free(ptr1);
        ptr1 = NULL;
    }
}
void del_posn(struct node *head, int position)
{
    struct node *current = head;
    struct node *prev = head;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    else if (position == 1)
    {
        head = head->next;
        free(current);
        current = NULL;
    }
    else
    {
        while (position != 1)
        {
            prev = current;
            current = current->next;
            position--;
        }
        prev->next = current->next;
        free(current);
        current = NULL;
    }
}
int main()
{
    struct node *head = malloc(sizeof(struct node));
    head->data = 10;
    head->next = NULL;
    struct node *current = malloc(sizeof(struct node));
    head->next = current;
    current->data = 20;
    current->next = NULL;
    printf("Before insertion:\n");
    Traversal(head);
    add_end(head, 30);
    head = add_first(head, 00);
    add_pos(head, 55.2, 3);
    printf("After insertion or Before deletion:\n");
    Traversal(head);
    head = del_begg(head);
    del_last(head);
    int pos;
    printf("Enter the position: ");
    scanf("%d", &pos);
    del_posn(head, pos);
    printf("After deletion:\n");
    Traversal(head);

    return 0;
}