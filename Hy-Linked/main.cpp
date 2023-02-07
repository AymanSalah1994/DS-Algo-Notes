#include <iostream>
#include <stddef.h>
#include <cstring>
using namespace std;

struct node
{
    // This is the Node that Represent Data , We Can Use Struct Or Class , Does NOT matter
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

    node* searchByNameHidden(char searchName[25])
    {
        node* nodeHolder =  head  ;
        while (nodeHolder != NULL )
        {
            if ( strcmp(searchName, nodeHolder->name) == 0  )
            {
                return nodeHolder ;
            }
            nodeHolder = nodeHolder->next  ;
        }
        return NULL  ;
    }

public :
    LinkedList()
    {
        head = NULL ;
        tail = NULL ;
    }

    node* exposeTheHead()
    {
        return head;
    }

    void append(int _id, char _name[25])
    {
        node* temp = new node ;
        temp->id = _id ;
        strcpy(temp->name, _name) ;
        temp->next = NULL ;
        temp->prev = NULL ;

        if (head == NULL)
        {
            head = temp ;
            tail = temp ;
        }

        else
        {
            temp->prev = tail ;
            tail->next = temp ;
            tail = temp ;
        }
    }


    void displayList()
    {
        node* nodeHolder =  head  ;
        while (nodeHolder != NULL )
        {
            cout << nodeHolder->id << "\t" << nodeHolder->name <<"\n" ;
            nodeHolder = nodeHolder->next ;
        }

    }

    void printCountOfNodes()
    {
        //
        node* nodeHolder =  head  ;
        int nodesCounter = 0 ;
        while (nodeHolder != NULL )
        {
            nodesCounter += 1  ;
            nodeHolder = nodeHolder->next ;
        }

        cout<<"The Number Of Elements is : " << nodesCounter << endl ;
    }



    int CountOfNodes()
    {
        node* nodeHolder =  head  ;
        int nodesCounter = 0 ;
        while (nodeHolder != NULL )
        {
            nodesCounter += 1  ;
            nodeHolder = nodeHolder->next ;
        }

        return nodesCounter ;
    }


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
    node searchByName( char searchName[25])
    {
        node* nodePtr = searchByNameHidden(searchName) ;
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
            strcpy(nullifiedNode.name, "") ;
            return nullifiedNode ;
        }
    }

    void insertNodeBeforeID(int id, int _nodeID, char _nodeName[25])
    {
        // insert Before ID , Here We Check Only the Head
        // It will Be Before Some Certain ID , Since there is No Criteria
        node* positionNodePtr = searchByIdHidden(id) ;
        node* insertedNode = new node ;
        insertedNode->id  = _nodeID ;
        strcpy(insertedNode->name, _nodeName) ;
        if ( positionNodePtr == head )
        {
            head = insertedNode ;
            insertedNode->prev = NULL ;
            insertedNode->next = positionNodePtr ;
            positionNodePtr->prev = insertedNode ;
        }
        else
            // I will Not check the tail Since it is Always Insert Before
        {
            insertedNode->next = positionNodePtr ;
            insertedNode->prev = positionNodePtr->prev ;
            positionNodePtr->prev->next = insertedNode ;
            positionNodePtr->prev = insertedNode ;

        }

    }

    void deleteById(int deletedID)
    {
        int theNubmer  = CountOfNodes() ;

        node* deletedNode = searchByIdHidden(deletedID) ;
        if (deletedNode == tail)
        {
            tail = deletedNode->prev ;
            delete deletedNode  ;
            return ;
        }
        if (deletedNode == head)
        {
            head = deletedNode->next  ;
            delete deletedNode  ;
            return ;
        }


        if (theNubmer > 2 )
        {
            node* deletedNode = searchByIdHidden(deletedID) ;
            deletedNode->prev->next = deletedNode->next ;
            deletedNode->next->prev = deletedNode->prev ;
            delete deletedNode ;
        }

        else if (theNubmer == 2)
        {
            node* deletedNode = searchByIdHidden(deletedID) ;
            tail  = deletedNode->prev ;
            head = deletedNode->prev ;
            delete deletedNode ;
        }
        else if (theNubmer == 1 )
        {
            tail = NULL ;
            head = NULL ;
        }
    }

    void deleteByName(char deleteName[25])
    {
        int theNubmer  = CountOfNodes() ;
        node* deletedNode = searchByNameHidden(deleteName) ;
        if (tail == deletedNode)
        {
            tail = deletedNode->prev ;
            delete deletedNode  ;
            return ;
        }
        if (head == deletedNode)
        {
            head = deletedNode->next  ;
            delete deletedNode  ;
            return ;
        }


        if (theNubmer > 2 )
        {
            node* deletedNode = searchByNameHidden(deleteName) ;
            deletedNode->prev->next = deletedNode->next ;
            deletedNode->next->prev = deletedNode->prev ;
            delete deletedNode ;
        }

        else if (theNubmer == 2)
        {
            node* deletedNode = searchByNameHidden(deleteName) ;
            tail  = deletedNode->prev ;
            head = deletedNode->prev ;
            delete deletedNode ;
        }
        else if (theNubmer == 1 )
        {
            tail = NULL ;
            head = NULL ;
            delete deletedNode ;
        }
    }

};



