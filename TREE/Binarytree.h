#include<iostream>
using namespace std;

template<typename V>
class Binarytreenode{
	public:
	V data;
	Binarytreenode*left;
	Binarytreenode*right;
	Binarytreenode(V value)
	{
		this->data=value;
		this->left=NULL;
		this->right=NULL;
	}
	
	~Binarytreenode()
	{
		delete this->left;
		delete this->right;
	}
	
};
