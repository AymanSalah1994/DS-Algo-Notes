#include <iostream>

using namespace std;

void mySwap(int &x, int &y)
{
    int temp ;
    temp = x ;
    x = y ;
    y  = temp ;
}


void InsertSort(int userInput[], int sizeOfTheArr)
{
    int i ;
    for (i = 1 ; i < sizeOfTheArr ; i++ )
    {
        /*
        Insertion Sort IS the opposite of the Bubble Sort in That :
        If we Break the Sort operation at any time We will Find that The LEFT side will be sorted ,
        But Right Side is Not !  [ Whether Ascending or Descending ]

        {
            In Bubble Sorting the Sorted Part is The Right Part , and Hence We Make the Enhancement
            For the Bubble Sort "Check Bubble-Enhance-1.cpp File"
        }

        Hence The outer Loop Works as the Following , at first we assume First Element is Sorted
        In Each Iteration In the Outer Loop We Focus on One Element from the Right Side (The Unsorted Part)
        So We Start with "i"  =  the Index of 1 , And Increase it  To get an Element from the Right Side
        , And In the inner loop we Make j Equal to "i"
        In other Words , Every time We take an Element From the NON-sorted Side "RIGHT"
        and In the Inner Loop We INSERT it in its proper place In the Left Side
        */


        int j = i ;
        while (j > 0  && userInput[j] > userInput[j-1])
        {
            // > Means If Our Inserted Number If Bigger Than the Once Before it Swap it
            // Is is Descending Sorting

            /*
            //In the Inner Loop , it is Similar to the Bubble Sort ,
            // We Keep Comparing and Swapping , Till we INSERT the Element In its proper
            // Place in the Sorted Side "LEFT side"
            */
            mySwap(userInput[j], userInput[j-1]) ;
            j-- ; // Till We Reach to Index 1 , And In this case we Compare arr[1] with arr[1-1]
        }
    }
}


int main()
{
    int myNumbers[10] = {4,54,56,23,768,3,0,12,11,4} ;
    //int myNumbers[10] = {411,57,5,26,76,5,667,4,1,44} ;
    InsertSort(myNumbers, 10) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
