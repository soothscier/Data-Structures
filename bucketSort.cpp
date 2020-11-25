#include <iostream>
using namespace std;

struct node
{
    float data;
    node* next;
};

struct buck
{
    node*next;
};

class bucketSort {
private:
    node *head;
    int counter;

public:
    bucketSort() {
        head = NULL;
        counter = 0;
//        buck1 = NULL;
    }

    node *createNode(float value) {
        if (head == NULL) {
            head = new node;
            head->next = NULL;
            head->data = value;
            return head;
        }

        node *temp = head;

        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new node;
        temp->next->data = value;
        temp->next->next = NULL;
        return temp->next;

    }

    float *sort(float arr[], int size) {
        buck *bucky = new buck[size];
        node *temp = NULL;


        for (int i = 0; i < size; ++i) {
            bucky[i].next = NULL;
        }

        for (int i = 0; i < size; ++i) {
            int a = int(arr[i] * 10);

            if (a > size-1)
            {
                a = size-1;
            }

            if (bucky[a].next == NULL) {
                temp = new node;
                temp->data = arr[i];
                temp->next = NULL;
                bucky[a].next = temp;
                temp = NULL;
            } else {
                temp = new node;
                temp->next = NULL;
                temp->data = arr[i];
                node *temp2 = bucky[a].next;

                if (temp2->data > temp->data)
                    swap(temp2->data, temp->data);

                while (temp2->next != NULL)
                {
                    if (temp2->data > temp->data)
                        swap(temp2->data, temp->data);
                    temp2 = temp2->next;
                }

                temp2->next = temp;
                temp = temp2 = NULL;

            }

        }

        for (int j = 0; j < size; ++j) {
            if (bucky[j].next != NULL)
            {
                temp = bucky[j].next;
                while(temp!= NULL)
                {
                    arr[counter] = temp->data;
                    counter ++ ;
//                    cout << temp->data  << "  ";
                    temp = temp->next;
                }
//                cout << endl;
            }
        }

        return arr;


    }
};




int main()
{
    float arr[] = {0.2,0.43,0.1,0.234,0.12,0.14, 0.98,0.78};
    bucketSort bucketSort1;
    bucketSort1.sort(arr,8);

}
