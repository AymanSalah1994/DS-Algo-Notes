#include <iostream>

using namespace std;

void mySwap(int &x, int &y)
{
    int temp;
    temp = x;
    x = y;
    y = temp;
}

void mySelectionSort(int userInput[], int sizeOfTheArr)
{
    int i  ;
    for (i = 0  ; i < sizeOfTheArr ; i++)
    {
        int minimumIndex = i  ; // Its Proper Name Should Be [ NextMinimumIndex OR NextMaximumIndex ]
        int j = i+1 ;
        for (j ; j < sizeOfTheArr ; j++)
        {
            if (userInput[j] < userInput[minimumIndex])
            {
                // In the Above Comparison it is Like Asking :
                // IS there any item After the item at minimumIndex Which has a Smaller Value ?
                // In other Words it is putting smalls First
                mySwap(userInput[j], userInput[minimumIndex]) ;
            }
        }
    }
}

int main()
{
    //int myNumbers[10] = {4,54,56,23,768,3,0,12,11,4} ;
    int myNumbers[10] = {3452,656,7,6,5,4,3,2,1324,330} ;
    mySelectionSort(myNumbers, 10) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
