#include<stdio.h>
#include<string>

using namespace std;

template<typename V>
class Mapnode{
	public:
		string key;
		V value;
		Mapnode* next;
		
		MapNode(string key, V value)
		{
			this->key=key;
			this->value=value;
			this->next=NULL;
		}
		
		~Mapnode()
		{
			delete next;
		}
};

template<typename V>
class ourmap{
	Mapnode<V>** buckets;
	int count;
	int numbuckets;
	
	public:
		ourmap()
		{
			count=0;
			numbuckets=5;
			buckets=new Mapnode<V>*[numbuckets];
			for(int i=0;i<numbuckets;i++)
			{
				buckets[i]=NULL;
			}
			
		}
		
		~ourmap()
		{
			for(int i=0;i<numbuckets;i++)
			{
				delete buckets[i];
			}
			delete []buckets;
		}
		
		
		private:
		getbucketindex(string key)
		{
			int hashcode = 0;
			int currcoff = 1;
			
			for(int i=key.length()-1;i>=0;i--)
			{ 
				hashcode+=key[i]*currcoff;
				hashcode%=numbuckets;
				currcoff+=37;
				currcoff%=numbuckets;
				
			}	
			
			return hashcode%numbuckets;
		}
			
		public:
		
		int size()
		{
			return count;
		}
		
		V getValue(string keyvalue)
		{
			int bucketindex=getbucketindex(keyvalue);
			Mapnode<V>* head=buckets[bucketindex];
			while(head)
			{
				if(head->key==keyvalue)
				{
					return head->value;
				}
				
				head=head->next;
			}
			return 0;
		}
		V remove(string key)
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
						return head->value;
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
		void insert(string keyvalue,V value)
		{
			int bucketIndex= getbucketindex(keyvalue);
			Mapnode<V>* head=buckets[bucketIndex];
			while(head)
			{
				if(head->key==keyvalue)
				{
					head->value=value;
					return;
				}
				
				head=head->next;
			}
			Mapnode<V>* node=new Mapnode<V>(keyvalue,value);
			node->next=head;
			buckets[bucketIndex]=node;
			count++;
			double loadfactor=(1.0*count)/numbuckets;
			if(loadfactor>0.7)
			{
				rehash();
			}
			
		}
		
		
		void rehash()
		{
			Mapnode<V>**temp=buckets;
			buckets=new Mapnode<V>*[2*numbuckets];
			for(int i=0;i<2*numbuckets;i++)
			{
				buckets[i]=NULL;
			}
			int oldnumbuckets=numbuckets;
			numbuckets*=2;
			count=0;
			for(int i=0;i<oldnumbuckets;i++)
			{
				Mapnode<V>* head=temp[i];
				while(head)
				{
					buckets.insert(head->key,head->value);
					head=head->next;
				}
			}
			for(int i=0;i<oldnumbuckets;i++)
			{
				Mapnode<V>* head= temp[i];
				delete head;
			}
			delete [] temp;
		}
		
		
};



