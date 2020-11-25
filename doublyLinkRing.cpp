#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
    node* pre;
};

class doublyLinkRing
{
private:
    node*head;
    node*tail;
    node*temp;

public:
    doublyLinkRing()
    {
        head = NULL;
        tail = NULL;
        temp = NULL;
    }

    void createNode(int value)
    {
        if (head == NULL)
        {
            head = new node;
            head->data = value;
            head->next = head;
            head->pre = head;
            return;
        }

        temp = head;

        while(temp->next!=head)
        {
            temp = temp->next;
        }

        node* temp2 = new node;
        temp2->data = value;
        temp->next = temp2;
        temp2->pre = temp;
        temp2 ->next = head;
        head->pre = temp2;

        return;

    }

    void insertNode(int ind, int value)
    {
        if(head->data == ind)
        {
            temp = new node;
            temp->data = value;
            temp->pre = head;
            temp->next = head->next;
            head->next = temp;
            return;
        }

        temp = head->next;

        while (temp!= head)
        {
            if(temp->data==ind)
            {
                node* temp2 = new node;
                temp2->data = value;
                temp2->next = temp->next;
                temp2->pre = temp;
                temp->next = temp2;
                head->pre = temp2;
                return;
            }
            temp = temp->next;
        }
    }

    void deleteNode(int value)
    {
        if (head->data == value)
        {
//            temp = head->next;
            temp->pre = head->pre;
            delete head;
            head = temp;
            temp = NULL;
            return;
        }

        temp = head->next;

        while(temp!=head)
        {
            if (temp->data == value)
            {
                temp->pre->next = temp->next;
                temp = temp->pre;
                delete temp->next->pre;
                temp->next->pre = temp;
                temp = NULL;
                return;
            }
            temp = temp->next;
        }
    }

    void printNode()
    {
        cout << head->data << endl;
        temp = head->next;
        while(temp!=head)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
};


int main() {

    doublyLinkRing ring;
    ring.createNode(2);
    ring.createNode(3);
    ring.createNode(4);
    ring.insertNode(4,5);
    ring.deleteNode(5);

    ring.printNode();

    return 0;
}
