#include<stdio.h>
#include<stdlib.h>
struct node
{
    float coefficient;
    int exponent;
    struct node* link;
};
struct node * insert(struct node *head, float co, int ex){
    struct node * temp;
    struct node * newP = malloc(sizeof(struct node));
    newP->coefficient  =  co ;
    newP->exponent = ex;
    newP->link = NULL;
    
    if (head == NULL || ex> head-> exponent )
    {
        newP->link = head;
        head= newP;
    }
    else
    {
        temp = head;
        while (temp->link != NULL && temp->link->exponent >= ex)
        {
           temp = temp->link;
        }
        newP->link = temp->link;
        temp->link = newP;
    }
    return head;
}
struct node* create(struct node* head){
    int n;
    int i;
    float coeff;
    int expo;
    printf("Enter the number of terms: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
       printf("Enter the coefficient for term %d: ",i+1);
       scanf("%f" ,&coeff);

       printf("Enter the exponent for terms %d: ",i+1);
       scanf("%d",&expo);
       head = insert(head,coeff,expo);
    } 
    return head;
}
void print(struct node* head)
{
    if (head == NULL)
    {
        printf("No polynomial.");
    }
    else
    {
        struct node* temp = head;
        while (temp != NULL)
        {
            printf("(%.0fx^%d)",temp->coefficient,temp->exponent);
            temp = temp->link;
            if (temp != NULL)
            {
               printf(" + ");
            }
            else
            {
                printf("\n");
            }      
        }
    } 
}
void polyMultiply(struct node* head1, struct node* head2){
    struct node* ptr1 = head1;
    struct node* ptr2 = head2;
    struct node* head3 = NULL;
    int res2,res1;
    
    if (head1 == NULL || head2 == NULL)
    {
        printf("Zero polynomial\n");
        return;
    }
    
    while (ptr1 != NULL)
    {
        ptr2 = head2;
        while(ptr2 != NULL)
        {
            res1 = ptr1->coefficient * ptr2->coefficient;
            res2 = ptr1->exponent + ptr2->exponent;
            head3 = insert(head3,res1,res2);
            ptr2 = ptr2->link;
        }
        ptr1 = ptr1->link;
    }
    printf("\n Before simplifiaction: \n");
    print(head3);
    struct node* ptr3 = head3;
    struct node* temp = NULL;
    while (ptr3->link != NULL)
    {
        if (ptr3->exponent == ptr3->link->exponent)
        {
            ptr3->coefficient = ptr3->coefficient + ptr3->link->coefficient;
            temp = ptr3->link;
            ptr3->link = ptr3->link->link;
            free(temp);
        }
        else
        {
            ptr3 = ptr3 ->link;
        }
    }
    printf("\n After Simplification: \n");
    print(head3);
}
int main(){
    struct node* head1 = NULL;
    struct node* head2 = NULL;
    printf("Enter the first polynomail\n ");
    head1 = create(head1);
    print(head1);
    printf("Enter the second polynomail\n ");
    head2 = create(head2);
    print(head2);
    polyMultiply(head1,head2);
    return 0;
}