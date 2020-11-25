#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node*pre;
};

class doublyLinkList
{

private:
    node* head;
    node* temp;

public:

    doublyLinkList()
    {
        head = NULL;
        temp = NULL;
    }

    void createNode(int value)
    {
        if (head == NULL)
        {
            head = new node;
            head->pre = NULL;
            head->next = NULL;
            head->data = value;
            return;
        }

        temp = head;

        while(temp->next!=NULL)
        {

            temp = temp->next;

        }

        temp->next = new node;
        temp->next->pre = temp;
        temp->next->next = NULL;
        temp->next->data = value;
        return;

    }

    void insertNode(int value, int indValue)
    {
        temp = head;
        node* temp2 = NULL;
        while(temp!=NULL)
        {
            if (temp->data == indValue)
            {
                if (temp->next == NULL)
                {
                    temp2 = new node;
                    temp2->data = value;
                    temp2->next = temp->next;
                    temp->next = temp2;
                    temp2 = NULL;
                    temp = temp->next;

                }
                else
                {
                    temp2 = new node;
                    temp2->data = value;
                    temp2->next = temp->next;
                    temp2->next->pre = temp2;
                    temp->next = temp2;
                    temp2->pre = temp;
                    temp2 = NULL;
                    temp = temp->next;
                }
            }
            temp= temp->next;
        }
    }

    void deleteNode(int value)
    {
        if (head->data == value)
        {
            temp = head->next;
            delete temp->pre;
            head = temp;

            return;

        }

        temp = head;
        while(temp->next!=NULL)
        {
            if (temp->next->data == value && temp->next->next == NULL)
            {
                delete temp->next;
                temp->next = NULL;
                return;
            }

            else if (temp->next->data == value)
            {
                temp->next = temp->next->next;
                delete temp->next->pre;
                temp->next->pre = temp;
                return;
            }
            temp = temp->next;
        }
        return;
    }

    void printNode()
    {
        temp = head;
        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

};


int main()
{
    doublyLinkList doubly;
    doubly.createNode(1);
    doubly.createNode(2);
    doubly.createNode(3);
    doubly.insertNode(12,3);
    doubly.deleteNode(12);
    doubly.printNode();
}
