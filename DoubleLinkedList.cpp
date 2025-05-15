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

    void traverse ()
    {
        if (START == NULL)
        {
            cout << "\nList is empty " << endl;
            return;
        }

        //step 1: Mark first node as currentNode 
        Node *currentNode = START;
        //step 2: Repeat until currentNode == NULL
        cout << "\nRecords in ascending order of roll number are:\n ";
        int i=0;
        while (currentNode != NULL)
        {
            cout << i+1 <<"." << currentNode->noMhs << endl;
            //step 3: Move to next node 
            currentNode = currentNode->next;
            i++;
        }
  
    void revtraverse()
    {
        
     if (START == NULL)
     {
      cout << " \nList is empty " << endl;
      return;
     }
        
     //step 1: Move to last node
     Node *currentNode = START;
     int i= 0;
     while (currentNode->next != NULL)
    {
     currentNode = currentNode->next;
      i++;
    }
            
     //step 2: Traverse backward
     cout << "\nRecords in descending order of roll number are:\n";
     while (currentNode != NULL)
    }
       cout << i + 1 << "." << currentNode->noMhs <<"." << endl;
      //step 3 : Move to previous node 
      currentNode = currentNode->prev;
      i--;  
        
        
        
    
    }

    void search()
    {
        if (START == NULL)
        {
            cout << "\nList is empty " << endl;
            return;
        }

        int rollNo;
        cout << "\nEnter the roll number of the student to be searched: ";
        cin >> rollNo;

        Node *current = START;

        //step 1: Traverse to find matching roll number 
        while (current != NULL && current->noMhs != rollNo)
            current = current->next;

        //step 2:Output result 
        if (current == NULL)
        {
            cout << "Record not found " << endl;
        }
        else
        {
            cout << "Record not found\n ";
            cout << "Roll Number : " << current->noMhs << endl;

        }
    }

};

int main()
{
    DoubleLinkedList List;
    char choice;
    
    do
    {
        cout << "\nMenu:\n";
        cout << "1. Add Reccord\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending\n";
        cout << "4. View Descending\n";
        cout << "5. Search Reccord\n";
        cout << "6. Enter your choice: ";

        cin >> choice;

             switch (choice){
            case '1':
                list.addNode();
                break;
            case '2':
                list.hapus();
                break;
            case '3':
                list.traverse();
                break;
            case '4':
                list.revtraverse();
                break;
            case '5':
                list.searchData();
                break;
            case '6':
                return 0;
            default:
                cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');

        
    
    
}


