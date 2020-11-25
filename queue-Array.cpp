#include <iostream>
using namespace std;

class queueArr
{
private:
    int* front;
    int* rear;
    int size;
    int* queue;
    int filledSize;


public:

    queueArr()
    {
//        front = rear = NULL;
        cout << "enter size" << endl;
        cin >> size;
        queue = new int[size];
        for (int i = 0; i < size; ++i) {
            *(queue+i) = 0;
        }
        front = queue;
        rear = queue;
        filledSize = 0;

    }

    void enque(int value)
    {
        if (filledSize == size)
        {
            cout << "full" << endl;
            return;
        }

        if(*front == 0)
        {
            *front = value;
            filledSize++;
            return;
        }

        *(rear+1) = value;
        rear = (rear + 1);
        return;

    }

    void printNode()
    {
        int* temp = front;

        for (int i = 0; i < filledSize; ++i) {
            cout << *(temp+i) << endl;
        }
        return;
    }


};

int main() {

    queueArr queueArr1;
    queueArr1.enque(21);
    queueArr1.printNode();

    return 0;
}
