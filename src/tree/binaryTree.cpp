#include<iostream>
#include <stack>
#include <queue>

using namespace std;
typedef char DataType;
struct TreeNode{
	DataType data;
	TreeNode* lchild;
	TreeNode* rchild;
};

typedef TreeNode* Root;

int FindRootPos(DataType c, DataType In [], int start, int end)
{
	int i = start;
	while (i <= end && In[i++] != c);
	if (i > end)
		return -1;
	return --i;
}
TreeNode* CreateTree(DataType Pre [], int Ps, int Pe, DataType In [], int Is, int Ie)
{
	//error check 略
	if(Ps > Pe)
		return NULL;

	TreeNode* tn = new TreeNode;
	tn->data = Pre[Ps];
	if (Ps == Pe)
	{
		tn->lchild = NULL;
		tn->rchild = NULL;
		return tn;
	}

	int pos = FindRootPos(Pre[Ps], In, Is, Ie);
	if (pos == -1)
		return NULL;

	tn->lchild = CreateTree(Pre, Ps+1, Ps + pos-Is, In, Is, pos-1);
	tn->rchild = CreateTree(Pre, Ps + pos - Is + 1,Pe, In, pos + 1, Ie);
	return tn;
}

void PreOrder(const Root& root)
{
	if (root == NULL)
		return;

	cout << root->data << " ";
	PreOrder(root->lchild);
	PreOrder(root->rchild);
}
void PreOrderUnRe(const Root& root)
{
	stack<TreeNode*> st;
	st.push(root);
	while (!st.empty())
	{
		TreeNode* tn = st.top();
		cout << tn->data << " ";
		st.pop();

		if (tn->rchild != NULL)
			st.push(tn->rchild);
		if (tn->lchild != NULL)
			st.push(tn->lchild);
	}
}
void InOrder(const Root& root)
{
	if (root == NULL)
		return;
	InOrder(root->lchild);
	cout << root->data <<" ";
	InOrder(root->rchild);
}
void InOrderUnRe(const Root& root)
{
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	while (pNode != NULL || !st.empty())
	{
		while (pNode != NULL) 
		{ // n steps forward left after push
			st.push(pNode); 
			pNode = pNode->lchild; 
		}
		if (!st.empty())
		{// one step forward right after pop
			pNode = st.top(); cout << pNode->data << " "; st.pop(); 
			pNode = pNode->rchild; 
		}
	}
}

void PostOrder(const Root& root)
{
	if (root == NULL)
		return;
	PostOrder(root->lchild);
	PostOrder(root->rchild);
	cout << root->data << " ";
}
void PostOrderUnRe(const Root& root)
{
	stack<TreeNode*> st;
	TreeNode* pNode = root;
	TreeNode* pre = NULL;
	while (pNode != NULL || !st.empty())
	{
		while (pNode != NULL)
		{
			// n steps forward left after push
			st.push(pNode);
			pNode = pNode->lchild;
		}
		if (!st.empty())
		{
			// one step forward right after pop
			pNode = st.top();
			if ((pNode->lchild == NULL && pNode->rchild == NULL) || (pre != NULL && pre == pNode->rchild))
			{
				cout << pNode->data << " ";
				st.pop();
				pre = pNode;
				pNode = NULL;
			}
			else
				pNode = pNode->rchild;
		}
	}
}
void LevelOrder(const Root& root)
{
	if (root == NULL)
		return;
	
	queue<TreeNode*> qt;
	TreeNode* tn = NULL;
	qt.push(root);
	while ( !qt.empty())
	{
		tn = qt.front(); cout << tn->data << " "; qt.pop();
		if (tn->lchild != NULL)
			qt.push(tn->lchild);
		if (tn->rchild != NULL)
			qt.push(tn->rchild);
	}
}

void DestoryTree(Root& root)
{
	if (root == NULL)
		return;
	DestoryTree(root->lchild);
	DestoryTree(root->rchild);
	delete root;
}
int main()
{
	char Pre[7] = "abdefc";
	char In[7] = "dbefac";
	Root root;
	root = CreateTree(Pre, 0, 5, In, 0, 5);
	//PreOrder(root);
	//cout << endl;
	PreOrderUnRe(root);
	cout << endl;
	InOrder(root);
	cout << endl;
	//InOrderUnRe(root);
	//cout << endl;
	PostOrder(root);
	cout << endl;
	PostOrderUnRe(root);
	cout << endl;
	LevelOrder(root);
    return 0;
}
