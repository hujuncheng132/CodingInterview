/*
面试题1：赋值运算符函数
*/
#include<cstring>
#include<iostream>

using namespace std;

class myString
{
public:
	myString(char* pData = nullptr);
	myString(const myString& otherString);
	~myString();
	myString& operator = (const myString& otherString);
	void Print();
private:
	char* m_pData;	 
};

myString::myString(char* pData)
{
	if(pData == nullptr)
	{
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else
	{
		m_pData = new char[strlen(pData)+1];
		strcpy(m_pData,pData);
	}
}

myString::myString(const myString& otherString)
{
	m_pData = new char[strlen(otherString.m_pData)+1];
	strcpy(m_pData,otherString.m_pData);
}

myString::~myString()
{
	delete[] m_pData;
}

//存在内存分配不足的问题
myString& myString::operator = (const myString& otherString)
{
	//首先判断二者是否为同一个对象
	if(this == &otherString)
	{
		return *this;
	}
	
	//首先释放原有的数据内存
	delete[] m_pData;
	m_pData = nullptr;
	//然后根据新对象的大小分配新的内存
	m_pData = new char[strlen(otherString.m_pData)+1];
	//接下来将新对象的内容拷贝到内存
	strcpy(m_pData,otherString.m_pData);

	return *this;
}

void myString::Print()
{
	cout << m_pData << endl;
}

//==================测试代码=====================

void Test()
{
	char* text = "hello world";
	myString str1(text);//默认构造函数
	myString str2;//默认构造函数
	str1.Print();
	str2.Print();
	str2 = str1;//赋值运算函数
	str2.Print();
	str1 = str1;//赋值运算函数(自己赋值给自己)
	str1.Print();
	
	return;
}

int main()
{
	Test();
	return 0;
}
