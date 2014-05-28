#pragma once
#include <mutex>


class Singleton
{
public:
	static Singleton* getInstance();

private:
	static Singleton* instance;
	static std::mutex lockGetInstance;

protected:
	Singleton();


};

