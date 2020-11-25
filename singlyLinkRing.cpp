#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class singlyLinkedRing
{
private:

    node* head;
    node* temp;

public:

    singlyLinkedRing()
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
            head->next = head;
            return;
        }

        if (head->next==head)
        {
            temp = new node;
            temp->next = head;
            temp->data = value;
            head->next = temp;
            temp = NULL;
            return;
        }

        temp = head->next;

        while(temp != head)
        {
            if (temp->next == head)
            {
                temp->next = NULL;
                temp->next = new node;
                temp->next->data = value;
                temp->next->next = head;
                temp = NULL;
                return;
            }
            temp = temp->next;
        }
    }

    void insertNodeMultiple(int ind, int value)
    {
        if (head->data == ind)
        {
            temp = new  node;
            temp->data = value;
            temp->next = head->next;
            head->next = temp;
            temp = NULL;
            return;
        }
        temp = head->next;
        while(temp!=head)
        {
            if (temp->data == ind)
            {
                node* temp2 = new node;
                temp2->next = temp->next;
                temp2->data = value;
                temp->next = temp2;
                temp2 = NULL;
                return;
            }
            temp = temp->next;
        }
    }


    void insertNode(int ind, int value)
    {
        if (head->data == ind)
        {
            temp = new  node;
            temp->data = value;
            temp->next = head->next;
            head->next = temp;
            temp = NULL;
            return;
        }

        temp = head->next;

        while(temp!=head)
        {
            if (temp->data == ind)
            {
                node* temp2 = new node;
                temp2->next = temp->next;
                temp2->data = value;
                temp->next = temp2;
                temp2 = NULL;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteNode(int value)
    {
        if(head->data == value)
        {
            temp = head->next;
            delete head;
            head=temp;
            temp = NULL;
            return;
        }

        temp = head->next;
        if (temp->data == value)
        {
            head->next = temp->next;
            delete temp;
            temp = NULL;
            return;
        }
        temp = head->next;

        while (temp!=head)
        {
            if (temp->next->data == value)
            {
                node* temp2 = temp->next->next;
                delete temp->next;
                temp->next = temp2;
                temp2 = NULL;
                temp = NULL;
                return;
            }

            temp = temp->next;
        }
    }

    void printNode()
    {
        temp = head->next;
        cout << head->data << endl;
        while(temp!=head)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }

};

int main() {
    singlyLinkedRing ring;

    ring.createNode(2);
    ring.createNode(1);
    ring.createNode(3);
    ring.createNode(3);
    ring.createNode(3);
    ring.createNode(3);
    ring.insertNode(3,4);
    ring.deleteNode(4);
    ring.printNode();

    return 0;
}
