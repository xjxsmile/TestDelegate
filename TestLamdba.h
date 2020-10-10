#pragma once
#include <iostream>
#include <functional>
#include <algorithm>
#include <string>
#include <vector>

using namespace std; 
class Test
{
public:
	std::function<bool(int)> getfile(){
		return [=](int value){return value*disver;};
	}

	void TestF();
	/*std::vector<int> aa(10);
	vector<int> abc(10,1);*/
	//vector<int> v {1, 3, 5, 2, 6, 10};
	//int a = 0;
	//int b = 1;
	//int sumval=0;
	//std::generate(v.begin(), v.end(), [&a, &b] { int value = b; b = b + a; a = value; return value; });
	//string chars(30, ' ');// 30 space characters
	//char ch{ 'a' };
	//int incr{};
	//std::generate(std::begin(chars), std::end(chars), [ch, &incr]
	//{
	//	incr += 3;
	//	return ch + (incr % 26); })；
	//	std::cout << chars << std: : endl;
		
private:
	int disver=10;
};
class MeanValue
{
public:
	MeanValue() : num{ 0 }, sum{ 0 } {}

	void operator()(int e)
	{
		++num;
		sum += num;
	}

	double value()
	{
		return static_cast<double>(sum) / static_cast<double>(num);
	}
private:
	int num;
	int sum;
};

class TestClass {
public:
	void TestFunction(const std::string  s,std::string s1){
		cout<<"S:"<<s<<" S1"<<s1<<endl;
	}


};


std::string TestFunction2(const std::string s){
	cout<<"S1:"<<s<<endl;
	std::string sa=s+std::string("ssssssssffff");
	return sa;
}
int mainLamdba(){

	Test *t=new Test();

	vector<int> v1(10);
	int a = 0;
	int b = 1;
	//std::generate(v.begin(), v.end(), [&a, &b] { int value = b; b = b + a; a = value; cout<<b <<" ";return value; });
	
	int x = 4;
	auto y = [&r = x, x = x + 1]{ r += 2; return x * x; }();
	cout<<x<<"  "<<y<<endl;

	vector<int> v{ 1, 3, 5, 7 };
	MeanValue mv = std::for_each(v.begin(), v.end(), MeanValue{});
	cout << mv.value() << endl;  // output: 2.5

	std::function<void(const std::string,const std::string)> ff;
	TestClass test;

	ff=std::bind(&TestClass::TestFunction,&test,std::placeholders::_2,std::placeholders::_1);
	std::string str("aaaa");
	std::string str222("rrrrrrrrrr");
	ff(str,str222);

	std::function<std::string(const std::string)>  fs;
	fs=std::bind(&TestFunction2,std::placeholders::_1);
	std::string strs("BBBB");
	std::string ts=fs(strs);
	cout<<"TS"<<ts<<endl;


	return 0;
}