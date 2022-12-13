#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void add_at_pos(struct node *head,int data, int pos){
    struct node * ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->link = NULL;

    pos--;
    while (pos != 1)
    {
       ptr = ptr->link;
       pos--;
    }
    ptr2->link = ptr->link;
    ptr->link = ptr2;
}
struct node * add_at_end(struct node *ptr, int data){
    struct node* temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    ptr->link = temp;
    return temp;
}
void Traversal(struct node *head){
    int count = 0;
    if (head == NULL)
    {
        printf("Linked list is empty");
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        printf("%d\n",ptr->data);
        ptr = ptr->link;
    }
    printf("count: %d ",count); 
}
int main(){
    struct node * head = malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node *ptr = head;
    ptr = add_at_end(ptr,10);
    ptr = add_at_end(ptr,15);
    add_at_pos(head,5, 3);
    Traversal(head);
    return 0;
    
}
