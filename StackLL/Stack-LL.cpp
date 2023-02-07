#include <iostream>
#include <stddef.h>
#include <cstring>
using namespace std;


struct node
{
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

public :
    LinkedList()
    {
        head = NULL ;
        tail = NULL ;
    }
    void appendFromHead(int _id, char _name[25])
    {
        // TODO : Check If Ram is Full !

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
            node* tem = new node ;
            tem = head ;
            tem->prev = temp ; // temp is the New One To Be the Head
            head = temp ;
            temp->next = tem ;
        }
    }



    int deleteFromHead(node* theDeletedNodeHolder)
    {
        if (head == NULL)
        {
            //cout<<"There is Not Remaining Elements "<<endl  ;
            return 0  ;
        }
        else
        {
            node* holder  = new node ;
            holder  = head ;
            theDeletedNodeHolder->id  = holder->id ;
            strcpy(theDeletedNodeHolder->name, holder->name) ;
            head = head->next ;
            delete holder ;
            return 1  ;
        }
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

};



class StackLL
{
    LinkedList stackList ;

public :

    void push(int _id, char _name[25])
    {
        stackList.appendFromHead(_id, _name) ;
    }


    int pop(node* resultHolder)
    {
        int result ;
        result  = stackList.deleteFromHead(resultHolder) ;
        return result ;
    }
};





int main()
{
    StackLL myLinkedStack ;
    node* generalDataHolder = new node ;

    myLinkedStack.push(45,"Samy") ;
    myLinkedStack.push(45,"Ahmed") ;
    myLinkedStack.push(45,"Ali") ;
    myLinkedStack.push(45,"DOOMAi") ;
    myLinkedStack.pop(generalDataHolder)  ;
    myLinkedStack.pop(generalDataHolder)  ;
    myLinkedStack.pop(generalDataHolder)  ;
    // To Check if the Stack is Empty you Have to assign another variable to get the Result from the function ;
    cout<<generalDataHolder->id<<":"<<generalDataHolder->name<<endl ;

    return 0;
}


