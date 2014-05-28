#include "singleton.h"
#include <iostream>


Singleton* Singleton::instance = nullptr;
std::mutex Singleton::lockGetInstance;

Singleton::Singleton()
{
	std::cout << "single instance has been created!";
}

Singleton* Singleton::getInstance()
{
	if (instance == nullptr)
	{
		lockGetInstance.lock();
		
		if (instance == nullptr)
			instance = new Singleton();

		lockGetInstance.unlock();
	}

	return instance;
}

