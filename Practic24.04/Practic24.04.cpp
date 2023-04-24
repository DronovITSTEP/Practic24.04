#include <iostream>
using namespace std;

// const_cast - преобразование const и/или 
	// volitile
void test(const int* v) {
	int* temp;
	temp = const_cast<int*>(v);
	*temp = *v * *v;
}

// dynamic_cast
class B {
public:
	virtual void Test() {
		cout << "Test B\n\n";
	}
};
class D : public B {
public:
	void Test() {
		cout << "Test D\n\n";
	}
};

// reinterpret_cast
void test2() {
	long x;
	char* str = (char*)"This is string";
	x = reinterpret_cast<long>(str);
	cout << x;
}
// static_cast
void test3() {
	double d = static_cast<double>(5)/6;
	double d1 = (double)5/6;
}

//auto_ptr
class Temp {
public:
	Temp() {
		cout << "Temp\n\n";
	}
	~Temp() {
		cout << "~Temp\n\n";
	}
	void Test() {
		cout << "Test\n\n";
	}
};

#include <vector>
//vector();
//vector(size_t num, const T& val);
//vector(vector obj);
//vector(InIter start, InIter end, Allocator& a);

// void assign(InIter start, InIter end);
// void assign(size_t num, const T& val);
// reference at(size_t i);
// reference back();
// iterator begin(); reverse_iterator rbegin();
// iterator end(); reverse_iterator rend();
// size_t capacity();
// void clear();
// bool empty();
// iterator erase(iterator i); iterator erase(iterator start, iterator end);
// reference front();
// iterator insert(iterator i, const T& val);
// void pop_back();
// void push_back(const T& val);
// void reserve(size_t num);
// size_t size();
// void swap()
void func_vector() {
	vector<int> vect;

	cout << "Capacity = " << vect.capacity() << endl
		<< "Size = " << vect.size() << endl;
	vect.resize(4, 0);
	cout << "Resize = " << vect.size() << endl;
	for (int i = 0; i < vect.size(); i++) {
		vect[i] = i + 5;
		cout << vect[i] << " ";
	}
	cout << endl;
	cout << "Capacity = " << vect.capacity() << endl;
	cout << "Max size byte = " << vect.max_size() / 4 << endl;
	vect.push_back(55);
	for (int i = 0; i < vect.size(); i++) {
		cout << vect[i] << " ";
	}
	cout << endl;

	vector<int>::reverse_iterator i_riter = vect.rbegin();
	cout << "Reverse iterator:\n";
	for (int i = 0; i < vect.size(); i++) {
		cout << *(i_riter + i) << " ";
	}
	cout << endl;

	for (int i : vect)
	{
		cout << i;
	}



}

#include <list>
// void merge();
// pop_back(); pop_front();
// reverse()
// sort();
// unique();
typedef list<int> ourList;
void ShowLists(ourList& l1, ourList& l2) {
	ourList::iterator iter;

	cout << "\n---------------------------------\n";
	cout << "list 1:\n";
	for (iter = l1.begin(); iter != l1.end(); iter++) {
		cout << *iter << " ";
	}
	cout << endl;
	cout << "list 2:\n";
	for (iter = l2.begin(); iter != l2.end(); iter++) {
		cout << *iter << " ";
	}
	cout << "\n---------------------------------\n\n";
}
void func_list() {
	ourList list1, list2;
	for (int i = 0; i < 6; i++) {
		list1.push_back(i);
		list2.push_front(i);
	}
	ShowLists(list1, list2);

	list2.splice(list2.end(), list2, list2.begin());
	list1.reverse();
	ShowLists(list1, list2);

	list1.sort();
	list2.sort();
	ShowLists(list1, list2);

	list1.merge(list2);
	ShowLists(list1, list2);

	list1.unique();
	ShowLists(list1, list2);
}

#include <map>
// count(const key_type& key);
// iterator find(const key_type& key);
void func_map() {
	map<int, int> our_map;
	vector<int> our_vector;

	cout << "max Size  vector = " << our_vector.max_size() / sizeof(int) << endl
		<< "max Size map = " << our_map.max_size() / sizeof(int) << endl;

	int val;
	int key;
	cin >> val >> key;
	pair<int, int> element(key, val);
	our_map.insert(element);

	cout << "Count element = " << our_map.size() << endl;

	map<int, int>::iterator iter = our_map.begin();
	for (; iter != our_map.end(); iter++) {
		cout << "Key - " << iter->first << " Value - " << iter->second << endl;
	}

	cin >> key >> val;
	pair<map<int, int>::iterator, bool> err = our_map.insert(make_pair(key, val));
	if (err.second == false) {
		cout << "Error!!!\n";
	}
	for (iter = our_map.begin(); iter != our_map.end(); iter++) {
		cout << "Key - " << iter->first << " Value - " << iter->second << endl;
	}
}

int main()
{
	/*int x = 10;
	cout << x << endl;
	test(&x);
	cout << x << endl;*/

	/*B* ptr_B, obj_B;
	D* ptr_D, obj_D;

	ptr_D = dynamic_cast<D*>(&obj_D);
	if (ptr_D) {
		cout << "Ok...\n";
		ptr_D->Test();
	}
	else cout << "Error\n\n";

	ptr_B = dynamic_cast<B*>(&obj_D);
	if (ptr_B) {
		cout << "Ok...\n";
		ptr_B->Test();
	}
	else cout << "Error\n\n";

	ptr_B = dynamic_cast<B*>(&obj_B);
	if (ptr_B) {
		cout << "Ok...\n";
		ptr_B->Test();
	}
	else cout << "Error\n\n";

	ptr_D = dynamic_cast<D*>(& obj_B);
	if (ptr_D) {
		cout << "Ok...\n";
		ptr_D->Test();
	}
	else cout << "Error\n\n";*/

	// контейнер
	// алгоритм 
	// итератор
	// функтор
	// аллокатор
	// предикат

	/*auto_ptr<Temp> ptr1(new Temp), ptr2;
	ptr2 = ptr1;
	ptr2->Test();

	Temp* ptr = ptr2.get();
	ptr->Test();
	delete[]ptr;*/
	//func_vector();
	//func_list();
	func_map();
}