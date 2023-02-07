#include <iostream>

using namespace std;


int binarySearchingRecursion(int userArray[],int theRealSize, int keyValue, int _startIndex, int _endIndex)
{
    int startIndex = _startIndex;
    int endIndex = _endIndex  ;
    int keyIndex = -1    ; // Index  Default till we find the Result ?


    if  (startIndex > endIndex)
    {
        keyIndex = -1  ; // Base
        return keyIndex ;
    }

    int middleIndex = (startIndex + endIndex) / 2 ;
    if ( keyValue == userArray[middleIndex])
    {
        keyIndex = middleIndex ;
        return keyIndex ;
    }
    else if ( keyValue < userArray[middleIndex])
    {
        // Recursion again
        binarySearchingRecursion(userArray, 12, keyValue, middleIndex-1, endIndex) ;
    }
    else if (keyValue > userArray[middleIndex] )
    {
        // Recursion again
        binarySearchingRecursion(userArray, 12, keyValue, startIndex, middleIndex+1 ) ;

    }


    cout<<"The index of the Value is : "<<keyIndex<<endl ;
}

int main()
{
    int mySortedArray[12]  = {3,4,5,7,12,33,43,55,67,79,88,99};
    int theIndex  = binarySearchingRecursion(mySortedArray, 12, 0, 99, 11) ;
    cout<<"The Final Index of the Element (if -1 then Does not exist ):"<<theIndex<<endl  ;
    return 0;
}
