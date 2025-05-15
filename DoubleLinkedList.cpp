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

        //isert in between node
        //step 8 : locate position fo insertion
        Node *current = START;
        while (current->next != NULL && current->next->noMhs)
        {
            cout << "\Duplicate roll numbers not allowed " << endl;
            return;
        }
        //step9 : insert between current and current->next
        newNode->next = current->next; //step 9a:newNode.next = current 
        newNode->prev = current; //step 9b:newNode.prev = current 

        //insert last node 
        if (current->next != NULL)
            current->next->prev = newNode; //step 9c:current.next.prev = newNod
        current->next = newNode; //step 9d:current.next = newNode

    }
    void hapus()
    {
        if (START == NULL)
        {
            cout << "\nList is empty " << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        Node *current = START;

        //step 1: Traverse the list to find the node
        while (current != NULL && current->noMhs !=rollNo)
            current = current->next;

        if (current == NULL)
        {
            cout << "Reccord not found " << endl;
            return;
        }

        //step 2: if node is at the beginning 
        if (current == START)
        {
            START = current->next; // step 2a: START = START.next
                START->prev = NULL;  // step 2b: START = START.prev
        }

        else
        {
            // step 3 : Link previos node to next of current 
            current->prev->next = current->next;

            //step4 : if current is not the last node 
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        //step 5: delete the node
        delete current;
        cout << "Record with the roll number " << rollNo << "deleted " << endl;
    }




};


