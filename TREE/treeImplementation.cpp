#include<iostream>
#include<queue>
#include<vector>
#include"treenode.h"
using namespace std;

void printatk(Treenode<int>* root,int k)
{
	if(k==1)
	{
		cout<<root->data<<" ";
		return;
	}
	
	for(int i=0;i<root->chilldren.size();i++)
	{
		printatk(root->chilldren[i],k-1);
	}
	
}

int height(Treenode<int>* root)
{
	vector<int>a;
	if(root->chilldren.size()==0)
	{
		return 1;
	}
	for(int i=0;i<root->chilldren.size();i++)
	{
		a.push_back(height(root->chilldren[i]));
		
	}
	int max=0;
	for(int i=0;i<a.size();i++)
	{
		if(max<a[i])
		{
			max=a[i];
		}
	}
	return 1+max;
	
}

int countnodes(Treenode<int>* root)
{
	int ans=1;
	for(int i=0;i<root->chilldren.size();i++)
	{
		ans+=countnodes(root->chilldren[i]);
	}
	return ans;
}

void printlevelorder(Treenode<int>* root)
{
	queue<Treenode<int>* >pendingnodes;
	pendingnodes.push(root);
	Treenode<int>* front=pendingnodes.front();
	while(pendingnodes.size()!=0)
	{
		front=pendingnodes.front();
		pendingnodes.pop();
		for(int i=0;i<front->chilldren.size();i++)
		{
			pendingnodes.push(front->chilldren[i]);
		}
		cout<<front->data<<endl;
	}
}

Treenode<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"Enter the Node data: "<<endl;
	cin>>rootdata;
	Treenode<int>* root=new Treenode<int>(rootdata);
	queue <Treenode<int>*>pendingnodes;
	pendingnodes.push(root);
	Treenode<int>* front;
	while(pendingnodes.size()!=0)
	{
		front=pendingnodes.front();
		pendingnodes.pop();
		cout<<"Enter the number of chilldren for "<<front->data<<endl;
		int numchild;
		cin>>numchild;
		for(int i=0;i<numchild;i++)
		{
			cout<<"enter the data for : "<<i<<"th child of "<<front->data<<endl;
			int cdata;
			cin>>cdata;
			Treenode<int>* n1=new Treenode<int>(cdata);
			front->chilldren.push_back(n1);
			pendingnodes.push(n1);
		}
	}
	return root;
	
}

Treenode<int>* takeinput()
{
	int rootdata;
	cout<<"Enter the Node data: "<<endl;
	cin>>rootdata;
	Treenode<int>* root=new Treenode<int>(rootdata);
	cout<<"enter the number of chilldren for : "<<rootdata<<endl;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Treenode<int>* n1=takeinput();
		root->chilldren.push_back(n1);
	}
	return root;
}

void printTree(Treenode<int>* root)
{
	cout<<root->data<<": ";
	for(int i=0;i<root->chilldren.size();i++)
	{
		cout<<root->chilldren[i]->data<<", ";
	}
	cout<<endl;
	for(int i=0;i<root->chilldren.size();i++)
	{
		printTree(root->chilldren[i]);
	}
}

int leafnodes(Treenode<int>* root)
{
	if(root->chilldren.size()==0)
	{
		return 1;
	}
	
	int sum=0;
	for(int i=0;i<root->chilldren.size();i++)
	{
	
		sum+=leafnodes(root->chilldren[i]);
	}
	return sum;
}


void del(Treenode<int>* root)
{
	
	for(int i=0;i<root->chilldren.size();i++)
	{
		del(root->chilldren[i]) ;
	//	root->chilldren.pop_back();
	}
	delete root ;
}

int main()
{
	/*Treenode<int>* root=new Treenode<int>(10);
	Treenode<int>* n1=new Treenode<int>(20);
	Treenode<int>* n2=new Treenode<int>(40);
	
	root->chilldren.push_back(n1);
	root->chilldren.push_back(n2);
	*/
	Treenode<int>* root=takeinputlevelwise();
	printlevelorder(root);
	int count=countnodes(root);
	cout<<"the number of node in the tree is : "<<count<<endl;
	int h=height(root);
	cout<<"height of the tree is : "<< h<<endl;
	printatk(root,3);
	int leafnode=leafnodes(root);
	cout<<"the leafnodes in the tree are: "<<leafnode<<endl;
	del(root);

	
}

