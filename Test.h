#pragma once
#include "Singleton.h"
#include "iostream"
using namespace std;
class Test : public Singleton<Test>
{
	friend class Singleton<Test>;
private:
	Test() {};
	~Test() {};

public:
	int s = 31;
};


