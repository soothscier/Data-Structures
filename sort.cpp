#include <iostream>
#include <cmath>
using namespace std;

class sort
{
public:

    void selection(int arr[], int size)
    {

        for (int i = 0; i < size; ++i) {

            for (int j = i; j < size; ++j) {
                if (arr[i] > arr[j])
                    swap(arr[i], arr[j]);
            }
        }

        for (int i=0; i < size; i++)
            cout << arr[i] << endl;
    }

    void bubble(int arr[], int size)
    {
        for (int i = 0; i < size; ++i)
        {
            for (int j = 0; j < size; ++j)
            {
                if (arr[i] < arr[j])
                    swap(arr[i], arr[j]);
            }
        }

        for (int i=0; i < size; i++)
            cout << arr[i] << endl;
    }


};


int main() {

    sort sort1;

//    int arr[10] = {212,3,12,12,5,31,53,21,42,21};
//
//    sort1.bubble(arr,10);
    cout << 3/2 << endl;


    return 0;
}



