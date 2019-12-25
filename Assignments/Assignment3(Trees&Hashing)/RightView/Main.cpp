#include <iostream>
using namespace std;




struct Node {

	int data;
	struct Node* right;
	struct Node* left;

};


void PrintRightView(Node * Root, int level, int &maxLevel);


int main()
{
	int NumberOfNodes = 0 , NumberOfEdges = 0;
	cin >> NumberOfNodes;
	Node * ArrayOfNodes = new  Node[NumberOfNodes];
    int data;

	for (int i = 0; i < NumberOfNodes; i++)
	{
		ArrayOfNodes[i].left = NULL;
		ArrayOfNodes[i].right = NULL;
		cin >> data;
		ArrayOfNodes[i].data = data;
	}
	cin >> NumberOfEdges;
	string Side;
    int Start,End;
 	for (int i = 0; i < NumberOfEdges; i++)
	{
		cin>>Side>>Start>>End;
		if (Side == "L")
		{
			ArrayOfNodes[Start].left = &ArrayOfNodes[End];
		}
		if (Side == "R")
		{
			ArrayOfNodes[Start].right = &ArrayOfNodes[End];
		}
	}

	int level = 0, maxlevel = -1;
	PrintRightView(&ArrayOfNodes[0],level,maxlevel);
	return 0;
}







void PrintRightView(Node * Root,int level,int &maxLevel)
{
	if (!Root)
	{
		return;
	}
	if (maxLevel < level)
		cout << Root->data << " ";
	if (maxLevel < level)
		maxLevel += 1;


	PrintRightView(Root->right,level+1,maxLevel);

	PrintRightView(Root->left,level+1,maxLevel);
	
}
