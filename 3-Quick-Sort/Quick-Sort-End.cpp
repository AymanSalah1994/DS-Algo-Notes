#include <iostream>
using namespace std;

void mySwap(int &x, int &y)
{
    int temp ;
    temp = x ;
    x = y ;
    y = temp ;
}

int partitionFunction(int myArr[], int startIndex, int endIndex )
{
    int pivot  = myArr[endIndex] ; // Picking a Pivot Point , Can be Start Or end Index ;

    int i = startIndex - 1   ;
    // TODO : Explain

    for (int j  =  startIndex  ; j < endIndex ; j++)
    {
        if (myArr[j] <  pivot)
        {
            // So , you Pick Pivot and Put the smalls Left to It , together side by side
            // you loop through the array and if you find any element smaller than pivot
            // you put it on the left side (starting from start index and the indexes after it )
            // in the first time this means index 0 , one , two ...etc

            i++ ;
            mySwap(myArr[i], myArr[j]) ;
        }
    }
    mySwap(myArr[i+1], myArr[endIndex]) ;
    // Take the Element After After latest Small and swap with pivot
    // if array is odd , pivot in middle bigs are in right , smalls are in left
    // if array is even , right side is bigs , left side is smalls
    return i + 1  ;
}


void QSort(int userArray[], int theStart, int theEnd  )
{
    if (theStart >= theEnd)
        return ;
    int iPivotIndex  = partitionFunction(userArray, theStart, theEnd) ;
    QSort(userArray, theStart, iPivotIndex - 1 ) ; // Recursion
    QSort(userArray, iPivotIndex + 1, theEnd) ; // Recursion with partial piece of the array
}

int main()
{
    //int myNumbers[10] = {4,54,56,23,768,3,0,12,11,4} ;
    //int myNumbers[10] = {411,57,5,26,76,5,667,4,1,44} ;
    int myNumbers[10] = {99,77,23,34,0,55,7,55,11,9} ;
    QSort(myNumbers, 0, 9) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
