#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
	LRUCache(int capacity) {
		_capacity = capacity;
	}

	int get(int key) {
		auto hashit = _hashmap.find(key);
		//hash中查找key为O(1)，找到后直接定位到list中的iterator直接删除，再进行头插实现O(1)的数据挪动
		if (hashit != _hashmap.end())
		{
			auto listit = hashit->second;
			pair<int, int> kv = *listit;
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
			return kv.second;
		}
		return -1;
	}

	void put(int key, int value) {
		auto hashit = _hashmap.find(key);
		if (hashit != _hashmap.end())	//找到旧key进行更新，放入链表头
		{
			auto listit = hashit->second;
			pair<int, int> kv =*listit;
			kv.second = value;
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
		else			//没有旧key，插入新节点，如果容量超限删除最旧的节点
		{
			if (_list.size() >= _capacity)
			{
				_hashmap.erase(_list.back().first);
				_list.pop_back();
			}

			_list.push_front(make_pair(key,value));
			_hashmap[key] = _list.begin();
		}
	}
	
private:
	int _capacity;						//LRU cache容量大小
	list<pair<int, int>> _list;			//将最近使用过的往链表头移动，保持LRU，list底层就是双向链表
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;    //调用get时，可以通过key找到list的指针，这样便于将使用后的list节点放入链表头符合LRU
};

int main()
{
	LRUCache* lr = new LRUCache(2);
	lr->put(3,3);
	lr->put(5,5);
	lr->put(7,7);

	cout<<lr->get(3)<<endl;		//-1
	cout<<lr->get(7)<<endl;		//7
	cout<<lr->get(5)<<endl;		//5	
}