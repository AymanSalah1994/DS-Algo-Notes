#include <iostream>
using namespace std;

void mySwap(int &x, int &y)
{
    // This is a Normal Swapping Function that we will Use !
    int temp ;
    temp = x ;
    x = y ;
    y = temp ;
}


/*
- First Of All , If you Want to Get Quick Sort ,
 Try to Understand the "First" Iteration that happens , and Build On it .

- Pivot :: If you Fold a Paper from the middle , this middle point is a pivot , Remember that to grasp the idea
*/

int partitionFunction(int myArr[], int startIndex, int endIndex )
{

    int pivotIndex  = startIndex ;
    // Now i will implement the Quick sort Using start index as Pivot


    int i  = endIndex + 1 ; // Get out of Range
    for (int j = endIndex ; j > startIndex ; j-- )
    {
        if (myArr[j] > myArr[pivotIndex])
        {
            i-- ;
            mySwap(myArr[i] , myArr[j]) ;
        }
    }
    mySwap(myArr[i-1] , myArr[startIndex]) ;
    return i-1 ; // Return the New Index of the Pivot
}


void QSort(int userArray[], int theStart, int theEnd  )
{
    /*
    This is the Starting Point , We Get an Array and its Edges  ;
    Edges = Start Index and End Index
    */
    if (theStart >= theEnd)
        return ;
        /*
        // This Condition Means no need to Call Quick Sort anymore
        // Everything is Sorted
        // IF Start equals End this means there is ONLY one element in the array (ie sorted )
        // If Start is Bigger than end , it can't be handled
        // OtherWise We will Take this array and Its Edges "Start and End "
        // And we will send them ALL to another Function , this another function will Do the Following
        1-Determine the Pivot [ Start pivot Or End Pivot ]
        2-Making a loop , with the Help of swapping to put
        the elements less than pivot  on the left side and elements greater than pivot on the right side of the pivot.
        // NOTE : Whether pivot is Last Element or pivot is First Element We will Try to Always put smalls on Left
        // And put the Bigs on the Right !

        3-After this little arrangement , We swap the pivot to be between Smalls and Bigs
         [ Get last index where there was a swapping and Put the Pivot after it ]

         4-Finally return the new index of the pivot to Quick Sort function
         5-Quick sort function will use Recursion and pivot index to determine the new Edges
        */
    int iPivotIndex  = partitionFunction(userArray, theStart, theEnd) ;
    QSort(userArray, theStart, iPivotIndex - 1 ) ; // Recursion
    QSort(userArray, iPivotIndex + 1, theEnd) ; // Recursion with partial piece of the array
}

int main()
{
    //int myNumbers[10] = {4,54,56,23,768,3,0,12,11,4} ;
    int myNumbers[10] = {411,57,5,26,76,5,667,4,1,44} ;
    //int myNumbers[10] = {99,77,23,34,0,55,7,55,11,9} ;
    QSort(myNumbers, 0, 9) ;
    int u  ;
    for (u = 0  ; u< 10 ; u++)
    {
        cout<<myNumbers[u]<<"\t" ;
    }
    cout<<endl ;
    return 0;
}
