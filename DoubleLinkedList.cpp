#include<iostream>
#include <string>
using namespace std;

class Node {
public:
    int noMhs;
    Node *next;
    Node *prev;
    
};

class DoubleLinkedList
{
private:
    Node *START;
    
public:
    DoubleLinkedList()
    {
        START = NULL;

    }

    void addnote()
    {
        int nim;
        string nm;
        cout << "/nEnter the roll number of the student: ";
        cin >> nim;

        //step 1: Allocate memory for new node 
        Node *newNode = new Node();

        //step 2: Assign vaalue to the data fields
        newNode->noMhs = nim;

        //step3 : insert at begining if list is empty or nim is smallest
        if (START == NULL || nim <= START->noMhs) 
        {
            if (START != NULL && nim == START->noMhs )
            {
                cout << "\nDuplicate number not allowed " << endl;
                return;
            }

            //step 4: newNode.next = start
            newNode->next = START;

            //step5 : START.prev = newNode (if START exits)
            if (START != NULL)
                START->prev = newNode;

            //step 6: newnode.prev = null
            newNode->prev = NULL;

            //step 7 : start = newnode
            START = newNode;
            return;

        }







    }
};