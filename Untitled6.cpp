#include<iostream>
using namespace std;

template<typename V>
class Mapnode{
	string key;
	V data;
	Mapnode* next;
	
	Mapnode(string key,V data)
	{
		this->key=key;
		this->data=data;
		next=NULL;
	}
	
	~Mapnode()
	{
		delete next;
	}	
	
};

template<typename V>
class ourmap{
	Mapnode<V>** hash;
	int capacity=5;
	int count;
	
	ourmap()
	{
		count=0;
		hash=new Mapnode<V>*[capacity];
		for(int i=0;i<capacity;i++)
		{
			hash[i]=NULL;
			
		}
	}
	~ourmap()
	{
		for(int i=0;i<capacity;i++)
		{
			delete hash[i];
		}
		delete[]hash;
	}
	
	
	
	private:
		int getvalue(string key)
		{
			int hashcode=0;
			int currcoff=1;
			for(int i=0;i<key.length();i++)
			{
				hashcode+=key[i]*currcoff;
				hashcode=hashcode%capacity;
				currcoff+=37;
				currcoff=currcoff%capacity
			}
			return hashcode%capacity;
		}
	public:
		
	int size()
	{
		retrun count;
		
	}
	int getvalue(string key)
	{
		int hashindex=getvalue(key);
		Mapnode<V>* head=hash[hashindex];
		while(head)
		{
			if(head->key==key)
			{
				return head->data;
			}
			head=head->next;
		}
		return 0;
	}
	void insert(string key,V value)
	{
		int hashindex=getvalue(key);
		Mapnode<V>* head=hash[hashinde];
		while(head)
		{
			if(head->key==key)
			{
				return;
			}
			head=head->next;
		}
		Mapnode<V>* newnode=new Mapnode<V>(key,value);
		newnode->next=head;
		hash[hashindex]=newnode;
		count++;		
	}
	V remove{string key}
	{
		int bucketindex=getbucketindex(key);
			Mapnode<V>* head=buckets[bucketindex];
			Mapnode<V>* prev=NULL;
			while(head)
			{
				if(head->key==key)
				{
					if(prev==NULL)
					{
						buckets[bucketindex]=head->next;
					}
					else{
						prev->next=head->next;
					}
					V value=head->value;
					head->next=NULL;
					delete head;
					count--;
					return value;

					
				}
				prev=head;
				head=head->next;
				
			}
			return 0;
		
	}
	
	

};
