//
//  LinkedList.h
//  LinkedList
//
//  Created by Erik Lysne on 25.09.2017.
//  Copyright © 2017 Erik Lysne. All rights reserved.
//

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>



// -------------------------------------
// --------- LINKED LIST CLASS ---------
// -------------------------------------

template <typename T>
class LinkedList
{
public:
    LinkedList();           // default constructor
    
    void pushFront(T);      // push (add) element to front
    void popFront();        // pop (remove) element from front
    void pushBack(T);       // push (add) element to back
    void popBack();         // pop (remove) element from front
    void sort();            // sort content of list using insertion sort
    void printContent();    // print content of linked list
    
private:

    struct Node             // nested class
    {
        Node* nextNode;     // pointer to next node
        Node* prevNode;     // pointer to prev node
        T data;             // content of node
        
        Node(T val) : data(val) {};         // constructor with data assignment
        Node() : data() {};                 // default constructor
        Node& operator= (const Node& rVal); // overloaded assignment operator
    };
    
    Node* p_firstNode;   // pointer to first sentinel node
    Node* p_lastNode;    // pointer to last sentinel node

};

// -------------------------------------
// ---------- MEMBER FUNCTIONS ---------
// -------------------------------------

template <typename T>
LinkedList<T>::LinkedList() :
p_firstNode(new Node()),
p_lastNode(new Node())
{
    p_firstNode->nextNode = p_lastNode;
    p_firstNode->prevNode = NULL;
    
    p_lastNode->nextNode = NULL;
    p_lastNode->prevNode = p_firstNode;
}

template <typename T>
void LinkedList<T>::pushFront(T newData)
{
    Node* newNode = new Node(newData);
    
    newNode->nextNode = p_firstNode->nextNode;
    newNode->prevNode = p_firstNode;
    p_firstNode->nextNode->prevNode = newNode;
    p_firstNode->nextNode = newNode;
}

template <typename T>
void LinkedList<T>::popFront()
{
    Node* popNode = p_firstNode->nextNode;
    
    popNode->nextNode->prevNode = p_firstNode;
    p_firstNode->nextNode = popNode->nextNode;
    
    delete popNode;
}

template <typename T>
void LinkedList<T>::pushBack(T newData)
{
    Node* newNode = new Node(newData);
    
    newNode->nextNode = p_lastNode;
    newNode->prevNode = p_lastNode->prevNode;
    p_lastNode->prevNode->nextNode = newNode;
    p_lastNode->prevNode = newNode;
}

template <typename T>
void LinkedList<T>::popBack()
{
    Node* popNode = p_lastNode->prevNode;
    
    popNode->prevNode->nextNode = p_lastNode;
    p_lastNode->prevNode = popNode->prevNode;
    
    delete popNode;
}

template <typename T>
void LinkedList<T>::printContent()
{
    Node* iterator = p_firstNode->nextNode;
    while(iterator != p_lastNode)
    {
        std::cout << "Address: " << iterator << ", Data: "<< iterator->data << std::endl;
        iterator = iterator->nextNode;
    }
}

template <typename T>
void LinkedList<T>::sort()
{
    Node* iterRemove = p_firstNode->nextNode->nextNode;
    Node* iterInsert = iterRemove->prevNode;
    T insertionData;
    
    while(iterRemove != p_lastNode)
    {
        insertionData = iterRemove->data;
        while(iterInsert->data > insertionData && iterInsert != p_firstNode)
        {
            iterInsert->nextNode->data = iterInsert->data;
            iterInsert = iterInsert->prevNode;

        }
        iterInsert->nextNode->data = insertionData;
        
        iterRemove = iterRemove->nextNode;
        iterInsert = iterRemove->prevNode;
        
    }
}

template <typename T>
typename LinkedList<T>::Node& LinkedList<T>::Node::operator= (const Node& rVal)
{
    if(&rVal == this)
        return *this;
    
    prevNode = rVal.prevNode;
    nextNode = rVal.nextNode;
    data = rVal.data;
    
    return *this;
}

#endif /* LinkedList_h */
