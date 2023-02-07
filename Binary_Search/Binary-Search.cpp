#include <iostream>
#include<string.h>

using namespace std;



int binarySearchingForString(string userArray[],int theRealSize, string keyValue )
{
    int startIndex = 0  ;
    int endIndex = theRealSize - 1  ;
    int middleIndex = (startIndex + endIndex) / 2 ;
    int keyIndex = -1    ; // Index with Default
    while (startIndex<=endIndex)
    {
        int iteration  = 1  ;
        cout<<"Iteration Number : "<< iteration<<endl ;
        iteration++ ;
        cout<<startIndex<<"\t"<<middleIndex<<"\t"<<endIndex<<endl ;
        if (userArray[middleIndex] == keyValue)
        {
            keyIndex = middleIndex ;
            break ;
        }

        else
        {
            if (userArray[middleIndex] > keyValue)
            {
                endIndex = middleIndex - 1  ;
                middleIndex = (startIndex + endIndex) / 2  ;
                continue ;

            }
            else if (userArray[middleIndex] < keyValue)
            {
                startIndex = middleIndex +1;
                middleIndex = (startIndex + endIndex) / 2  ;
                continue ;
            }
        }

    }
    cout<<"The index of the Value is : "<<keyIndex<<endl ;
}

int binarySearching(int userArray[],int theRealSize, int keyValue )
{
    int startIndex = 0  ;
    int endIndex = theRealSize - 1  ;
    int middleIndex = (startIndex + endIndex) / 2 ;
    int keyIndex = -1    ; // Index with Default
    while (startIndex<=endIndex)
    {
        int iteration  = 1  ;
        cout<<"Iteration Number : "<< iteration<<endl ;
        iteration++ ;
        cout<<startIndex<<"\t"<<middleIndex<<"\t"<<endIndex<<endl ;
        if (userArray[middleIndex] == keyValue)
        {
            keyIndex = middleIndex ;
            break ;
        }

        else
        {
            if (userArray[middleIndex] > keyValue)
            {
                endIndex = middleIndex - 1  ;
                middleIndex = (startIndex + endIndex) / 2  ;
                continue ;

            }
            else if (userArray[middleIndex] < keyValue)
            {
                startIndex = middleIndex +1;
                middleIndex = (startIndex + endIndex) / 2  ;
                continue ;
            }
        }

    }
    cout<<"The index of the Value is : "<<keyIndex<<endl ;
}

int main()
{
    int mySortedArray[12]  = {3,4,5,7,12,33,43,55,67,79,88,99};
    string sortedNames[5] = {"Ayman" , "Baher" , "Kamal" , "Samy" , "Zyad"} ;
   // binarySearching(mySortedArray, 12, 33) ;
    binarySearchingForString(sortedNames , 5 , "Ali") ;
    binarySearchingForString(sortedNames , 5 , "Zyad") ;
    return 0;
}
