#include<bits/stdc++.h>
using namespace std;

class Node{
	public:
	int data;
	Node* next;
	
	Node(int data)
	{
		this->data=data;
		this->next=NULL;
	}
};

void print_list(Node* head)
{
	while(head)
	{
		cout<<head->data<<"->"<<" ";
		head=head->next;
	}
	cout<<endl;
	}	

void reverse_list(Node** head_ref)
{
	Node* current_ptr=*head_ref;
	Node* prev_ptr=NULL;
	N
	ode* next_ptr;
	while(current_ptr)
	{
		next_ptr=current_ptr->next;
		current_ptr->next=prev_ptr;
		prev_ptr=current_ptr;
		current_ptr=next_ptr;
		
	}
	*head_ref=prev_ptr;
	
}

int main()
{
	Node* head=NULL;
	Node* n1=new Node(10);
	Node* n2=new Node(20);
	Node* n3=new Node(30);
	Node* n4=new Node(40);
	n1->next=n2;
	n2->next=n3;
	n3->next=n4;
	head=n1;
	print_list(head);
	reverse_list(&head);
	print_list(head);

}

