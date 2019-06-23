#include<iostream>
using namespace std;
class Node{
	public:
	int data;
	Node* next=NULL;
	
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

void enquee(Node** head,int data)
{
	if(*head==NULL)
	{
		Node* newnode=new Node(data);
		*head=newnode;
		return;
	}
	Node* temp=*head;
	Node* newnode=new Node(data);
	while(temp->next)
	{
		temp=temp->next;
	}
	temp->next=newnode;
	return;
}

int dequee(Node**head)
{
	if(*head==NULL)
	{
		cout<<"Quee is empty"<<endl;
		return 0;
	}
	Node* temp=*head;
	int output=temp->data;
	*head=(*head)->next;
	temp->next=NULL;
	return output;
	delete temp;
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
	Node* head=NULL;
	enquee(&head,10);
	enquee(&head,20);
	enquee(&head,30);
	enquee(&head,40);
	dequee(&head);
	printlist(head);
	
}
