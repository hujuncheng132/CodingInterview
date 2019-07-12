/*
面试题1：赋值运算符函数
如下为类型myString的声明，请为该类型添加赋值运算符函数
*/
#include<cstring>
#include<iostream>

using namespace std;

class myString
{
public:
	myString(); 
	myString(const char *pData); 
	myString(const myString& otherString); 
	~myString(); 
	myString& operator=(const myString& otherString); //赋值运算符
	void Print();
private:
	char* m_pData;	 
};

myString::myString()
{
	m_pData = new char[1];
	m_pData[0] = '\0';
}

myString::myString(const char* pData)
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
myString& myString::operator=(const myString& otherString)
{
	//首先判断二者是否为同一个对象
	if(this == &otherString)
	{
		return *this;
	}
	
	//首先释放原有的数据内存
	delete[] m_pData;
	m_pData = nullptr;
	//然后根据新对象的大小分配新的内存（如果内存不足导致分配失败，则m_pData将是一个空指针，违背了异常安全性原则）
	m_pData = new char[strlen(otherString.m_pData)+1];
	//接下来将新对象的内容拷贝到内存
	strcpy(m_pData,otherString.m_pData); //因为C++的访问控制是class-level而不是object-level，因此可以直接在类内访问同类对象的私有成员

	return *this;
}

//实现异常安全性（先用new分配新的内容，再delete释放已有的内容）
myString& myString::operator=(const myString& otherString)
{
        //首先判断二者是否为同一个对象
        if(this == &otherString)
        {
                return *this;
        }

        //首先根据新对象的大小分配新的内存（此时即使内存分配失败也不会造成原有对象的有效状态失效）
        char *pData = new char[strlen(otherString.m_pData)+1];
	//首先释放原有的数据内存
        delete[] m_pData;
        m_pData = p_Data;

        //接下来将新对象的内容拷贝到内存
        strcpy(m_pData,otherString.m_pData); //因为C++的访问控制是class-level而不是object-level，因此可以直接在类内访问同类对象的私有成员

        return *this;
}

//实现异常安全性（先创建一个临时实例，再交换临时实例和原来的实例）
myString& myString::operator=(const myString& otherString)
{
        //首先判断二者是否为同一个对象
        if(this != &otherString)
	{
		myString strTemp(otherString); //创建一个临时实例
		
		// 通过交换指针来交换两个对象的内容（原m_pData指针由临时实例离开作用域时自动负责释放）
		char *pData = strTemp.m_pData;
		strTemp.m_pData = m_pData;
		m_pData = pData;
        }

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
