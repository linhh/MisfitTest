#ifndef  _LINKEDLIST_CPP_
#define  _LINKEDLIST_CPP_

#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string.h>

using namespace std;

//-----------------------------------------------------------------------
/*
    Given such definition of Linked List
    class Node
    {
        int value;
        Node *next;
    }
    How to determine if the list contains a loop?
*/
class Node
{
public:
    int value;
    Node *next;

    Node()
	{
		value = 0;
		next = NULL;
	}

	~Node()
	{
		if (next)
		{
			delete next;
			next = NULL;
		}
	}
};

class LinkedList
{
public:
    Node *pHead, *pTail;

    LinkedList()
	{
		pHead = pTail = NULL;
	}

	~LinkedList()
	{

	}

public:
    // c. determine if the list contains a loop
    bool hasLoop (Node *startNode);

    //h. Reverse a linked list without recursion.
    Node* reveseLinkkedList(Node *node);
};

// c. determine if the list contains a loop
bool LinkedList::hasLoop(Node *startNode)
{
    Node *slowNode, *fastNode1, *fastNode2;
    slowNode = fastNode1 = fastNode2 = startNode;

    while (slowNode && (fastNode1 == fastNode2->next) && (fastNode2 == fastNode1->next)) {
        if ((slowNode == fastNode1) || (slowNode == fastNode2)) {
            return true;
        }
        slowNode = slowNode->next;
    }
    return false;
}

//h. Reverse a linked list without recursion.
Node* LinkedList::reveseLinkkedList(Node *node)
{
    Node *temp;
    Node *previous = NULL;
    while (node != NULL) {
        temp = node->next;
        node->next = previous;
        previous = node;
        node = temp;
    }
    return previous;
}

#endif
