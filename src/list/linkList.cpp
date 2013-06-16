#include "linkList.h"
#include <iostream>

/* with head node */
bool initialList(linkList& l)
{
	linkedNode* pNode = new linkedNode;
	if(0 == pNode)
		return false;
	pNode->link = 0;
	l = pNode;
	return true;
}

/*insert before the Kth element*/
linkList findList(linkList l, int k)
{
	if(0 == l->link || 0 == k)
		return l; //return head node
	if(k < 0)
		return 0;
	linkedNode* pNode = l;
	while(k && pNode != 0)
	{ 
		pNode = pNode->link;	
		k--;
	}
	if(pNode != 0 && 0==k)
		return pNode;
	return 0;
}

bool insertList(linkList& l, int k, int data)
{
	linkedNode* pNode = new linkedNode;
	if(0 == pNode)
		return false;

	linkedNode* pre;
	pre = findList(l, k-1);
	if(0 == pre)
		return false;
	pNode->data = data;
	pNode->link = pre->link;
	pre->link = pNode;
	
	return true;

}

bool deleteList(linkList& l, int k)
{
	if(0 == l->link)
		return false;

	linkedNode* pre;
	pre = findList(l, k-1);
	if(0 == pre)
		return false;
	linkedNode* pNode = pre->link;
	pre->link = pNode->link;
	delete pNode;
	return true;
}

void printList(linkList l)
{
	linkedNode* pNode = l->link;
	while(pNode != 0)
	{
		std::cout<<pNode->data<<" ";
		pNode = pNode->link;
	}
	std::cout<<std::endl;
}
void clearList(linkList& l)
{
	linkedNode* pre= l;
	linkedNode* pNode = pre->link;
	while(pNode != 0)
	{
		pre->link = pNode->link;
		delete pNode;
		pNode = pre->link;
	}
	delete l;
}