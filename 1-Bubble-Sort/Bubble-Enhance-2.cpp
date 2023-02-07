#include <iostream>

using namespace std;


void mySwap(int &x, int &y)
{
    int temp ;
    temp = x  ;
    x = y ;
    y  = temp  ;
}


void bubbleSorting(int userInput[],int sizeOfInput )
{
    int swappingFlag  ;
    int x =  0  ;
    for (x  ; x < sizeOfInput -1  ; x++)
    {
        swappingFlag = 0  ;
            /*
            This is Enhancement Number 2 ;
            We Make a Flag with Value 0
            If at ANY inner loop this Flag remains Zero , this means No swapping happend at all !!
            This means Everything is OK and Sorted , No need to Continue Bubbling  .
            */
        int j ;
        int editedSize = sizeOfInput - x  ;
        for (j = 0  ; j <  editedSize ; j++ )
        {
            if (userInput[j] > userInput[j+1])
            {
                swappingFlag = 1  ;
                mySwap(userInput[j], userInput[j+1]) ;
            }
        }
        if (swappingFlag == 0)
        {
            break ;
        }
    }
}

// Bubble DOWN the Heavy Elements
int main()
{
    //int myNumbers[10] = {4,54,56,23,768,3,0,12,11,4} ;
    int myNumbers[10] = {411,57,5,26,76,5,667,4,1,44} ;
    bubbleSorting(myNumbers, 10) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