void insertFromTails(int functionID, char functionName[25], node* myLinkedListArray[26])
{
    int matchingAsciiArray[26] ;
    int i  = 0  ;
    int stater = 65 ;
    for (i  = 0  ; i<26 ; i++)
    {
        matchingAsciiArray[i] = stater ;
        stater += 1 ;
    }
    //cout<<"Last Starter = "<<stater<<endl ;
    //cout<<"Last Element in the Array = " <<matchingAsciiArray[25] <<endl;
    //char ch = static_cast<char>(stater-1);
    //cout<<"Trying the Casting : "<<ch<<endl ;

    ////// Now We Made the Matching array and the Array of HEADS
    //int inputId  = 19 ;
    //char inputName[25] = "gamal" ;
    //int firstCharAsInt =  toupper(inputName[0]) ; // To upper will get me an int
    //cout<<"Here is the First Character Capitalized : "<< firstCharAsInt <<endl ;

    // Insertion Simulation
    // Of Course This is One Time Simulation But Later All Will be Wrapped in a Function
    // Or a Block For Repetition

    // 1- Check First Character in User input
    // Get its index in the array
    // Match the index in the Head array
    //Do the Append of this Element
    // Return Where did the Algorithm
    node* hybridNode = new node ;
    hybridNode->id = functionID ;
    strcpy(hybridNode->name, functionName) ;
    int firstCharAsInt =  toupper(functionName[0]) ;
    int index   ;
    for (index = 0 ; index < 26  ; index++)
    {
        if (matchingAsciiArray[index] == firstCharAsInt)
        {
            cout<<"Found the index : "<<index<<endl ;
            break ;
            // Now We Have the Matching index of the Matching Character
        }
    }


    if (myLinkedListArray[index] == NULL )
    {
        LinkedList newLinObj ;
        newLinObj.append(functionID,functionName) ; // If First Element We will Append First
        myLinkedListArray[index] = newLinObj.exposeTheHead() ;
    }

    else
    {
        cout<<"Head is  Not null"<<endl ;
        node* temp=  new node ;
        temp->id = functionID ;
        strcpy(temp->name,functionName) ;
        temp->next = NULL ;
        node* nodeHolder =  myLinkedListArray[index]  ;
        while (true)
        {
            if (nodeHolder->next == NULL)
            {
                nodeHolder->next = temp ;
                break ;
            }
            else {
                nodeHolder = nodeHolder->next ;
                continue ;
            }
        }
    }
    cout<<"Inserted Name at Head Always Fixed : "<<myLinkedListArray[index]->name<<endl ;



    // Displaying the Dictionary
    int xyz = 0   ;
    while (xyz<26 )
    {
        if (myLinkedListArray[xyz] == NULL)
        {
            cout<<"Empty Dictionary"<<endl ;
        }
        else
        {
            node* tempForHead = new node ;
            tempForHead = myLinkedListArray[xyz];
            cout<<tempForHead->name<<"\t" ;
            while(tempForHead->next)
            {
                tempForHead = tempForHead->next ;
                cout<<tempForHead->name<<"\t" ;
            }
            cout<<"\n" ;
        }
        xyz++ ;
    }
}




int main()
{
    node* myLinkedListArray[26] ;

    int j  = 0 ;
    for (j ; j<26 ; j++)
    {
        // Nullify It
        myLinkedListArray[j] = NULL ;
    }


    insertFromTails(34,"Ali",myLinkedListArray) ;
    insertFromTails(1,"Ayman",myLinkedListArray) ;
    insertFromTails(1,"Khaled",myLinkedListArray) ;
    insertFromTails(2,"Zego", myLinkedListArray) ;
    insertFromTails(2,"Ahmed", myLinkedListArray) ;


    return 0;
}


