#ifndef LINKSTACK_H
#define LINKSTACK_H

struct linkedNode
{
    int data;
    linkedNode* link;
};
typedef linkedNode* linkStack;

void initStack(linkStack& s);
bool isEmpty(linkStack s);
bool push(linkStack& s, int data);
bool pop(linkStack& s, int& data);
bool getTop(linkStack s, int& data);
void clearStack(linkStack& s);

#endif
