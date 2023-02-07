#include <iostream>

using namespace std;

int factorial(int userInput)
{
    // Recursion Rules :
    // First Of All
    if (userInput == 1 )
        return 1 ;
    else
        return factorial(userInput - 1 ) * userInput ;
}


int main()
{
    cout << factorial(3)<< endl;
    return 0;
}
