#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int data;
    struct tree *left;
    struct tree *right;
} tree;

tree *createN(int data)
{
    tree *p = malloc(sizeof(tree));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
}

void preorder(tree *t)
{
    if (t != NULL)
    {
        printf("%d ", t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void postorder(tree *t)
{
    if (t != NULL)
    {
        postorder(t->left);
        postorder(t->right);
        printf("%d ", t->data);
    }
}
void inorder(tree *t)
{
    if (t != NULL)
    {
        inorder(t->left);
        printf("%d ", t->data);
        inorder(t->right);
    }
}
int bst(tree *t)
{
    static tree *prev = NULL;
    if (t != NULL)
    {
        if (!bst(t->left))
        {
            return 0;
        }
        if (prev != NULL && t->data <= prev->data)
        {
            return 0;
        }
        prev = t;
        return bst(t->right);
    }
    else
    {
        return 1;
    }
}
int search(tree *root, int n)
{
    if (root != NULL)
    {
        if (n == root->data)
        {

            return 1;
        }
        if (n > root->data)
        {
            if (root->right != NULL)
                search(root->right, n);
            else
                return 0;
        }
        else
        {
            if (root->left != NULL)
                search(root->left, n);
            else
                return 0;
        }
    }
    else
    {
        return 0;
    }
}
void insert(tree *root, int data)
{
    tree *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (data == root->data)
        {
            printf("Cannot insert %d, already in BST", data);
            return;
        }
        else if (data < root->data)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    tree *new = createN(data);
    if (data < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

tree *delete(tree *root, int data)
{
    static tree *prev = NULL;
    // static tree *next = ;
    if (data < root->data)
    {
        prev = root;
        delete (root->left, data);
        // next = root;
    }
    else if (data > root->data)
    {
        prev = root;
        delete (root->right, data);
        // next = root;
    }
    else
    {
        if (root->left == NULL && root->right == NULL)
        {
            if (prev->right->data == root->data)
            {
                prev->right = NULL;
            }
            else
            {
                prev->left = NULL;
            }
        }
        else if (root->left == NULL || root->right == NULL)
        {
            if(root->left->left!=NULL)
            {
                root->data=root->left->data;
                root->left=NULL;
            }
             if(root->left->right!=NULL)
            {
                root->data=root->left->data;
                root->left=NULL;
            }

        }
    }
}
int main()
{
    // tree *t1=NULL;
        tree *p = createN(5);
        tree *p1 = createN(3);
        tree *p2 = createN(6);
        tree *p3 = createN(1);
        tree *p4 = createN(4);
        tree *p5 = createN(7);
        tree *p6 = createN(2);
    // tree *p7 = createN(7);

    p->left = p1;
    p->right = p2;
    p1->left = p6;
    p1->right = p4;
    p2->right = p5;
    p6->left = p3;
    // preorder(t1);
    // printf("\n");
    // postorder(t1);
    // printf("\n");
    // inorder(t1);
    // printf("\n");
    // printf("%d\n", bst(t1));
    // printf("%d\n", search(t1, 6));
    // insert(t1, 3);
    // insert(t1, 4);
    // inorder(t1);
    // printf("%d\n", t1->right->left->data);
    delete (p, 6);
    inorder(p);
    // printf("%d\n",p->left->right->data);

    return 0;
}