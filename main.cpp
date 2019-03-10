#include<iostream>
#include<string>
using namespace std;

struct TNode
{
	int val;
	TNode* next[10] = {NULL};
};
TNode* root = new TNode;

void insert_at_root(int x);
void insert_after(TNode* node, int x, int y);
void delete_node(TNode* node, int x);
void print(TNode* node, int n);

int main()
{
	/*
	insert_at_root(1);
	print(root->next[0], -1); cout << endl;

	insert_at_root(2);
	print(root->next[0], -1); cout << endl;

	insert_after(root,2, 3);
	print(root->next[0], -1); cout << endl;

	insert_after(root, 2, 4);
	print(root->next[0], -1); cout << endl;

	insert_after(root, 1, 6);
	print(root->next[0], -1); cout << endl;
	delete_node(root, 1);
	print(root->next[0], -1); cout << endl;
	delete_node(root, 6);
	print(root->next[0], -1); cout << endl;
	delete_node(root, 1);
	print(root->next[0], -1); cout << endl;
	*/
	string command;
	int x, y;
	while (cin >> command)
	{
		if (command == "insert_at_root")
		{
			cin >> x;
			insert_at_root(x);
		}
		else if (command == "insert_after")
		{
			cin >> x >> y;
			insert_after(root->next[0], x, y);
		}
		else if (command == "delete")
		{
			cin >> x;
			delete_node(root, x);
		}
		else if (command == "print")
		{
			cin >> x;
			print(root->next[0], x);
			cout << endl;
		}
	}
	return 0;
}

void insert_at_root(int x)
{
	TNode* p = new TNode;
	p->val = x;
	if (root->next[0] == NULL)
	{
		root->next[0] = p;
	}
	else
	{
		p->next[0] = root->next[0];
		root->next[0] = p;
	}
}
void insert_after(TNode* node, int x, int y)
{
	TNode* p = node;
	if (p == NULL)
		return;
	else if (p->val == x)
	{
		TNode* q = new TNode;
		q->val = y;
		if (p->next[0] == NULL)
		{
			p->next[0] = q;
		}
		else
		{
			int i;
			for (i = 1; p->next[i] != NULL; i++);
			p->next[i] = q;
		}
		return;
	}
	else
	{
		int j;
		for (j = 0; j < 9; j++)
		{
			if (p->next[j] == NULL)
				continue;
			else
				insert_after(p->next[j], x, y);
		}
	}
}
void delete_node(TNode* node, int x)
{
	TNode* p = node;
	int count = 0;
	for (int i = 0; i < 9; i++)
	{
		if (p->next[i] == NULL)
			continue;
		else if (p->next[i]->val == x)
		{
			int m = 0;
			for (int t = 0; t < 9; t++)
				if (p->next[i]->next[t] != NULL)
					m++;
			if (m == 0)
			{
				delete p->next[i];
				p->next[i] = NULL;   
				return;
			}
		}
		else
			delete_node(p->next[i], x);
	}
}
void print(TNode* node, int n)
{
	if (n == -1)
	{
		if (node == NULL)
			return;
		else
		{
			cout << node->val << " ";
			for (int i = 0; i < 9; i++)
			{
				if (node->next[i] == NULL)
					continue;
				else
					print(node->next[i], -1);
			}
		}
	}
	else
	{
		if (node == NULL || n == 0)
			return;
		else
		{
			cout << node->val << " ";
			for (int i = 0; i < 9; i++)
			{
				if (node->next[i] == NULL)
					continue;
				else
					print(node->next[i], n - 1);
			}
		}
	}
}