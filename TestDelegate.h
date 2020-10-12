#pragma once
#include <ctime>
#include <functional>
#include <iostream>
#include <vector>
class TestDelegate
{
};

/************使用C++模拟ue4的代理***********/
/*
typedef int(*FunMethod)(int, int);
class TestA {
public:
	int LessNum(int a, int b) {
		int c = a - b;
		std::cout << "a - b = " << c << std::endl;
		return c;
	}
	void print(){
		std::cout << " TestA::print " << std::endl;
	}
};
typedef int(TestA::* FunLessMethod)(int, int);

//两个参数的单播
class FDelegateTwoParams {
public:
	void BindStatic(FunMethod funPtr, int a, int b) {
		Fun = std::bind(funPtr, a, b);
	}

	void BindRaw(TestA* UserClass, FunLessMethod  funPtr, int a, int b) {
		Fun = std::bind(funPtr, UserClass, a, b);
	}

	bool  IsBound()const {
		return Fun ? true : false;
	}
	void Execute() {
		Fun();
	}
private:
	std::function<int()> Fun;
};

//两个参数的多播
class FDelegateMultiCastTwoParam{
public:
	void AddStatic(FunMethod funPtr,int a,int b){
		MultiyFun.push_back(std::bind(funPtr,a,b));
	}
	void AddBind(TestA * ta,FunLessMethod funPtr,int a,int b){
		MultiyFun.push_back(std::bind(funPtr,ta,a,b));
	}
	void Broadcast(){
		for (std::vector<std::function<int()>>::iterator iter=MultiyFun.begin();iter!=MultiyFun.end();++iter)
		{
			(*iter)();
		}
	}
private:
	std::vector<std::function<int()>> MultiyFun;
};

int AddNum(int a, int b) {
	int c = a + b;
	std::cout << "a + b = " << c << std::endl;
	return c;
}
*/
/************使用C++模拟ue4的代理***********/
/*
int main(){

	FDelegateMultiCastTwoParam MultiTwoParam;
	MultiTwoParam.AddStatic(&AddNum,3,2);
	TestA* ta=new TestA;
	MultiTwoParam.AddBind(ta,&TestA::LessNum,3,3);
	MultiTwoParam.Broadcast();

#if 0
	FDelegateTwoParams deleteparam;

	deleteparam.BindStatic(&AddNum, 3, 2);
	deleteparam.Execute();

	FDelegateTwoParams deletLessParam;
	TestA* ta = new TestA;
	deletLessParam.BindRaw(ta, &TestA::LessNum, 4, 5);
	deletLessParam.Execute();
#endif
	return 0;
}
*/
/*
class TestA {
public:
	void print() {
		std::cout << " TestA::print " << std::endl;
	}
	void TestTwoParam(int a,int b){
		std::cout<< "a + b = "<<a+b<<std::endl;
		//return 0;
	} 
};
typedef void(TestA::*FunLessMethod)(void);
typedef void(TestA::*FunTwoMethod)(int,int);
using FunTwoMethods = int (TestA::*)(int,int);

#define DECLARE_DELEGATE_TWOPARAM(DelegateNameTwo,ParamType1,ParamType2)\
class DelegateNameTwo {\
public:\
	void BindRaw(TestA* UserClass, FunTwoMethod funPtr,ParamType1 p1,ParamType2 p2) {\
		Fun = std::bind(funPtr, UserClass, p1, p2);\
	}\
	bool  IsBound() {\
		return Fun ? true : false;\
	}\
	void Execute() {\
		Fun();\
	}\
	bool ExecuteIfBound(){\
		if (IsBound())\
		{\
			Execute();\
			return true;\
		}\
		return false;\
	}\
private:\
	std::function<int()> Fun;\
};

#define DECLARE_DELEGATE(DelegateName)\
class DelegateName {\
public:\
	void BindRaw(TestA* UserClass, FunLessMethod funPtr) {\
		Fun = std::bind(funPtr, UserClass);\
	}\
	bool  IsBound() {\
		return Fun ? true : false;\
	}\
	void Execute() {\
		Fun();\
	}\
	bool ExecuteIfBound(){\
		if (IsBound())\
		{\
			Execute();\
			return true;\
		}\
		return false;\
	}\
private:\
	std::function<void()> Fun;\
};



DECLARE_DELEGATE(FTestDelegate);
DECLARE_DELEGATE_TWOPARAM(FTestDelegateTwos,int,int);
*/

template<typename Class,typename FunType>
struct TMemFunPtrType;

//Class 类  RetType返回类型   TrgTypes参数
template<typename Class,typename RetType,typename... TrgTypes>
struct TMemFunPtrType<Class,RetType(TrgTypes...)>
{
	typedef RetType(Class::* TypeName)(TrgTypes...);
};
//typedef void(TestA::*FunTwoMethod)(int,int);
//RetValType返回值类型   ParamTypes参数
template<typename RetValType,typename... ParamTypes>
class TBaseDelegate
{
public:
	template<typename UserClass>
	void BindRaw(UserClass * MyClass,typename TMemFunPtrType<UserClass,RetValType(ParamTypes...)>::TypeName FunPtr,ParamTypes... ValTypes){
			fun=std::bind(FunPtr, MyClass,ValTypes...);
	}
	bool IsBound()const{
		return fun?true:false;
	}
	void Execute(){
		fun();
	}
	bool ExecuteIfBound(){
		if (IsBound())
		{
			fun();
			return true;
		}
		return false;
	}
private:
	std::function<RetValType()> fun;
};
#define DECLARE_DELEGATE(DelegateName) class DelegateName:public TBaseDelegate<void>{};

#define DECLARE_DELEGATE_TwoParam(DelegateName,ParamType1,ParamType2) class DelegateName:public TBaseDelegate<void,ParamType1,ParamType2>{};
#define DECLARE_DELEGATE_RelVal_TwoParam(RelVal,DelegateName,ParamType1,ParamType2) class DelegateName:public TBaseDelegate<RelVal,ParamType1,ParamType2>{};

class SSS {

public:
	void print(){
		std::cout<<"aaaaaaaa"<<std::endl;
	}
	void printAA(int a,int b) {
		std::cout << "bbbbbbbbb" << std::endl;
	}
	float printaaaAA(int a, int b) {
		std::cout << "CCCCCC" << std::endl;
		return 1.f;
	}
};

DECLARE_DELEGATE(FTestDelegate);
DECLARE_DELEGATE_TwoParam(FTestDelegateTwo,int,int);
DECLARE_DELEGATE_RelVal_TwoParam(float,FTestDelegateTwoRelval,int,int);
int main(){

	FTestDelegate td;
	SSS s;
	td.BindRaw(&s,&SSS::print);
	td.Execute();
	FTestDelegateTwo two;
	two.BindRaw(&s,&SSS::printAA,1,4);
	two.Execute();
	FTestDelegateTwoRelval twoRel;
	twoRel.BindRaw(&s,&SSS::printaaaAA,1,4);
	twoRel.Execute();


#if 0
	FTestDelegate Delegate;
	TestA a;
	Delegate.BindRaw(&a,&TestA::print);
	Delegate.Execute();

	FTestDelegateTwos TwoDelegate;
	TwoDelegate.BindRaw(&a, &TestA::TestTwoParam, 4, 5);
	TwoDelegate.Execute();
#endif
	return 0;
}





