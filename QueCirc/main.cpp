#include <iostream>
using namespace std;
class Queue
{
    int rearQ  ;
    int frontQ  ;
    int* arr  ;
    int sizeQ  ;
public :
    Queue(int _sizeQ)
    {
        frontQ = rearQ = -1  ;
        sizeQ = _sizeQ ;
        arr = new int[sizeQ] ;
    }

    // TODO : DTOR and the Copy CTOR
    void enqU(int userInput)
    // enqU Deal With Rear
    {
        if ((frontQ == 0 & rearQ  == sizeQ - 1) || (frontQ == rearQ + 1) )
        {
            cout<<"Queue is Full !" <<endl ;
            return ;
        }
        else
        {
            // Still Empty
            if (rearQ == -1 )
            {
                rearQ = frontQ = 0  ;
            }
            else if (rearQ == sizeQ -1 )
            {
                rearQ = 0  ;
            }

            else
            {
                rearQ++ ;
            }
            arr[rearQ] = userInput ;
        }
    }

    int deqU(int& userInputHolder)
    {
        if (frontQ == -1 )
        {
            cout<<"No Elements !" <<endl ;
            return 0  ;
        }

        else
        {
            // The Variable that will Hold the de-Queued Value
            userInputHolder = arr[frontQ] ;
            // First Prepare the Front
            if (frontQ == rearQ)
            {
                frontQ = rearQ = -1 ;
            }
            else if (frontQ == sizeQ - 1 )
            {
                frontQ = 0  ;
            }
            else
            {
                frontQ++ ;
            }


        }
    }

};


int main()
{
    Queue qoqo(4) ;
    qoqo.enqU(5) ;
    qoqo.enqU(5) ;
    qoqo.enqU(5) ;
    qoqo.enqU(5) ;
    qoqo.enqU(5) ;
    qoqo.enqU(5) ;
    int y  ;
    qoqo.deqU(y) ;
    qoqo.deqU(y) ;
    qoqo.deqU(y) ;
    qoqo.deqU(y) ;
    qoqo.deqU(y) ;
    qoqo.deqU(y) ;
    cout<<y<<endl ;
    return 0;
}
