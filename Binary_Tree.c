#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *createNode(int data)
{
    struct node *n;                                 // creating a node pointer
    n = (struct node *)malloc(sizeof(struct node)); // Allocating memory in the heap
    n->data = data;                                 // setting the data
    n->left = NULL;                                 // setting the left and right children to NULL
    n->right = NULL;                                // setting the left and right children to NULL
    return n;                                       // finally returning the creating node
}
void preorder(struct node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void postorder(struct node *root)
{
    if (root != NULL)
    {

        preorder(root->left);
        preorder(root->right);
        printf("%d ", root->data);
    }
}
void inorder(struct node *root)
{
    if (root != NULL)
    {

        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}
int main()
{

    // constructing the root node or first node
    struct node *p = createNode(4);
    struct node *p1 = createNode(1);
    struct node *p2 = createNode(6);
    struct node *p3 = createNode(5);
    struct node *p4 = createNode(2);
    // finally tree looks like this:

    p->left = p1;
    p->right = p2;
    p1->left = p3;
    p1->right = p4;
    printf("Preorder:");
    preorder(p);
    printf("\n");
    printf("Postorder:");
    postorder(p);
    printf("\n");
    printf("inorder:");
    inorder(p);
    printf("\n");
    return 0;
}
