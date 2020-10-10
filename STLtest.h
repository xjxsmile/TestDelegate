#pragma once
#include "string"
#include <vector>
#include <algorithm>
#include <iostream>
#include <list>
#include <deque>
#include <assert.h>
#include <functional>

using namespace std;

int g_constructCount = 0;
int g_copyConstructCount = 0;
int g_destructCount = 0;

class STLtest
{
public:
	STLtest(){
		cout<< "STLtest无参："<<++g_constructCount<<endl;
	}

	STLtest(const STLtest& a) {
		cout << "STLtest有参：" << ++g_copyConstructCount << endl;
	}

	~STLtest(){
		cout<< "STLtest析构："<<++g_destructCount<<endl;
	}

	void testA(int & a){
		cout<< "testA  &"<<endl;
	}
	void testA(int && a) {
		cout << "testA  &&" << endl;
	}
};

STLtest getSTLtest(){
	return STLtest();
}

/************使用C++模拟ue4的代理***********/


struct A
{
	A() {
		cout << "construct: " << ++g_constructCount << endl;
	}

	A(const A& a)
	{
		cout << "copy construct: " << ++g_copyConstructCount << endl;
	}
	~A()
	{
		cout << "destruct: " << ++g_destructCount << endl;
	}
};

A GetA()
{
	return A();
}

static int testright(int && a) {
	return a++;
}


template <typename T>
void foo(const T & container) {
	typename T::iterator c; //未加typename, 报错
	//++iter;
	//int value = *iter;
	//std::cout << value;


}

int mainSTL(){


return 0;

#if 0
	A a = GetA();

	int i = 0;
	int j = std::move(i);

	assert(i == j);
#endif

	#if 0
	
	int a = 0;
	cout << testright(a + 1) << endl;

	STLtest* st=new STLtest();

	int Asd=1;
	st->testA(Asd);
	st->testA(1);

	vector<string> vec;
	vec.reserve(5);
	vec.push_back("hello,");
	vec.insert(vec.end(), { "how","are","you","?" });
	cout << "capacity:" << vec.capacity() << endl;
	copy(vec.cbegin(), vec.cend(), ostream_iterator<string>(cout, " "));
	cout << endl;

	swap(vec[1], vec[3]);
	vec.insert(find(vec.begin(), vec.end(), "?"), "always");
	vec.back() = "!";

	copy(vec.cbegin(), vec.cend(), ostream_iterator<string>(cout, " "));
	cout << endl;

	cout << "size:" << vec.size() << endl;
	cout << "capacity:" << vec.capacity() << endl;

	deque<string> que;
	que.push_back("a");
	que.push_back("33");
	que.push_back("fdg");
	que.push_back("fdg");
	que.push_back("gfh");
	que.push_back("fhgd");
	que.push_back("jg");

	deque<string>::iterator iterque;
	for (iterque=que.begin();iterque!=que.end();++iterque)
	{
		size_t offer=distance(que.begin(),iterque);
		cout<<"xiabiao :"<<offer<<"  "<<*iterque<<endl;
	}
	#endif

#if 0
	std::list<int> coll = { 1,2,3,4,5 }; //c++11
	std::vector<int> coll2;

	for (int i=20;i<40;i++)
	{
		coll2.push_back(i);
	}

	for (std::vector<int>::iterator a=coll2.begin();a!=coll2.end();++a)
	{
		if (*a == 29)
		{
			a=coll2.erase(a);
			std::cout<<*a<<std::endl;
		}
	}
#endif

#if  0
	
	std::vector<int> coll;
	coll.push_back(2);
	coll.push_back(5);
	coll.push_back(4);
	coll.push_back(1);
	coll.push_back(6);
	coll.push_back(3);

	std::list<char> temp;
	for (char c = 'a'; c <= 'z'; ++c) {
		temp.push_back(c);
	}
	for (std::list<char>::iterator pos = temp.begin(); pos != temp.end(); ++pos) {
		*pos = 'a';
		std::cout << *pos << std::endl;
	}
	for (std::list<char>::const_iterator pos = temp.begin(); pos != temp.end(); ++pos) {
		//*pos = 'a';
		std::cout << *pos <<std::endl;
	}

	std::vector<int>::const_iterator minpos = min_element(coll.begin(), coll.end());
	std::cout << "min: " << *minpos << std::endl;
	std::vector<int>::const_iterator maxpos = max_element(coll.begin(), coll.end());
	std::cout << "max: " << *maxpos << std::endl;


	std::list<int> state={2,5,6,1,6,3};
	state.sort();


	std::list<int> coll1;
	for (int i = 20; i < 40; ++i) {
		coll1.push_back(i);
	}
	std::list<int>::iterator pos25, pos35;
	
	pos25 = find(coll1.begin(), coll1.end(), 25);
	pos35 = find(coll1.begin(), pos25, 35);

	std::cout << "max: " << *max_element(pos25, pos35) << std::endl;
	std::cout << "max: " << *max_element(pos25, ++pos35) << std::endl;


	return 0;
	

#endif //  0
}
