#pragma once

template <class T>
class Node
{
public:
	Node ();
	~Node ();
	Node<T>* const getNext () const;
	void setNext ( Node<T>* _next );
	const T& getContent () const;
	T& getContent ();
	void setContent ( const T& _content );

private:
	Node<T>* next;
	T content;
};

template <class T>
Node<T>::Node ()
	: next ( nullptr ), content ( T () )
{
}

template <class T>
Node<T>::~Node ()
{
}

template <class T>
void Node<T>::setNext ( Node* _nextNode )
{
	next = _nextNode;
}

template <class T>
Node<T>* const Node<T>::getNext () const
{
	return next;
}


template <class T>
void Node<T>::setContent ( const T& _content )
{
	content = _content;
}

template <class T>
T& Node<T>::getContent ()
{
	return content;
}


template <class T>
const T& Node<T>::getContent () const
{
	return content;
}


