#include <iostream>
#include <cstddef>
#include <cstring>
using namespace std;

struct node
{
    // Node Can Be A Class Or anything , It is The DataHolder in General
    int id  ;
    char name[25] ;
    node* next  ;
    node* prev  ;
};

class LinkedList
{
private :
    node* head  ;
    node* tail  ;

    node* searchByIdHidden(int searchID)
    {
        node* nodeHolder =  head  ;
        while (nodeHolder != NULL )
        {
            if ( nodeHolder->id == searchID )
            {
                return nodeHolder ;
            }
            nodeHolder = nodeHolder->next  ;
        }
        return NULL  ;
    }

    node* searchByNameHidden()
    {

    }

public :
    //CTOR
    LinkedList()
    {
        // To Avoid the Garbage Data
        // NULL or Zero , No problem
         tail = head = NULL ;
    }


    // Appending is From Tail , We Can Make another method to add From Head
    void append(int _id  , char _name[25])
    {
        node* temp = new node ; // Temp is the NEW NODE that we WANT to insert
        // If we Don't Use the new KeyWord  with "temp" Node We will lose all Node Data Once Method is Done
        // Stack will remove data
        temp->id = _id ;
        strcpy(temp->name , _name) ;
        temp->next = NULL ;
        temp->prev = NULL ;
        // NULLs Here are Just initial Values Before Determining the Pointers for next and Prev

        if (head == NULL)
        {
            // In Case this is the First Element
            head = tail = temp ;
        }

        else
        {
            // Append is To append From Tail
            // Tail always Refer to null , till we append new Element ,--
            // -- Then the New Element will be the tail , and the New Element will REFER to NULL ! and So on ..
           temp->prev = tail ;
           tail->next = temp ;
           tail = temp ; // This is Tail Itself , a Property for the LinkedList Object
        }
    } // End of Append Method


    void displayList()
    {
        node* nodeHolder =  head  ;
        while (nodeHolder != NULL )
        {
            cout<<nodeHolder->id<<"\t"<<nodeHolder->name<<"\n" ;
            nodeHolder = nodeHolder->next ;
        }
    } // End of Display Method

    void printCountOfNodes()
    {
        // Same as the Node Display
        node* nodeHolder =  head  ;
        int nodesCounter = 0 ;
        while (nodeHolder != NULL )
        {
            nodesCounter += 1  ;
            nodeHolder = nodeHolder->next ;
        }

        cout<<"The Number Of Elements is : " << nodesCounter << endl ;
    } // End of Counter Method

    node searchById( int searchedID )
    {
        node* nodePtr = searchByIdHidden(searchedID) ;
        if (nodePtr != NULL )
        {
            node nullifiedNode = *nodePtr ;
            nullifiedNode.next = NULL ;
            nullifiedNode.prev = NULL ;
            return nullifiedNode ;
        }
        else
        {
            node nullifiedNode ;
            nullifiedNode.id = -1  ;
            return nullifiedNode ;
        }

    }
    node* searchByName()
    {

    }

    void insertNode()
    {

    }

    void deleteById()
    {

    }

    void deleteByName()
    {

    }

};

int main()
{
    LinkedList myList ;
    myList.append(1,"Ayman") ;
    myList.append(2 ,"Ahmed") ;
    myList.displayList() ;
    myList.printCountOfNodes() ;
    node searchNode  = myList.searchById(1) ;
    cout<<searchNode.id  ;
    return 0;
}
