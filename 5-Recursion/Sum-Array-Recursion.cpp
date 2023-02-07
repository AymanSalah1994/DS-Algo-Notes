#include <iostream>

using namespace std;

int sumArrayRecursion(int userInput[]  , int sizeOfArray )
{
    // IMPORTANT NOTE :
    // Sum Or array Can Be Implemented in MANY MANY ways , Depending on the Function arguments and Many things
    if (sizeOfArray == 1 )
        return userInput[0] ;
    else
    {
        int newSizeOfArray = sizeOfArray - 1  ;
        return sumArrayRecursion(userInput , newSizeOfArray) + userInput[newSizeOfArray] ;
    }
}

int main()
{
    int myArray[5] = {2,2,2,2,2} ;
    int result = sumArrayRecursion(myArray,5) ;
    cout << result << endl;
    return 0;
}
