#pragma once
#include "Node.h"

namespace TestLinkedList
{
  class LinkedListTest_PROF;
}

template <typename T>
class DataStructure
{
public:
  DataStructure ();
  DataStructure ( const DataStructure<T>& src );
  virtual ~DataStructure ();
  virtual unsigned int size () const;
  bool isEmpty () const;

protected:
  const Node<T>* getFirstNode () const;
  Node<T>* getFirstNode ();
  void setFirstNode ( Node<T>* node );

private:
  Node<T>* firstNode;
  friend class TestLinkedList::LinkedListTest_PROF;
};

template <typename T>
DataStructure<T>::DataStructure ()
  : firstNode ( nullptr )
{
}

template <typename T>
DataStructure<T>::DataStructure ( const DataStructure<T>& /*src*/ )
  : firstNode ( nullptr )
{
}

template <typename T>
DataStructure<T>::~DataStructure ()
{
}

template <typename T>
unsigned int DataStructure<T>::size () const
{
  const Node<T>* current = getFirstNode ();
  unsigned int count = 0;
  while (current != NULL)
  {
    count++;
    current = current->getNext ();
  }
  return count;
}

template <typename T>
void DataStructure<T>::setFirstNode ( Node<T>* node )
{
  this->firstNode = node;
}

template <typename T>
const Node<T>* DataStructure<T>::getFirstNode () const
{
  return this->firstNode;
}

template <typename T>
Node<T>* DataStructure<T>::getFirstNode ()
{
  return this->firstNode;
}

template <typename T>
bool DataStructure<T>::isEmpty () const
{
  return (0 == size ());
}
