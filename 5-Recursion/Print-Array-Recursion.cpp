#include <iostream>

using namespace std;

void printArrayRecursion(int userInput[]  , int sizeOfArray )
{
    // IMPORTANT NOTE :
    // AGAIN
    // Printing array Elements Can Be Implemented in MANY MANY ways , Depending on Many things
    if (sizeOfArray == 1 )
        //return userInput[0] ;
        cout << userInput[0]  <<" ";
    else
    {
        int newSizeOfArray = sizeOfArray - 1  ;
        /*
        // IMPORTANT :
        // If I swap the Two Lines Below {Printing first then Calling Function again}
        // it will Print in the opposite Direction [ From Right to Left ]
        // This Printing Example is GREAT to Demonstrate the Order Of "Stack Call" For Recursion
        */
        printArrayRecursion(userInput , newSizeOfArray)  ;
        cout << userInput[newSizeOfArray]<<" ";

    }
}

int main()
{
    int myArray[5] = {5,4,4,3,1} ;
    printArrayRecursion(myArray,5) ;
    return 0;
}
