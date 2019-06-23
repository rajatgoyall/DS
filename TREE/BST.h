#include"Binarytree.h"

class BST{
	public:
	Binarytreenode<int>* root;
	
	BST()
	{
		root=NULL;
	}
	~BST()
	{
		delete root;
	}
	private:
		Binarytreenode<int>* deletedata(int data,Binarytreenode<int>* root)
		{
			if(root==NULL)
			{
				return NULL;
			}
			
			if(root->data>data)
			{
				root->left=deletedata(data,root->left);
				return root;
			}
			else if(root->data<data)
			{
				root->right=deletedata(data,root->right);
				return root;
			}else
			{
				if(root->left==NULL&&root->right==NULL)
				{
					delete root;
					return NULL;
				}else if(root->left==NULL)
				{
					Binarytreenode<int>* out=root->right;
					root->right=NULL;
					delete root;
					return out;
				}else if(root->right==NULL)
				{
					Binarytreenode<int>* out=root->left;
					root->left=NULL;
					delete root;
					return out;
					
				}
				else
				{
					Binarytreenode<int>* mini=root->right;
					while(mini->left)
					{
						mini=mini->left;
					}
					int rightmin=mini->data;
					root->data=rightmin;
					root->right=deletedata(rightmin,root->right);
					return root;
				}
				
			}
			
		}
	
	public:
	void deletedata(int data)
	{
		this->root=deletedata(data,this->root);
	}
	private:
		Binarytreenode<int>* insert(int data,Binarytreenode<int>* root)
		{
			if(root==NULL)
			{
				Binarytreenode<int>* node=new Binarytreenode<int>(data);
				return node;
			}
			if(root->data>data)
			{
				
				root->left=insert(data,root->left);
				return root;
			}
			if(root->data<data)
			{
				root->right=insert(data,root->right);
				return root;
				
			}
			
			
		}
	public:
	void insert(int data)
	{
		this->root=insert(data,this->root);
	}
	private:
	bool hasdata(int data,Binarytreenode<int>*root)
	{
		if(root==NULL)
		{
			return false;
		}
		if(root->data==data)
		{
			return true;
		}
		if(data<root->data)
		{
			return hasdata( data,root->left);
		}
		if(root->data<data)
		{
			return hasdata(data , root->right);
		}
	}
	public:
		bool hasdata(int data)
		{
			return hasdata(data,root);
		}
};
