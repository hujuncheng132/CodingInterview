/*
第二题：单例模式(meyer大师版)
*/
#include<iostream>
class Singleton 
{
public:
	static Singleton* getInstance()//将获取单例对象的函数定义为静态函数，这样就不依赖于具体的对象
	{
		// C++11规定了当一个线程正在初始化一个变量的时候，其他线程必须得等到该初始化完成以后才能访问它
		static Singleton single;//静态变量只会初始化一次，而且C++11保证线程安全，在程序结束时其会自动调用析构函数进行销毁
		return &single;
	}
	
private:
	Singleton();
	~Singleton();
};


Singleton::Singleton()
{
        std::cout << "构造函数" << std::endl;
}


Singleton::~Singleton()
{
	std::cout << "析构函数" << std::endl;
}

int main()
{
	Singleton *s1 = Singleton::getInstance();
	Singleton *s2 = Singleton::getInstance();
}
