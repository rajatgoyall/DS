#include<vector>
using namespace std;

template<typename V>
class Treenode{
	public:
	V data;
	vector<Treenode<V>*>chilldren;
	
	Treenode(V data)
	{
		this->data=data;
	}
	
	~Treenode()
	{
		for(int i=0;i<chilldren.size();i++)
		{
			delete chilldren[i];
		}
	}
	
};
