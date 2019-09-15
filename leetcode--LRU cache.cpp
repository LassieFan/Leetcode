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
		//hash�в���keyΪO(1)���ҵ���ֱ�Ӷ�λ��list�е�iteratorֱ��ɾ�����ٽ���ͷ��ʵ��O(1)������Ų��
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
		if (hashit != _hashmap.end())	//�ҵ���key���и��£���������ͷ
		{
			auto listit = hashit->second;
			pair<int, int> kv =*listit;
			kv.second = value;
			_list.erase(listit);
			_list.push_front(kv);
			_hashmap[key] = _list.begin();
		}
		else			//û�о�key�������½ڵ㣬�����������ɾ����ɵĽڵ�
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
	int _capacity;						//LRU cache������С
	list<pair<int, int>> _list;			//�����ʹ�ù���������ͷ�ƶ�������LRU��list�ײ����˫������
	unordered_map<int, list<pair<int, int>>::iterator> _hashmap;    //����getʱ������ͨ��key�ҵ�list��ָ�룬�������ڽ�ʹ�ú��list�ڵ��������ͷ����LRU
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