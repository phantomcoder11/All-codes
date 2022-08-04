
/* BST Node
struct Node
{
    int key;
    struct Node *left, *right;
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    // Your code goes here
    if (!root)
        return;
    if (root->left)
        findPreSuc(root->left, pre, suc, key);
    if (root->key < key)
        pre = root;
    if (suc == NULL && root->key > key)
        suc = root;
    if (root->right)
        findPreSuc(root->right, pre, suc, key);
}

void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{

    if (!root)
        return;
    Node *temp = root;
    while (temp)
    {
        if (temp->key <= key)
        {
            temp = temp->right;
        }
        else
        {
            suc = temp;
            temp = temp->left;
        }
    }

    temp = root;
    while (temp)
    {
        if (temp->key < key)
        {
            pre = temp;
            temp = temp->right;
        }
        else
        {
            temp = temp->left;
        }
    }
}