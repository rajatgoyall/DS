#include<iostream>
#include"BST.h"

using namespace std;

void printtree(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	cout<<root->data<<": ";
	if(root->left)
	cout<<"L"<<root->left->data;
	if(root->right)
	cout<<"R"<<root->right->data;
	cout<<endl;
	printtree(root->left);
	printtree(root->right);
	return;
}

int main()
{
	BST b;
	b.insert(1);
	b.insert(2);
	b.insert(5);
	b.insert(3);
	b.insert(4);
	b.insert(6);
	b.insert(9);
	b.insert(8);
	b.insert(7);
	printtree(b.root);	
	cout<<endl;
	b.deletedata(5);
	printtree(b.root);
}
