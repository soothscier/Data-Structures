#include <iostream>
using namespace std;

class circular
{
private:
    int* f;
    int* r;
    int *arr;
    int size;

public:

    explicit circular(int s)
    {
        arr = new int[s];
        size = s;

        for (int i = 0; i < s; ++i) {
            arr[i] = 0;
        }

        f = r = arr;
    }

    void enque(int temp)
    {
        if (f == r && *r ==0)
        {
            *r = temp;
            return;

        }

        if (f == arr+1)
        {
            r = arr;
            *r = temp;
            return;
        }

        if ((r == arr+(size-1) && f == arr) || r+1 ==  f)
        {
            cout << "overflow" << endl;
            return;
        }

        if (r == arr+(size - 1) && f!=arr)
        {
            r = arr;
            *r = temp;
            return;
        }

        *(r+1) = temp;
        r++;
    }

    void deque()
    {
        if(f ==r && r ==arr)
        {
            cout << "no element present in arr" << endl;
        }

        if (f == arr+(size-1))
        {
            *f = NULL;
            f = arr;
            return;
        }

        if (f == r && f == arr+(size-1))
        {
            *f = NULL;
            f = arr;
            r = arr;
            return;
        }

        *f = NULL;
        f++;

    }

    void print()
    {
        for (int i = 0; i < size; ++i) {
            cout << *(arr+i) << endl;
        }
    }

};


int main() {

    circular queue(10);
    queue.enque(1);
    queue.enque(2);
    queue.enque(3);
    queue.enque(4);
    queue.enque(5);
    queue.enque(6);
    queue.enque(7);
    queue.enque(8);
    queue.enque(9);
    queue.enque(10);
    queue.deque();
    queue.deque();
    queue.enque(11);
    queue.print();




    return 0;
}