#include<iostream>
#include"BST.h"
#include<queue>
using namespace std;


Binarytreenode<int>* takeinputlevelwise()
{
	int rootdata;
	cout<<"enter the data at root: "<<endl;
	cin>>rootdata;
	Binarytreenode<int>* root= new Binarytreenode<int>(rootdata);
	queue<Binarytreenode<int>*> pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		Binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		int leftdata;
		cout<<"Enter the left child of: "<<front->data<<endl;
		cin>>leftdata;
		if(leftdata!=-1)
		{
			Binarytreenode<int>* node=new Binarytreenode<int>(leftdata);
			pendingnodes.push(node);
			front->left=node;
		}
		int rightdata;
		cout<<"Enter the right child of: "<<front->data<<endl;
		cin>>rightdata;
		if(rightdata!=-1)
		{
			Binarytreenode<int>* node=new Binarytreenode<int>(rightdata);
			pendingnodes.push(node);
			front->right=node;
		}
	}
	return root;
}

void printlevelwise(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return;
	}
	queue <Binarytreenode<int>* > pendingnodes;
	pendingnodes.push(root);
	while(pendingnodes.size()!=0)
	{
		Binarytreenode<int>* front=pendingnodes.front();
		pendingnodes.pop();
		cout<<front->data<<": ";
		if(front->left)
		{
			cout<<"L"<<front->left->data;
			pendingnodes.push(front->left);
		}
		
		if(front->right)
		{
			cout<<"R"<<front->right->data;
			pendingnodes.push(front->right);
		}
		cout<<endl;
		
		
	}
	return;
	
}

bool searchBST(Binarytreenode<int>* root,int key)
{
	if(root==NULL)
	return false;
	
	if(root->data==key)
	{
		return true;
	}
	if(root->data>key)
	{
		return searchBST(root->left,key);
	}
	if(root->data<key)
	{
		return searchBST(root->right,key);
	}
	
	
	
}

void insertinBST(Binarytreenode<int>* root,Binarytreenode<int>* inode)
{
	Binarytreenode<int>* temp=root;
	while(temp)
	{
		if(temp->data>inode->data)
		{
			if(temp->left==NULL)
			{
				temp->left=inode;
				return;
			}
			temp=temp->left;
		}
		if(temp->data<inode->data)
		{
			if(temp->right==NULL)
			{
				temp->right=inode;
				return;
			}
			temp=temp->right;
		}
	}
}

Binarytreenode<int>* createBST()
{
	int d;
	cout<<"Enter data : "<<endl;
	cin>>d;
	Binarytreenode<int>* root=NULL;
	while(d!=-1)
	{
		if(root==NULL)
		{
			Binarytreenode<int>* node=new Binarytreenode<int>(d);
			root=node;
			cout<<"Enter the next data: "<<endl;
			cin>>d;
			continue;
		}
		Binarytreenode<int>* node=new Binarytreenode<int>(d);
		insertinBST(root,node);
		cout<<"Enter the next data: "<<endl;
		cin>>d;
		
	}
	return root;
}

void Print(Binarytreenode<int>* root,int k1,int k2)
{
	if ( NULL == root )  
        return;  
      
   
    if ( k1 < root->data )  
        Print(root->left, k1, k2);  
      
    
    if ( k1 <= root->data && k2 >= root->data )  
        cout<<root->data<<" ";  
      
    if ( k2 > root->data )  
        Print(root->right, k1, k2);
	
	
}

int getmax(Binarytreenode<int>* root)
{
	while(root->right)
	{
		root=root->right;
	}
	return root->data;
}

int getmin(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return 0;
	}
	while(root->left)
	{
		root=root->left;
	}
	return root->data;
}
bool isBST(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		return true;
	}
	if(root->left&&root->right)
	return (root->data>getmax(root->left))&&(root->data<getmin(root->right) )&&isBST(root->left)&&isBST(root->right);
	if(root->left)
	return (root->data>getmax(root->left))&&isBST(root->left);
	if(root->right)
	return (root->data<getmin(root->right) )&&isBST(root->right);
	return true;
	
}
class isBSTreturn{
	public:
	bool isbst;
	int maximum;
	int minimum;
};

isBSTreturn isBST2(Binarytreenode<int>* root)
{
	if(root==NULL)
	{
		isBSTreturn a;
		a.isbst=true;
		a.maximum=INT_MIN;
		a.minimum=INT_MAX;
		return a;
	}
	isBSTreturn leftoutput=isBST2(root->left);
	isBSTreturn rightoutput=isBST2(root->right);
	
	int minimum=min(root->data,min(leftoutput.minimum,rightoutput.minimum));
	int maximum=max(root->data,max(leftoutput.maximum,rightoutput.maximum));
	bool isBSTfinal=(root->data>leftoutput.maximum)&& (root->data<rightoutput.minimum)&&leftoutput.isbst&&rightoutput.isbst;
	isBSTreturn out;
	out.isbst=isBSTfinal;
	out.maximum=maximum;
	out.minimum=minimum;
	return out;
}

bool isBST3(Binarytreenode<int>* root,int min,int max)
{
	if(root==NULL)
	{
	return true;
	}
	
	if(root->data<min||root->data>max)
	{
		return false;
		}	
		bool isleftok=isBST3(root->left,min,root->data-1);
		bool isrightok=isBST3(root->right,root->data+1,max);	
		return isleftok&&isrightok	;
}

Binarytreenode<int>* BSTfromarray(int* a,int si,int ei)
{
	if(si==ei)
	{
		Binarytreenode<int>* node=new Binarytreenode<int>(a[si]);
		return node;
	}
	int m=(si+ei)/2;
	Binarytreenode<int>* lefttree=BSTfromarray(a,si,m-1);
	Binarytreenode<int>* righttree=BSTfromarray(a,m+1,ei);
	Binarytreenode<int>* root=new Binarytreenode<int>(a[m]);
	root->left=lefttree;
	root->right=righttree;
	return root;
	
	
}
vector<int> returnpath(Binarytreenode<int>*root,int key)
{
	if(root==NULL)
	{
		vector<int>a;
		return a;
	}
	if(root->data==key)
	{
		vector<int>output;
		output.push_back(root->data);
		return output;
	}
	
	vector<int> leftoutput=returnpath(root->left,key);
	if(leftoutput.size()!= 0)
	{
		leftoutput.push_back(root->data);
		return leftoutput;
	}
	vector<int> rightoutput=returnpath(root->right,key);
	if(rightoutput.size()==0)
	{
		vector<int>a;
		return a;
	}
	rightoutput.push_back(root->data);
	return rightoutput;
	
}


int main()
{
//	Binarytreenode<int>*root=createBST();
	int a[7]={1,2,3,4,5,6,7};
	Binarytreenode<int>* root=BSTfromarray(a,0,6);

	printlevelwise(root);
//	cout<<"enter the key you want to search"<<endl;
//	int a;
//	cin>>a;
//	searchBST(root,a)?cout<<"Key found"<<endl:cout<<"key not found"<<endl;
//	int min,max;
//	cout<<"enter the min and max: ";
//	cin>>min>>max;
//	Print(root,min,max);

//	isBST3(root,INT_MIN,INT_MAX)?cout<<"it is":cout<<"it is not"<<endl;

	vector<int> output=returnpath(root,7);
	for(int i=0;i<output.size();i++)
	{
		cout<<output[i]<<" ";
	}
	
}
