/*
Programmer: Ari Sherman 
Section: 1510 A
Date: 3/15/2017
Description: brain lab implement 
*/
#include <iostream>
using namespace std;
   
//clear function :)
template <class T> 
void LinkedListStack<T>::clear()
{
	Node<T>* tmp = m_head;  
	Node<T>* tmp2;
  while (tmp != NULL)
  {
    tmp2 = tmp -> m_next;  
    delete tmp;
    tmp = tmp2;
  }
  m_head = NULL;
  m_back = NULL;
  m_size = 0;
  return;
}

template <class T>
LinkedListStack<T>::LinkedListStack()
{
  m_head = NULL;
  m_back = NULL;
  m_size = 0;
}

template <class T>
const T& LinkedListStack<T>::top() const throw ( Oops )
{
  
    if (m_head == NULL)
      throw (Oops("I did it again"));
    return m_head -> m_data;
  
}

template <class T>
bool LinkedListStack<T>::isEmpty () const
{
  if (m_head==NULL)
    return true;
  else
    return false;
}

//insert front
template <class T>
void LinkedListStack<T>::push(const T& x)
{
   Node<T>* first = new Node<T>(x,m_head);
   m_head = first;
   if (m_size == 0)
     m_back = first;
   m_size++;
  return; 
   
}

//remove front...
template <class T>
void LinkedListStack<T>::pop() 
{
  	if (!isEmpty())
	{
  	Node<T>* tmp = m_head;
  	m_head = tmp ->m_next;
  	delete tmp;
  	if (isEmpty())
  		m_back = NULL;
  	m_size--;
	}
	return;
}

template <class T>
int LinkedListStack<T>::size() const
{
  return m_size;
}

template <typename T>                 
std::ostream& operator<< (std::ostream& out, const LinkedListStack<T>& list)
{
  int size = (list.size());
  out << size << ": " << endl;
  const Node<T>* tmp = list.getFirstPtr(); 
	for (int i = 0; i < size; i++)
	{
	  out << "member" << i+1 <<": " <<tmp -> m_data << endl;
	  tmp = tmp -> m_next;
	}
  
  return out;
}

template <class T>
LinkedListStack<T>::~LinkedListStack()
{
  clear();
} 

template <class T> 
const Node<T>* LinkedListStack<T>::getFirstPtr() const
{
  Node<T>* fPTR = m_head;
  return fPTR;
}




