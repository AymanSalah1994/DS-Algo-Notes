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
        int editedSize = sizeOfInput - x  ;
        /*
        Q / Where Does editedSize Come From ?
        A / Whether you are sorting Descending OR Ascending ,Always the First Inner Loop
        As we Said Will always Sort One Element CORRECTLY , In Descending Largest is At the End
        In Ascending Smallest is At the End ! So We Can Always Use X from the Outer Loop
        TO minimize the Number of Inner loop iterations
        (since the Last elements in the Array are in their Correct Place ! )
        Hence Before each New Inner Loop we reduce the LIMIT Of J
        */
        for (j = 0  ; j <  editedSize ; j++ )
        {
            if (userInput[j] < userInput[j+1])
            {
                mySwap(userInput[j], userInput[j+1]) ;
            }
        }
    }
}


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
