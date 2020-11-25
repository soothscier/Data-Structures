#include <iostream>
#include <cmath>
using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
    int lh;
};



class tree
{
public:
    node* root;
    node* temp2;
    node* temp3;
    node* par;
    int h,nodes, tempNodes;
    bool flag;

    tree()
    {
        root = temp2 = temp3 = par =  NULL;
        h = 0;
        nodes =  0;
        flag = false;
        tempNodes = 0;

    }


    void insert(node* temp, int value)
    {
        if (temp == NULL)
        {
            temp = new node;
            temp->left = NULL;
            temp->right = NULL;
            temp->data = value;
            temp->lh = h;
            root = temp;
            temp = NULL;

            nodes++;
            return;
        }

        if (nodes == pow(2,h+1)-1)
        {
            while(temp->left != NULL)
            {
                temp = temp->left;
            }

            temp->left = new node;
            temp->left->left = temp->left->right = NULL;
            temp->left->data = value;

            h++;
            temp->left->lh = h;
            nodes++;
            return;
        }

        else
        {
            traverse(temp, value);
            flag = false;
            return;
        }
    }

    void traverse(node* temp, int value)
    {
        if (temp->left != NULL)
            traverse(temp->left,value);


        if (!flag && (temp->lh == h - 1) && (temp->left == NULL || temp->right == NULL))
        {

            if (temp->left != NULL && temp->right == NULL)
            {
                temp->right = new node;
                temp->right->data = value;
                temp->right->left = temp->right->right = NULL;
                nodes++;
                temp->right->lh = h;
                flag = true;
                temp2 = temp->left;
                return;
            }

            if (temp->left == NULL && temp->right ==NULL)
            {
                temp->left = new node;
                temp->left->data = value;
                temp->left->left = temp->left->right = NULL;
                nodes++;
                temp->left->lh = h;
                flag = true;
                temp2 = temp->left;
                return;
            }

        }



        if (temp->right != NULL)
            traverse(temp->right, value);
    }

    void deleteCbt(node* temp, int value)
    {
        deletion(temp, value);
        temp3->data = temp2->data;

        if(tempNodes == 1)
        {
            h--;
            tempNodes = 0;
        }

        if (par->right == temp2)
            par->right = NULL;
        else
            par->left = NULL;


        delete temp2;
        temp2 = temp3 = par = NULL;



    }

    void deletion(node* temp, int value)
    {
        if (temp->left != NULL)
            deletion(temp->left, value);


        if (temp->left != NULL)
        {
            if (temp->left->lh == h)
            {
                par = temp;
                temp2 = temp->left;
                tempNodes++;
            }
        }

        if (temp->right != NULL)
        {
            if(temp->right->lh == h)
            {
                par = temp;
                temp2 = temp->right;
                tempNodes++;
            }
        }

        if (temp->data == value)
            temp3 = temp;

        if (temp->right != NULL)
            deletion(temp->right, value);


    }

    void deleteHeap(node*temp)
    {
        deleteHeapUtil(temp);

        if(tempNodes == 1)
        {
            h--;
            tempNodes = 0;
        }

        if (par->right == temp2)
            par->right = NULL;
        else
            par->left = NULL;


        delete temp2;
        temp2 = par = NULL;
    }

    void deleteHeapUtil(node* temp)
    {
        if (temp->left != NULL)
            deleteHeapUtil(temp->left);


        if (temp->left != NULL)
        {
            if (temp->left->lh == h)
            {
                par = temp;
                temp2 = temp->left;
                tempNodes++;
            }
        }

        if (temp->right != NULL)
        {
            if(temp->right->lh == h)
            {
                par = temp;
                temp2 = temp->right;
                tempNodes++;
            }
        }

        if (temp->right != NULL)
            deleteHeapUtil(temp->right);

    }




    void minHeap(node* temp)
    {

        if (temp->left != NULL)
        {
            if (temp->data > temp->left->data)
            {
                swap(temp->lh, temp->left->lh);
                swap(temp->data, temp->left->data);
            }

            minHeap(temp->left);
        }

        if (temp->right != NULL)
        {
            if (temp->data > temp->right->data)
            {
                swap(temp->lh, temp->right->lh);
                swap(temp->data, temp->right->data);
            }

            minHeap(temp->right);
        }


    }

    void maxHeap(node* temp)
    {

        if (temp->left != NULL)
        {
            if (temp->data < temp->left->data)
            {
                swap(temp->lh, temp->left->lh);
                swap(temp->data, temp->left->data);
            }

            minHeap(temp->left);
        }

        if (temp->right != NULL)
        {
            if (temp->data < temp->right->data)
            {
                swap(temp->lh, temp->right->lh);
                swap(temp->data, temp->right->data);
            }

            minHeap(temp->right);
        }
    }



    void print(node* temp)
    {
        if (temp->left != NULL) {
            print(temp->left);
        }

        cout << temp->data << endl;

        if (temp->right != NULL)
            print(temp->right);

    }



};

int main() {

    tree tree1;
    tree1.insert(tree1.root, 100);
    tree1.insert(tree1.root, 7);
    tree1.insert(tree1.root, 8);
    tree1.insert(tree1.root, 10);
    tree1.insert(tree1.root, 20);
    tree1.insert(tree1.root, 120);

    cout << "max Heap" << endl;
    tree1.maxHeap(tree1.root);
    tree1.print(tree1.root);

    cout << "min Heap" << endl;
    tree1.minHeap(tree1.root);
    tree1.print(tree1.root);

    tree1.deleteHeap(tree1.root);



    return 0;
}



