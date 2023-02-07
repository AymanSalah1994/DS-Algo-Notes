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
    int x =  0  ;
    for (x  ; x < sizeOfInput ; x++)
    {
        int j ;
        for (j = 0  ; j <  sizeOfInput - 1 ; j++ )
        // J is Less Than Size-1 because we will use "j+1" in the index ! (to avoid out of range exception)
        {
            if (userInput[j] < userInput[j+1])
            {
                // < means first loop puts the smallest to right
                // > means first loop puts the largest to right
                mySwap(userInput[j], userInput[j+1]) ;
            }
        }
    }
}

int main()
{
    int myNumbers[10] = {4,54,56,23,768,3,0,12,11,77777} ;
    bubbleSorting(myNumbers, 10) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
