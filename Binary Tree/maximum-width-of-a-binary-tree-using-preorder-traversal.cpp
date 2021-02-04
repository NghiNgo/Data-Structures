// C++ program to calculate width of binary tree
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
and a pointer to right child */
class node
{
public:
    int data;
    node *left;
    node *right;
};

// A utility function to get
// height of a binary tree
int height(node *node);

// A utility function to allocate
// a new node with given data
node *newNode(int data);

// A utility function that returns
// maximum value in arr[] of size n
int getMax(int arr[], int n);

// A function that fills count array
// with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(node *root, int count[], int level);

/* Function to get the maximum
width of a binary tree*/
int getMaxWidth(node *root)
{
    int width;
    int h = height(root);

    // Create an array that will
    // store count of nodes at each level
    int *count = new int[h];

    int level = 0;

    // Fill the count array using preorder traversal
    getMaxWidthRecur(root, count, level);

    // Return the maximum value from count array
    return getMax(count, h);
}

// A function that fills count array
// with count of nodes at every
// level of given binary tree
void getMaxWidthRecur(node *root, int count[], int level)
{
    if (root)
    {
        count[level]++;
        getMaxWidthRecur(root->left, count, level + 1);
        getMaxWidthRecur(root->right, count, level + 1);
    }
}

/* UTILITY FUNCTIONS */
/* Compute the "height" of a tree -- the number of
	nodes along the longest path from the root node
	down to the farthest leaf node.*/
int height(node *node)
{
    if (node == NULL)
        return 0;
    else
    {
        /* compute the height of each subtree */
        int lHeight = height(node->left);
        int rHeight = height(node->right);
        /* use the larger one */

        return (lHeight > rHeight) ? (lHeight + 1)
                                    : (rHeight + 1);
    }
}

/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
node *newNode(int data)
{
    node *Node = new node();
    Node->data = data;
    Node->left = NULL;
    Node->right = NULL;
    return (Node);
}

// Return the maximum value from count array
int getMax(int arr[], int n)
{
    int max = arr[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

/* Driver code*/
int main()
{
    node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

    cout << "Maximum width is " << getMaxWidth(root)
            << endl;

    cout << endl;
    system("pause");
    return 0;
}
