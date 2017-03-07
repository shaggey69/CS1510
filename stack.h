/*
Programmer: Ari Sherman 
Section: 1510 A
Date: 3/15/2017
Description: brain lab implement 
*/
#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "abstractstack.h"
using namespace std;

// --------------- Class Node ---------------
template <class T>
class Node
{
public:
  T m_data;            // Data to be stored
  Node<T>* m_next;     // Pointer to the next element in the list


  // Purpose: Default constructor
  // Postconditions: next pointer set to NULL
  // ---INLINE---
  Node() : m_next(NULL) {}

  // Purpose: Auxiliaty constructor, construct from parameters
  // Postconditions: data and next pointer set to parameters
  // ---INLINE---
  Node(const T& x, Node<T>* p) 
             : m_data(x), m_next(p) {}

};


// --------------- Class LinkedList ---------------
template <class T>
class LinkedListStack : public AbstractStack<T>
{
 
  Node<T>* m_head;     // Pointer to the head of the list
  Node<T>* m_back;     // Pointer to the back of the list
  int m_size;          // The number of elements in the list
  
public:
  
  // Purpose: Default constructor
  // Postconditions: this list represents the empty list
  LinkedListStack();


  // Purpose: Destructor
  ~LinkedListStack();
  
                             //specification
  const T& top() const throw (Oops);
  
  bool isEmpty();
  
  void push(const T& x);
  
  void pop();
  
  void clear();
  
  int size() const;

            
};

template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedListStack<T>& list);
#include "stack.hpp"

#endif
