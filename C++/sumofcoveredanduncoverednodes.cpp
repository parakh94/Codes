// C++ program to find sum of Covered and Uncovered node of
// binary tree
#include <bits/stdc++.h>
using namespace std;
 
/* A binary tree node has key, pointer to left
   child and a pointer to right child */
struct Node
{
    int key;
    struct Node* left, *right;
};
 
/* To create a newNode of tree and return pointer */
struct Node* newNode(int key)
{
    Node* temp = new Node;
    temp->key = key;
    temp->left = temp->right = NULL;
    return (temp);
}
 
/* Utility function to calculate sum of all node of tree */
int sum(Node* t)
{
    if (t == NULL)
        return 0;
    return t->key + sum(t->left) + sum(t->right);
}
 
/* Recursive function to calculate sum of left boundary
   elements  */
int uncoveredSumLeft(Node* t)
{
    /*  If left node, then just return its key value   */
    if (t->left == NULL && t->right == NULL)
        return t->key;
 
    /*  If left is available then go left otherwise go right  */
    if (t->left != NULL)
        return t->key + uncoveredSumLeft(t->left);
    else
        return t->key + uncoveredSumLeft(t->right);
}
 
/* Recursive function to calculate sum of right boundary
   elements  */
int uncoveredSumRight(Node* t)
{
    /*  If left node, then just return its key value   */
    if (t->left == NULL && t->right == NULL)
        return t->key;
 
    /*  If right is available then go right otherwise go left  */
    if (t->right != NULL)
        return t->key + uncoveredSumRight(t->right);
    else
        return t->key + uncoveredSumRight(t->left);
}
 
// Returns sum of uncovered elements
int uncoverSum(Node* t)
{
    /* Initializing with 0 in case we don't have
       left or right boundary  */
    int lb = 0, rb = 0;
 
    if (t->left != NULL)
        lb = uncoveredSumLeft(t->left);
    if (t->right != NULL)
        rb = uncoveredSumRight(t->right);
 
    /* returning sum of root node, left boundry
       and right boundry*/
    return t->key + lb + rb;
}
 
// Returns true if sum of covered and uncovered elements
// is same.
bool isSumSame(Node *root)
{
    // Sum of uncovered elements
    int sumUC = uncoverSum(root);
 
    // Sum of all elements
    int sumT = sum(root);
 
    // Check if sum of covered and uncovered is same
    return (sumUC == (sumT - sumUC));
}
 
/* Helper function to print inorder traversal of
   binary tree   */
void inorder(Node* root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}
 
// Driver program to test above functions
int main()
{
    // Making above given diagram's binary tree
    Node* root = newNode(8);
    root->left = newNode(3);
 
    root->left->left = newNode(1);
    root->left->right = newNode(6);
    root->left->right->left = newNode(4);
    root->left->right->right = newNode(7);
 
    root->right = newNode(10);
    root->right->right = newNode(14);
    root->right->right->left = newNode(13);
 
    if (isSumSame(root))
        printf("Sum of covered and uncovered is same\n");
    else
        printf("Sum of covered and uncovered is not same\n");
}
