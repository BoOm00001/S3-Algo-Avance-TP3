#pragma once
#include "Color.h"
#include "LinkedList.h"
class CombinationTreeNode
{
public:
  CombinationTreeNode() = default;
  ~CombinationTreeNode();
  unsigned int size() const;
  void setColor(Color color);
  Color getColor() const;
  LinkedList<CombinationTreeNode*>& getChildren();
  const LinkedList<CombinationTreeNode*>& getChildren() const;
private:
  Color color;
  LinkedList<CombinationTreeNode*> children;
};

