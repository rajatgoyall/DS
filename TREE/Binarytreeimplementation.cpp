#include<iostream>
#include<queue>
#include"Binarytree.h"
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

void printtreelevelwise(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	queue<Binarytreenode<int>* > pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		Binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<":";
		if(front->left)
		cout<<"L"<<front->left->data;
		if(front->right)
		cout<<"R"<<front->right->data;
		cout<<endl;
	
		if(front->left)
		pendingnodes.push(front->left);
		if(front->right)
		pendingnodes.push(front->right);
		
	}
	return;
}

Binarytreenode<int>* takeinput()
{
	int rootdata;
	cout<<"Enter the data at root: "<<endl;
	cin>>rootdata;
	if(rootdata==-1)
	{
		return NULL;
	}
	Binarytreenode<int>* root= new Binarytreenode<int>(rootdata);
	
	Binarytreenode<int>* leftnode=takeinput();
	Binarytreenode<int>* rightnode=takeinput();
	root->left=leftnode;
	root->right=rightnode;
	return root;
	
}

Binarytreenode<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"Enter the data of root"<<endl;
	cin>>rootdata;
	Binarytreenode<int>* root=new Binarytreenode<int>(rootdata);
	queue<Binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		Binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int leftdata;
		cout<<"enter the left data of "<<front->data<<endl;
		cin>>leftdata;
		int rightdata;
		cout<<"enter the data at right of "<<front->data<<endl;
		cin>>rightdata;
		if(leftdata!=-1)
		{
			Binarytreenode<int>* leftnode=new Binarytreenode<int>(leftdata);
			front->left=leftnode;
			pendingnodes.push(leftnode);
		}
		if(rightdata!=-1)
		{
			Binarytreenode<int>* rightnode=new Binarytreenode<int>(rightdata);
			front->right=rightnode;
			pendingnodes.push(rightnode);
		}
		
	}
	
	return root;
}

void printinorder(Binarytreenode<int>*root)
{
	if(root==NULL)
	{
		return;
	}
	printinorder(root->left);
	cout<<root->data; 
	printinorder(root->right);
}

int height(Binarytreenode<int>* root)
{
	if(root==NULL)
	return 0;
	return 1+max(height(root->left),height(root->right));
}

int diameter(Binarytreenode<int>* root)
{
	if(root==NULL)
	return 0;
	return max(height(root->left)+height(root->right),max(diameter(root->left),diameter(root->right))) ;
	
}

pair<int,int> heightdiameter(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		pair<int,int>p;
		p.first=0;
		p.second=0;
		return p;		
	}
	pair<int,int>leftans=heightdiameter(root->left);
	pair<int,int>rightans=heightdiameter(root->right);
	
	int lh=leftans.first;
	int ld=leftans.second;
	int rh=rightans.first;
	int rd=rightans.second;
	
	int hei=1+max(lh,rh);
	int dia=max(lh+rh,max(ld,rd));
	pair<int,int>p;
	p.first=hei;
	p.second=dia;
	return p;
	
}

int main()
{
	Binarytreenode<int>* root=takeinputlevelwise();
	printinorder(root);
	cout<<endl;
	pair<int,int>q;
	
	q=heightdiameter(root);
	cout<<"the diameter of the tree is : "<<q.second<<endl;	
}
