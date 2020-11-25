#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class linkedList
{

private:
    node* head;
    node* temp;

public:

    linkedList()
    {
        head = NULL;
        temp = NULL;

    }

    void createNode(int value)
    {


        if(head == NULL)
        {
            head = new node;
            head->data = value;
            head->next = NULL;

            return;
        }

        temp = head;
//        node* temp2 = NULL;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new node;
        temp->next->data = value;
        temp->next->next = NULL;
        temp = NULL;
        return;


    }

    void insertNode(int value, int indValue)
    {
        temp=head;
        node* temp2 = NULL;
        while(temp != NULL)
        {
            if (temp->data == indValue)
            {
                temp2 = new node;
                temp2->data = value;
                temp2->next = temp->next;
                temp->next = temp2;
                temp = temp->next;
                temp2 = NULL;
                // return;
            }
            temp = temp->next;
        }

    }

    void update(int value, int indValue)
    {
        if (head->data == indValue)
        {
            head->data = value;
            return;
        }

        temp = head;
        while (temp != NULL)
        {
            if(temp->data == indValue)
            {
                temp->data = value;
                return;
            }
            temp = temp->next;
        }
        return;

    }

    void deleteNode(int value)
    {
        if(head->data == value)
        {
            delete head;
            head = NULL;
            return;
        }

        temp = head;

        node*temp2;

        while(temp!=NULL)
        {
            if (temp->next->data == value)
            {
                temp2 = temp->next->next;
                delete temp->next;
                temp->next = temp2;
                temp2 = NULL;
                temp = NULL;
                return;
            }


            temp = temp->next;
        }
        return;
    }

    void printNode()
    {
        temp = head;
        while(temp != NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        return;
    }

    ~linkedList()
    {
        delete temp;
        delete head;
    }


};

int main()
{
    linkedList link;
    link.createNode(1);

    link.createNode(1);
    link.createNode(1);


    link.insertNode(12,1);

    link.printNode();



}
