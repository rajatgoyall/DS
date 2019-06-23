#include<iostream>
using namespace std;

struct Node{
	int data;
	Node* next;
	
	Node(int value)
	{
		this->data=value;
		next=NULL;
    }
};

void takeinput(Node** head)
{
	
	int input;
	cin>>input;
	if(*head==NULL)
	{
			Node* node=new Node(input);
			*head=node;
			cin>>input;
	}

	
	Node* tail=*head;
	while(input!=-1)
	{
		Node* newnode=new Node(input);
		tail->next=newnode;
		tail=newnode;
		cin>>input;
	}
}

void append(int value,int index,Node**head)
{
	if(index==0)
	{
		Node* newnode=new Node(value);
		newnode->next=(*head);
		*head=newnode;
		
	}
	else
	{
		Node* temp=*head;
		while(temp&&index)
		{
			if(index==1)
			{
				Node* newnode=new Node(value);
				newnode->next=temp->next;
				temp->next=newnode;
			}
			temp=temp->next;
			index--;
		}
	
	}
	
}

void print(Node* head)
{
	while(head)
	{
		cout<<head->data<<" ";
		head=head->next;
	}
	cout<<endl;
}

void deletekey(int key,Node** head)
{
	Node* temp=*head;
	if((*head)->data==key)
		{
			(*head)=(*head)->next;
		}
	Node* prev=NULL;	
	while(temp)
	{
		if(temp->data==key)
		{
			prev->next=temp->next;
			temp=temp->next;
			continue;
		}
		prev=temp;
		temp=temp->next;
		}	
	
}

Node* findmiddle(Node* head)
{
	Node* fast=head;
	Node* slow=head;
	while(fast&&fast->next)
	{
		slow=slow->next;
		fast=fast->next->next;
	}
	return slow;
}

int main()
{
	Node* head=NULL;
	takeinput(&head);
//	print(head);
//	append(15,1,&head);
	print(head);
//	deletekey(8,&head);
	print(head);
	Node* middle=findmiddle(head);
	cout<<middle->data<<endl;
	
	
}
