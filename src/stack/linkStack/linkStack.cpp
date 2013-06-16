#include "linkStack.h"
void initStack(linkStack& s)
{
	s = 0;
}
bool isEmpty(linkStack s)
{
	if(0 == s)
		return true;
	else
		return false;
}
bool push(linkStack& s, int data)
{
	linkedNode* pNode = new linkedNode;
	if(0 == pNode)
		return false;
	pNode->data = data;
	pNode->link = s;
	s = pNode;
	return true;
}
bool pop(linkStack& s, int& data)
{
	if(0 == s)
		return false;
	linkedNode* pNode = s;
	data = pNode->data;
	s = s->link;
	delete pNode;
	return true;
}
bool getTop(linkStack s, int& data)
{
	if(0 == s)
		return false;
	data = s->data;
	return true;
}
void clearStack(linkStack& s)
{
	while(s != 0)
	{
		linkedNode* pNode = s;
		s = s->link;
		delete pNode;
	}
}