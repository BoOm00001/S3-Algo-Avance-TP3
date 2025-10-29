#pragma once

#include "DataStructure.h"
#include <stdexcept>
namespace TestLinkedList
{
  class LinkedListTest_PROF;
}

template <class T>
class LinkedList : public DataStructure<T>
{
public:
  LinkedList ();
  LinkedList ( const LinkedList<T>& src );
  ~LinkedList ();
  bool contains ( const T& content ) const;
  void add ( const T& content );
  void remove ( const T& content );
  void clear ();
  const T& get ( unsigned int index ) const;
  virtual unsigned int size () const override;
  template <class U>
  friend bool operator==( const LinkedList<U>& lhs, const LinkedList<U>& rhs );
private:
  const Node<T>* getLastNode () const;
  Node<T>* getLastNode ();
  friend class TestLinkedList::LinkedListTest_PROF;



};










template <class T>
LinkedList<T>::LinkedList()
{
    this->setFirstNode(nullptr);
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T>& src)
{
    this->setFirstNode(nullptr); 
    const Node<T>* current = src.getFirstNode();
    while (current)
    {
        add(current->getContent());
        current = current->getNext();
    }
}

template <class T>
LinkedList<T>::~LinkedList()
{
    
    clear();
}

template <class T>
bool LinkedList<T>::contains(const T& content) const
{
    
    const Node<T>* current = this->getFirstNode();
    while (current)
    {
        if (current->getContent() == content) return true;
        current = current->getNext();
    }
    return false;
}

template <class T>
void LinkedList<T>::add(const T& content)
{
                                               // ajoute un nouveau noeud a la fin de la liste
    Node<T>* n = new Node<T>();
    n->setContent(content);
    n->setNext(nullptr);

    Node<T>* head = this->getFirstNode();
    if (!head)
    { 
                                               // cas liste vide  n devient le premier noeud
        this->setFirstNode(n);
        return;
    }

    Node<T>* last = getLastNode(); // trouve le dernier noeud existant
    last->setNext(n);              // attache le nouveau noeud
}

template <class T>
void LinkedList<T>::remove(const T& content)
{
                                          // supprime la premiere occurrence de content si elle existe
    Node<T>* head = this->getFirstNode();
    if (!head) return;

                                             // cas ou le premier noeud correspond
    if (head->getContent() == content)
    {
        Node<T>* next = head->getNext();
        delete head;
        this->setFirstNode(next);
        return;
    }

                                                     // cherche le noeud precedent
    Node<T>* prev = head;
    while (prev->getNext() && !(prev->getNext()->getContent() == content))
        prev = prev->getNext();

    if (Node<T>* victim = prev->getNext())
    {
        prev->setNext(victim->getNext());
        delete victim;
    }
}

template <class T>
void LinkedList<T>::clear()
{
                                                     // supprime tous les noeuds de la liste
    Node<T>* cur = this->getFirstNode();
    while (cur)
    {
        Node<T>* next = cur->getNext();
        delete cur;
        cur = next;
    }
    this->setFirstNode(nullptr);
}

template <class T>
const T& LinkedList<T>::get(unsigned int index) const
{
                                            // retourne le contenu du noeud a l index ou lance exception si hors limites
    const unsigned int n = size();
    if (index >= n)
        throw std::out_of_range("index hors limites");

    const Node<T>* cur = this->getFirstNode();
    for (unsigned int i = 0; i < index; ++i)
        cur = cur->getNext();

    return cur->getContent();
}

template <class T>
unsigned int LinkedList<T>::size() const
{
                                                   // Compte le nombre de noeuds et le retourne
    unsigned int count = 0;
    const Node<T>* cur = this->getFirstNode();
    while (cur)
    {
        ++count;
        cur = cur->getNext();
    }
    return count;
}

template <class T>
Node<T>* LinkedList<T>::getLastNode()
{
                                             // retourne un pointeur vers le dernier noeud ou nullptr si vide
    Node<T>* cur = this->getFirstNode();
    if (!cur) return nullptr;
    while (cur->getNext())
        cur = cur->getNext();
    return cur;
}

template <class T>
const Node<T>* LinkedList<T>::getLastNode() const
{
                                                     // version const de getLastNode
    const Node<T>* cur = this->getFirstNode();
    if (!cur) return nullptr;
    while (cur->getNext())
        cur = cur->getNext();
    return cur;
}

template <class U>
bool operator==(const LinkedList<U>& lhs, const LinkedList<U>& rhs)
{
    
    if (&lhs == &rhs) return true;

                                                  // tailles differentes -> pas egal
    if (lhs.size() != rhs.size()) return false;

                                                  // comparaison element par element dans lordre
    const unsigned int n = lhs.size();
    for (unsigned int i = 0; i < n; ++i)
    {
        if (!(lhs.get(i) == rhs.get(i)))               // utilise operator== de int
            return false;
    }
    return true;
}
