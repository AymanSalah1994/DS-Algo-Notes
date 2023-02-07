#include <iostream>

using namespace std;

int fibbonacci(int userInput )
{
    if (userInput <= 0 )
        // I made it <= Instead of ==
        // But supposed to be ==
        // I made it for negatives
        return 0 ;
    else if (userInput == 1)
        return 1 ;
    else
        return fibbonacci(userInput-1) + fibbonacci(userInput - 2) ;
}


int main()
{
    int myValue  ;
    myValue = fibbonacci(6) ;
    cout << myValue << endl;
    return 0;
}
