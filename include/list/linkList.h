#ifndef LINKLIST_H
#define LINKLIST_H

struct linkedNode
{
	int data;
	linkedNode* link;
};
typedef linkedNode* linkList;

bool initialList(linkList& l);

/*insert before the Kth element*/
bool insertList(linkList& l, int k, int data);
bool deleteList(linkList& l, int k);
linkList findList(linkList l, int k);
void printList(linkList l);
void clearList(linkList& l);

#endif
