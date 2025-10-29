#include "stdafx.h"
#include "CppUnitTest.h"
#include "LinkedList.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDoubleLinkedList
{
  TEST_CLASS(LinkedListTests)
  {
  public:

    
    TEST_METHOD(Ctor_MembersInitialized_ListIsEmpty)
    {
      LinkedList<int> list;
      Assert::IsTrue(list.isEmpty());
      Assert::AreEqual(0u, list.size());
    }

  };
}
