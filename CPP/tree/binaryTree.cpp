#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    Node *left;
    int data;
    Node *right;

    Node(int value)
    {
        data = value;
        left = right = NULL;
    }
};

static int idx = -1;
Node *buildTree(vector<int> preOrder)
{
    idx++;

    if (preOrder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(preOrder[idx]);
    root->left = buildTree(preOrder);
    root->right = buildTree(preOrder);
    return root;
}

void preOrderTravese(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    cout << root->data << " ";
    preOrderTravese(root->left);
    preOrderTravese(root->right);
}

void inOrderTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    inOrderTraverse(root->left);
    cout << root->data << " ";
    inOrderTraverse(root->right);
}

void postOrdreTraverse(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    postOrdreTraverse(root->left);
    postOrdreTraverse(root->right);
    cout << root->data << " ";
}

int main()
{
    vector<int> preOrder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = buildTree(preOrder);

    cout << "Pre-Order Traverse: ";
    preOrderTravese(root);
    cout << endl;
    
    cout << "In-Order Traverse: ";
    inOrderTraverse(root);
    cout << endl;
    
    cout << "Post-Order Traverse: ";
    postOrdreTraverse(root);
    cout << endl;

    return 0;
}