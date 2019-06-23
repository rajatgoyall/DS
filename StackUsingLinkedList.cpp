#include<iostream>
using namespace std;

class Node{
	public:
	int data;
	Node* next= NULL;
	
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
	~Node()
	{
		delete next;
	}
	
};

void insertnode(Node** head,int data)
{
	if(*head==NULL)
	{
		Node* newnode=new Node(data);
		*head=newnode;
		return;
	}
	
	Node* newnode=new Node(data);
	newnode->next=*head;
	*head=newnode;
	return;
	
}

int  popnode(Node** head)
{
	if(*head==NULL)
	{
		cout<<"List is Empty"<<endl;
		return 0;
	}
	Node* temp=*head;
	*head=(*head)->next;
	int output=temp->data;
	temp->next=NULL;
	delete temp;
	return output;
	
	
}

void printlist(Node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
}

int main()
{
	Node*head=NULL;
	insertnode(&head,10);
	insertnode(&head,20);
	insertnode(&head,30);
	insertnode(&head,40);
	popnode(&head);
	//cout<<head->data<<endl;
	printlist(head);
	
}
