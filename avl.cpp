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
    int left, right,max;
    string str;

    Tree()
    {
        left = right = max = 0;
        root = NULL;
    }

    void RR(node* temp)
    {
        int swap = temp->right->data;
        temp->right->data = temp->data;
        temp->data = swap;

        //step2
        temp->left = temp->right;
        temp->right = temp->right->right;

        //step3
        temp->left->right = temp->left->left;
        temp->left->left = NULL;
        return;
    }

    void LL(node* temp)
    {
        //swap
        int swap = temp->left->data;
        temp->left->data = temp->data;
        temp->data = swap;

        //step2
        temp->right = temp->left;
        temp->left = temp->left->left;

        //step3
        temp->right->left = temp->right->right;
        temp->right->right = NULL;

        return;
    }

    void rotate(node* temp, const string &condition)
    {
        if (condition == "LL")
        {
            cout << "rotate LL" << endl;
            LL(temp);
            return;

        }

        if (condition == "RR")
        {
            cout << "rotate RR" << endl;

            RR(temp);
            return;
        }

        if (condition == "LR")
        {
            node* temp2 = temp->left;
            temp->left = temp->left->right;
            temp->left->left = temp2;
            temp2->left = NULL;
            temp2->right = NULL;
            temp2 = NULL;

            cout << "rotate LR" << endl;
            //swap

            LL(temp);

            return;
        }

        if (condition == "RL")
        {
            node* temp2 = temp->right;
            temp->right = temp->right->left;
            temp->right->right = temp2;
            temp2->right = NULL;
            temp2->left = NULL;
            temp2 = NULL;

            cout << "rotate RL" << endl;

            RR(temp);

            return;
        }
    }

    void insert(node* temp, int value)
    {
        if (root == NULL)
        {
            temp = new node;
            temp->right = NULL;
            temp->left = NULL;
            temp->data = value;
            root = temp;
            return;
        }

        if (value < temp->data)
        {
            if (temp->left == NULL)
            {
                temp->left = new node;
                temp->left->data = value;
                temp->left->left = NULL;
                temp->left->right = NULL;
                return;
            }
            else
                insert(temp->left, value);
        }


        if (value > temp->data)
        {
            if (temp->right == NULL)
            {
                temp->right = new node;
                temp->right->data = value;
                temp->right->left = NULL;
                temp->right->right = NULL;
                return;
            }
            else
                insert(temp->right, value);
        }

        int balance = bf(temp);
        if (balance > 1)
        {
            if (temp->left->data > value)
            {
                cout << "LL" << endl;
                //LL
                rotate(temp, "LL");
            }
            else if (temp->left->data < value)
            {
                //LR
                rotate(temp, "LR");
            }
        }

        if (balance < -1)
        {
            if (temp->right->data < value)
            {
                //RR
                cout << "RR" << endl;
                rotate(temp,"RR");
            }
            else if (temp->right->data < value)
            {
                //RL
                rotate(temp,"RL");
            }
        }
    }

    void swap_delete(node* temp)
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

    void deleteNode(node* temp, int value)
    {
        if (root == NULL)
        {
            cout << "root is NULL";
            return;
        }

        if (temp->left != NULL)
        {
            if (value == temp->left->data)
            {
                if (temp->left->left == NULL && temp->left->right == NULL)
                {
                    delete temp->left;
                    temp->left = NULL;
                }

                if (temp->left->left != NULL && temp->left->right == NULL)
                {
                    node* temp2 = temp->left;
                    temp->left = temp->left->left;
                    delete temp2;
                    temp2 = NULL;
                    return;
                }

                if (temp->left->left == NULL && temp->left->right!= NULL)
                {
                    node* temp2 = temp->left;
                    temp->left = temp->left->right;
                    delete temp2;
                    temp2 = NULL;
                }

                if (temp->left->left != NULL && temp->left->right != NULL)
                {
                    swap_delete(temp->left);
                }

            }
            else
                deleteNode(temp->left, value);
        }

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
                    swap_delete(temp->right);
                    return;
                }
            }

            else
            {
                deleteNode(temp->right,value);
            }
        }



    }



    void printNode(node*temp)
    {
        if (temp->left!=NULL)
            printNode(temp->left);

        cout << temp->data << endl;

        if (temp->right != NULL)
            printNode(temp->right);
    }


    int max_depth(node* temp)
    {
        if (temp == NULL)
        {
            return 0;
        }

        if (temp!=NULL)
        {
            left += 1;
            max_depth(temp->left);

        }

        if (temp!=NULL)
        {
            right += 1;
            max_depth(temp->right);

        }

        if (left > right)
            max = left;
        else
            max = right;

        return max;
    }


    int bf(node* p)
    {
        int tempL = max_depth(p->left);
        this->left = this->right = this->max = 0;

        int tempR = max_depth(p->right);
        this->left = this->right = this->max = 0;

        int tempBalance = tempL - tempR;

        return tempBalance;
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

    ~Tree()
    {
        destructor(root);
        root = NULL;
        left = right = max = 0;
    }

};


int main()
{
    Tree tree;

    tree.insert(tree.root, 20);
    tree.insert(tree.root, 15);
    tree.insert(tree.root, 4);

    tree.printNode(tree.root);

}
