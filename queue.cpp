#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;
};

class hamza
{
private:
    node* front;
    node* rear;

public:
    hamza()
    {
        front = NULL;
        rear = NULL;
    }

    bool isFull(int size)
    {
        int tempSize = 0;
        node* temp = front;

        while(temp != NULL)
        {
            tempSize++;
            temp = temp->next;

        }

        if (tempSize == size)
        {
            cout << "Queue is full" << endl;
            return true;
        }
        else
            return false;
    }


    void createNode(int value, int size)
    {

        if(isFull(size))
        {
            return;
        }

        if (front == NULL)
        {
            front = new node;
            front->data = value;
            front->next = NULL;
            rear = front;
            return;
        }

        rear->next = new node;
        rear->next->data = value;
        rear->next->next = NULL;
        rear = rear->next;
        return;


    }

    void printNode()
    {
        node* temp = NULL;
        temp = front;

        while(temp!=NULL)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
        return;
    }

    void deque()
    {
        node* temp = front;
        front = front->next;
        delete temp;
        temp = NULL;
    }


};




int main() {
//    cout << "Hello, World!" << endl;
    hamza queue1;
    queue1.createNode(1,10);
    queue1.createNode(1,10);

    queue1.deque();

    queue1.printNode();

    return 0;
}
