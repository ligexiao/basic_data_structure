#include <iostream>
#include "linkList.h"
using namespace std;

int main()
{
/*
	linkList l;
	initialList(l);

	linkStack s;
	initStack(s);

	insertList(l, 1, 5);
	insertList(l, 1, 1);
	insertList(l, 2, 2);
	insertList(l, 3, 4);
	insertList(l, 3, 3);
	printList(l);

	linkedNode* pNode = l->link;
	while(pNode != 0)
	{
		push(s, pNode->data);
		pNode = pNode->link;
	}
	int data;
	while(!isEmpty(s))
	{
		pop(s, data);
		cout<<data<< ", ";
	}
	cout<<endl;
	clearStack(s);
	clearList(l);
*/
	/*
	linkStack s;
	initStack(s);
	
	push(s,1);
	int data;
	getTop(s, data);
	cout<<data<<endl;
	
	push(s,2);
	getTop(s, data);
	cout<<data<<endl;
	
	push(s,3);
	getTop(s, data);
	cout<<data<<endl;

	pop(s, data);
	cout<<data<<endl;

	clearStack(s);

	if(getTop(s, data))
		cout<<data<<endl;
	*/

	
	linkList l;
	initialList(l);
	for(int i = 1; i <= 5; i++)
	{
		insertList(l, 1, i+10);
		
	}
	printList(l);

	deleteList(l, 1);
	printList(l);

	deleteList(l,2);
	printList(l);

	deleteList(l,3);
	printList(l);
	clearList(l);

	return 0;
}
