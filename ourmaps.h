	
#include<string>

using namespace std;

template<typename V>
class Mapnode{
	public:
		string key;
		V value;
		Mapnode* next;
		
		Mapnode(string key, V value)
		{
			this->key=key;
			this->value=value;
			next=NULL;
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
		
		V getValue(string key)
		{
			int bucketindex=getbucketindex(key);
			Mapnode<V>* head=buckets[bucketindex];
			while(head)
			{
				if(head->key==key)
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
		void insert(string key,V value)
		{
			int bucketIndex= getbucketindex(key);
			Mapnode<V>* head=buckets[bucketIndex];
			while(head)
			{
				if(head->key==key)
				{
					head->value=value;
					return;
				}
				
				head=head->next;
			}
			head=buckets[bucketIndex];
			Mapnode<V>* node=new Mapnode<V>(key,value);
			
			node->next=head;
			buckets[bucketIndex]=node;
			count++;
			double loadfactor=(1.0*count)/numbuckets;
			if(loadfactor>0.7)
			{
				rehash();
			}
			
		}
		
		double getloadfactor()
		{
			return (1.0*count)/numbuckets;
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
					string key=head->key;
					V value=head->value;
					insert(key,value);
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




