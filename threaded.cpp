#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    bool rth,lth;
};

class Tree {
private:

public:

    node* root;
    node* dummy;

    Tree()
    {
        root = NULL;
        dummy = new node;
        dummy->left = root;
        dummy->data = 0;
        dummy->right = dummy;
        dummy->lth = false;
        dummy->rth = false;
    }

    void insertion(node* temp, int value)
    {
        if(root == NULL)
        {
            root = new node;
            root->data = value;
            root->left = dummy;
            root->lth = true;
            root->right = dummy;
            root->rth = true;
            return;
        }

        if (value < temp->data)
        {
            if (temp->lth)
            {
                node* temp2 = temp->left;
                temp->left = new node;
                temp->left->data = value;
                temp->left->left = temp2;
                temp->left->lth = true;
                temp->left->right = temp->right;
                temp->left->rth = true;
                temp2 = NULL;
                return;
            }

            insertion(temp->left, value);
        }

        if (value > temp->data)
        {
            if (temp->lth)
            {
                node* temp2 = temp->right;
                temp->right = new node;
                temp->right->data = value;
                temp->right->left = temp->left;
                temp->right->lth = true;
                temp->right->right = temp2;
                temp->right->rth = true;
                temp2 = NULL;
                return;
            }

            insertion(temp->right,value);
        }
    }

    void inorder(node* temp)
    {
        
    }

};


int main()
{
    Tree tree;

    tree.insertion(tree.root, 20);
    tree.insertion(tree.root, 22);
    tree.insertion(tree.root, 15);
    tree.insertion(tree.root, 18);
//    tree.insertion(tree.root, 19);
//    tree.insertion(tree.root, 17);
//    tree.insertion(tree.root, 16);


}
