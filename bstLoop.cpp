#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

class Tree {
private:

public:

    node* root;

    Tree()
    {
        root = NULL;
    }

    void insertion(node* temp, int value)
    {
        if (root == NULL)
        {
            node* temp2 = new node;
            temp2->data = value;
            temp2->left = temp;
            temp2->right = temp;
            root = temp;
            return;
        }

        node* temp2 = NULL;

        while(temp != NULL)
        {
            temp2 = temp;

            if (value < temp->data)
            {
                temp = temp->left;
            }

            else if (value > temp->data)
            {
                temp = temp->right;
            }
        }


        if (value < temp2->data)
        {
            temp2->left = new node;
            temp2->left->data = value;
            temp2->left->left = NULL;
            temp2->left->right = NULL;
            temp2 = NULL;
            return;
        }

        if (value > temp2->data)
        {
            temp2->right = new node;
            temp2->right->data = value;
            temp2->right->left = NULL;
            temp2->right->right = NULL;
            temp2 = NULL;
            return;
        }
    }



    void traverse(node* temp)
    {
        if (temp->left != NULL)
            traverse(temp->left);

        cout << temp->data << endl;

        if (temp->right != NULL)
            traverse(temp->right);
    }

};


int main()
{
    Tree tree;

    tree.insertion(tree.root, 20);
    tree.insertion(tree.root, 22);
    tree.insertion(tree.root, 15);
    tree.insertion(tree.root, 18);
    tree.insertion(tree.root, 19);
    tree.insertion(tree.root, 17);
    tree.insertion(tree.root, 16);

    tree.traverse(tree.root);

}
