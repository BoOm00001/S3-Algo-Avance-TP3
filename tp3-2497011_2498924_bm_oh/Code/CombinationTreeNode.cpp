#include "CombinationTreeNode.h"
#include "CombinationTreeNode.h"
#include "stdafx.h"
#include "CombinationTreeNode.h"

CombinationTreeNode::~CombinationTreeNode()
{
  for (unsigned int i = 0; i < children.size(); ++i)
  {
    delete children.get(i);
  }
}

unsigned int CombinationTreeNode::size() const
{
  unsigned int total = 0;
  // Le noeud ne compte pour un que s'il n'a pas d'enfants
  // C'est la fin de la combinaison
  if (children.isEmpty())
    total = 1;
  else
  {
    // Sinon, on compte les enfants de manière récursive
    for (unsigned int i = 0; i < children.size(); ++i)
    {
      unsigned int currentSize = children.get(i)->size();
      total += currentSize;
    }
  }
  return total;
}


void CombinationTreeNode::setColor(Color newColor)
{
  color = newColor;
}
Color CombinationTreeNode::getColor() const
{
  return color;
}


LinkedList<CombinationTreeNode*>& CombinationTreeNode::getChildren()
{
  return children;
}

const LinkedList<CombinationTreeNode*>& CombinationTreeNode::getChildren() const
{
  return children;
}