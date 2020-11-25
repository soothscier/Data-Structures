#include <iostream>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;

};

class Tree
{
private:


public:

    node* root;
    int left, right,max, leftTree,rightTree;
    int rightC,leftC;
    Tree()
    {
        leftTree = rightTree = left = right = max = 0;
        root = NULL;
        rightC = leftC = 0;
    }

    void insert(node* temp, int value)
    {

        if (root == NULL)
        {
            root = new node;
            root->data = value;
            root->left = NULL;
            root->right = NULL;
            temp = root;
            return;
        }

        if (value < temp->data)
        {
            if (temp-> left == NULL)
            {
                temp->left = new node;
                temp->left->data = value;
                temp->left->left = NULL;
                temp->left->right= NULL;
                return;
            }

            else
            {
                insert(temp->left, value);
            }
        }

        else if (value > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = new node;
                temp->right->data = value;
                temp->right->right = NULL;
                temp->right->left = NULL;
                return;
            }

            else
            {

                insert(temp->right, value);
            }
        }
        return;

    }


    void print(node* temp)
    {

        if (temp->left != NULL)
            print(temp->left);

        cout << temp->data << endl;

        if (temp->right != NULL)
            print(temp->right);


    }


    void delNode(node* temp, int value)
    {
        if (value == root->data)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                delete root;
                root = NULL;
                temp = root;
                return;
            }

            if (temp->left == NULL && temp->right != NULL)
            {
                temp = root;
                root = temp->right;
                delete temp;
                temp = NULL;
                return;
            }

            if (temp->left != NULL && temp->right == NULL)
            {
                temp = root;
                root = temp->left;
                delete temp;
                temp = NULL;
                return;
            }

            if (temp->left != NULL && temp->right != NULL)
            {
                temp = root;
                swap(temp);
                return;
            }

        }

        if (temp->data == value)
        {
            if (temp->left == NULL && temp->right == NULL)
            {
                delete temp;
                temp = NULL;
                root = temp;
            }

            if (temp->left != NULL && temp->right == NULL)
            {
                node* temp2 = temp;
                temp = temp->left;
                delete temp2;
                temp2 = NULL;
                root = temp;
                return;
            }

            if (temp->left == NULL && temp->right != NULL)
            {
                node* temp2 = temp;
                temp = temp->right;
                delete temp2;
                temp2 = NULL;
                root = temp;
                return;
            }

            if (temp->left !=NULL && temp->right != NULL)
            {
                swap(temp);
            }

        }

        ////////////////////////LEFT/////////////////////////////////////////

        if (temp->left != NULL)
        {
            if (temp->left->data == value)
            {
                if (temp->left->right == NULL && temp->left->left == NULL) {
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }

                if (temp->left->right != NULL && temp->left->left == NULL)
                {
                    node* temp2 = temp->left;
                    temp->left = temp->left->right;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }

                if (temp->left->left != NULL && temp->left->right == NULL)
                {
                    node* temp2 = temp->left;
                    temp->left = temp->left->left;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }

                if (temp->left->left != NULL && temp->left->right != NULL)
                {
                    swap(temp->left);
                    return;
                }
            }



            else
            {
                delNode(temp->left, value);
            }
        }



        ////////////////////////RIGHT/////////////////////////////////////////
        if (temp->right != NULL)
        {
            if (temp->right->data == value)
            {
                if (temp->right->right == NULL && temp->right->left == NULL)
                {
                    delete temp->right;
                    temp->right = NULL;
                    return;
                }

                if (temp->right->right != NULL && temp->right->left == NULL)
                {
                    node* temp2 = temp->right;
                    temp->right = temp->right->right;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }

                if (temp->right->left != NULL && temp->right->right == NULL)
                {
                    node* temp2 = temp->right;
                    temp->right = temp->right->left;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }


                if (temp->right->left != NULL && temp->right->right != NULL)
                {
                    swap(temp->right);
                    return;
                }

            }

            else
            {
                delNode(temp->right,value);
            }
        }
    }

    void swap(node* temp)
    {
        node* temp2 = temp;

        temp = temp->right;

        if(temp->left == NULL)
        {
            temp2->right = temp->right;
            temp2->data = temp->data;
            delete temp;
            temp = NULL;
            return;
        }

        while(temp->left != NULL)
        {
            if (temp->left->left == NULL)
            {
                if (temp->left->right == NULL)
                {
                    temp2->data = temp->left->data;
                    delete temp->left;
                    temp->left = NULL;
                    return;
                }

                else
                {
                    temp2->data = temp->left->data;
                    temp2 = temp->left;
                    temp->left = temp->left->right;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }

            }

            temp = temp->left;
        }
    }

    int max_depth(node* temp)
    {

        if (temp == NULL)
        {
            cout << "NULL" << endl;
            return 0;
        }

        if (temp->left!=NULL)
        {
            max_depth(temp->left);
            left += 1;
        }

        if (temp->right!=NULL)
        {
            max_depth(temp->right);
            right += 1;
        }

        if (left > right)
            max = left;
        else
            max = right;

        return max;
    }


    bool bf(node* p)
    {
        int tempL = max_depth(p->left);
        int tempR = max_depth(p->right);
        int tempBalance = tempL - tempR;

        return tempBalance == -1 || tempBalance == 0 || tempBalance == 1;
    }

    void destructor(node* temp)
    {
        if (temp == NULL)
            return;

        if (temp->left != NULL)
            destructor(temp->left);

        if (temp->right != NULL)
            destructor(temp->right);

        delete temp;
    }

    void granchild(node* temp)
    {
        if (temp->left!=NULL)
        {
            granchild(temp->left);
        }

        if (temp->left!=NULL)
        {
            if (temp->left->left != NULL)
            {
                leftC++;
            }
        }

        if (temp->right!=NULL)
        {
            if (temp->right->right != NULL)
            {
                rightC++;
            }
        }

        if (temp->right!=NULL)
        {
            granchild(temp->right);
        }

    }

    void levelOrder(node* temp)
    {
        int h = max_depth(temp);
        for (int i = 1; i < h; i++)
        {
            levelLeaves(temp, i, i);
        }
    }

    void levelLeaves(node* temp, int level, int tempL)
    {

        if (root == NULL)
            return;

        if (level == 1) {
        cout << "Level: " << tempL << " : " << temp->data << endl;
        }

        else
        {
//            cout << "hamza" << endl;
            levelLeaves(temp->left, level - 1, tempL);
            levelLeaves(temp->right, level - 1, tempL);
        }


    }

    ~Tree()
    {
        destructor(root);
    }

};


int main()
{
    Tree tree;

    tree.insert(tree.root, 25);
    tree.insert(tree.root, 51);
    tree.insert(tree.root, 52);
    tree.insert(tree.root, 40);
    tree.insert(tree.root, 54);

    tree.insert(tree.root, 5);
    tree.insert(tree.root, 10);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 9);
    tree.insert(tree.root, 4);
    tree.insert(tree.root, 2);
    tree.insert(tree.root, 1);
    tree.insert(tree.root, 3);

    tree.granchild(tree.root);
//    cout << tree.leftC << "  " << tree.rightC << endl;

    tree.levelOrder(tree.root);



//    cout  << tree.max_depth(tree.root) << endl;
//    cout  << tree.bf(tree.root) << endl;
//    cout << tree.left << "   " << tree.right << endl;

//    tree.print(tree.root);

}
