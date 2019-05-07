/*
第二题：单例模式(meyer大师版)
*/
#include<iostream>
#include<cstring>

using namespace std;

class myString
{
public:
	static myString& getInstance(char *p_Data = nullptr)//将获取单例对象的函数定义为静态函数，这样就不依赖于具体的对象
	{
		static myString str(p_Data);//静态变量只会初始化一次，而且C++11保证线程安全，在程序结束时才被销毁
		return str;
	}
	void Print();
private:
	
	myString(char *p_Data = nullptr);//构造函数设为私有
	myString(const myString& str);//拷贝构造函数设为私有
	myString& operator = (const myString& str);//赋值运算符函数设为私有
	~myString();
	char* m_pData;
};

myString::~myString()
{
	cout << "析构函数" << endl;
	delete[] m_pData;
}

myString::myString(char *p_Data)
{
	if(p_Data == nullptr)
	{
		m_pData = new char[0];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(p_Data)+1];
		strcpy(m_pData,p_Data);
	}
}

void myString::Print()
{
	cout << m_pData << endl;
}
//=============测试代码=====================
void Test()
{

	{
		char *p_Data = "hello world";
		myString &str1 = myString::getInstance(p_Data);//第一次调用getInstance时初始化静态局部变量
		p_Data = "hello";
		myString &str2 = myString::getInstance(p_Data);//第二次调用getInstance时不再初始化静态局部变量
		str1.Print();
		str2.Print();
	}
	char *p_Data = "hello";//静态局部变量在程序退出时才销毁，此时调用getInstance依然得到的是“hello world”
	myString &str3 = myString::getInstance(p_Data);
	str3.Print();
}

int main()
{
	Test();
	return 0;
}
