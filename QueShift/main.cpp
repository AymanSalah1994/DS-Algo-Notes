#include <iostream>

using namespace std;
class ShiftQueue
{
    int* arr;
    int size;
    int rear;
public:
    ShiftQueue(int _size = 5)
    {
        rear=-1;
        size=_size;
        arr=new int [size];
    }
    int isFull()
    {
        return (rear==size-1);
    }
    void enqueue(int data)
    {
        if(isFull())
        {
            cout <<"queue is full\n";
            return;
        }
        else
        {
            rear++;
            arr[rear] = data;
        }
    }
    int dequeue(int& data)
    {
        if(rear == -1)
        {
            cout << "queue is empty\n";
            return 0;
        }
        data=arr[0];
        for(int i=0; i<rear; i++)
        {
            arr[i]=arr[i+1];
        }
        rear--;
        return 1;
    }

    ~ShiftQueue()
    {
        cout<<"Destructor"<<endl;
        delete arr;
    }
};

int main()
{
    ShiftQueue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    int x;
    if(q1.dequeue(x) == 1)
    {
        cout << x <<endl;
    }
    if(q1.dequeue(x) == 1)
    {
        cout << x <<endl;
    }
    if(q1.dequeue(x) == 1)
    {
        cout << x <<endl;
    }
    if(q1.dequeue(x) == 1)
    {
        cout << x <<endl;
    }
    return 0;
}
