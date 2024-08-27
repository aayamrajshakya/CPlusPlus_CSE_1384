/*
Name: Aayam Shakya          NetID: as5160
Date: 14 April 2023         Due Date: 14 April 2023
Description: This program implements a linked list to store book titles and authors.
            The program reads a list of books and authors from a file called "books.txt" 
            and stores them in the linked list. The program then performs several operations
            on the linked list, such as inserting and removing nodes, and displays the linked 
            list after each operation. The program consists of 5 files: "main.cpp", "books.txt",
            "linkedlist.h", "linkedlist.cpp", and "node.h". This is the "linkedlist.cpp" file that contains the
            implementation of the LinkedList class and its member functions.
            The LinkedList class has member functions like append(), pop(), display(), and insert(), remove(), view().

*/

#include "linkedlist.h"

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

LinkedList::~LinkedList()
{
    if(size > 0)
    {
        Node *temp;

        while(head != nullptr)
        {
            // grabs the node after the head
            temp = head->next;

            // deletes the head
            delete head;

            // reassigns the head
            head = temp;
        }
    }
}

// ***************************************************
// GIVEN TO STUDENTS
// ***************************************************

void LinkedList::append(string title, string author)
{
    // if the list is currently empty
    if(size == 0)
    {
        // create a new node at the head
        // with the information brought in
        head = new Node(title, author);

        // assigns tail to the head
        tail = head;
    }

    // otherwise, if it's not empty
    else
    {
        // creates a new node
        // with the information brought in
        Node *temp = new Node(title, author);

        // point current tail to new node
        tail->next = temp;

        // make new node the new tail
        tail = temp;
    }

    size++;
}

int LinkedList::pop()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- pop failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // if removing a node will empty the list
    if(size == 1)
    {
        // store current head
        Node *temp = head;

        // sanity check clear head and tail
        head = nullptr;
        tail = nullptr;

        // delete node
        delete temp;
    }

    // otherwise, if it won't
    else
    {
        // start a temporary node at the head
        Node *temp = head;

        // loop to one before the tail
        while(temp->next->next != nullptr)
        {
            temp = temp->next;
        }

        // delete the current tail
        delete tail;

        // sanity check clear the next pointer
        // and assign the new tail
        tail = temp;
        tail->next = nullptr;
    }

    size--;

    return 0;
}

int LinkedList::display()
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- display failed!" << endl;
        return 1; // exits from the function with fail flag
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;
    int count = 0;

    while(temp != nullptr)
    {
        // displays information
        cout << "Book " << count << ": ";
        cout << temp->title << " by " << temp->author << endl;

        // moves the temp node to the next node in the sequence
        temp = temp->next;

        count++;
    }

    return 0;
}

// ***************************************************
// END GIVEN TO STUDENTS
// ***************************************************


int LinkedList::insert(string title, string author, int position)
{
    // error check:
    // checks if the position is out of range
    if(position < 0 || position > size)
    {
        cout << "Not a valid insert -- out of range!" << endl;
        return 1; // exits from the function with fail flag
    }

    // if inserting at the head
    if(position == 0)
    {
        // create a new node with the information brought in
        Node *temp = new Node(title, author);

        // link the new node to the current head
        temp->next = head;

        // reassign head to the new node
        head = temp;

        // if the list was previously empty, update the tail as well
        if(size == 0)
        {
            tail = temp;
        }
    }

    // if inserting at the tail of the list
    else if(position == size)
    {
        // create a new node at the tail
        // with the information brought in
        Node *temp = new Node(title, author);

        // point the next pointer of the current tail to the new node
        tail->next = temp;

        // update the tail to point to the new node
        tail = temp;
    }

    // otherwise, inserting in the middle of the list
    else
    {
        // start a temporary node at the head
        Node *temp = head;

        // loop to the node before the insertion point
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }

        // create a new node at the insertion point
        Node *newNode = new Node(title, author);

        // update the next pointer of the new node to the next node in the sequence
        newNode->next = temp->next;

        // update the next pointer of the previous node to the new node
        temp->next = newNode;
    }

    size++;

    return 0;
}


int LinkedList::remove(int position)
{
    // error check:
    // checks if the current size is zero
    if(size == 0)
    {
        cout << "List was empty -- remove failed!" << endl;
        return 1; // exits from the function with fail flag
    }
    
    // error check:
    // checks if the given position is out of range
    if(position < 0 || position >= size)
    {
        cout << "Not a valid remove - out of range!" << endl;
        return 1; // exits from the function with fail flag
    }
    
    // if removing the head node
    if(position == 0)
    {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    // if removing a non-head node
    else
    {
        Node* temp = head;
        
        // loop to the node before the one to remove
        for(int i = 0; i < position - 1; i++)
        {
            temp = temp->next;
        }
        
        Node* to_remove = temp->next;
        temp->next = to_remove->next;
        
        // if removing the tail node
        if(position == size - 1)
        {
            tail = temp;
        }
        
        delete to_remove;
    }
    
    size--;
    return 0;
}




int LinkedList::view(int position)
{
    // error check:
    // checks if the position is out of range
    if(position < 0 || position >= size)
    {
        cout << "Not a valid view -- out of range!" << endl;
        return 1; // exits from the function with fail flag
    }

    // starts temporary Node at the beginning (head)
    Node *temp = head;

    // moves temp to the desired node
    for(int i = 0; i < position; i++)
    {
        temp = temp->next;
    }

    // displays information
    cout << temp->title << " by " << temp->author << endl;

    return 0;
}

