#include <iostream>
#include<string.h>
using namespace std;

struct node
{
    int id  ;
    char name[25] ;
    node* next  ;
};

class Queue
    {
        node* rearQ ;
        node* frontQ ;
    public :
        Queue()
        {
            rearQ = NULL ;
            frontQ = NULL ;
        }

        void enqU(int _id, char _name[25] )
        {
            node* temporary = new node ;
            if (temporary == NULL)
            {
                cout<<"RAM has No Space !" <<endl ;
                return  ;
            }
            else
            {
                temporary->id = _id ;
                strcpy(temporary->name , _name) ;
                temporary->next = NULL ;
                if (frontQ == NULL)
                {
                    frontQ = rearQ = temporary;
                    // ?????????????? = NULL No Need
                }
                else
                {
                    temporary->next = rearQ ;
                    rearQ = temporary ;
                }
            }
        }

        int deqU(node* userNodeHolder)
        {
            if (frontQ == NULL)
            {
                cout<<"No One In Q in Front of Me , Empty queue !"<<endl ;
                return 0;
            }
            else
            {
                node* temporary  = new node ;
                temporary = frontQ ;
                userNodeHolder->id = temporary->id  ;
                strcpy(userNodeHolder->name, temporary->name) ;
                // nullify later
                frontQ = frontQ->next ;
                delete temporary ;
            }
        }
    };

int main()
{
    Queue oo ;
    oo.enqU(1,"Ayman") ;
    oo.enqU(2,"Aan") ;
    oo.enqU(3,"Ayn") ;
    node* myResult = new node ;
    oo.deqU(myResult) ;
    cout<<myResult->id<<":"<<myResult->name<<endl ;
    oo.deqU(myResult) ;
    cout<<myResult->id<<":"<<myResult->name<<endl ;
    return 0;
}
