#pragma once
template <typename T>
class Singleton
{
public:
	
	static T& GetInstance()
	{
		static T instance;
		return instance;
	}

public:
	//Disable the Copy_Constructor
	Singleton(Singleton const&) = delete;

	//Disable the extern_input to populate the Singleton
	Singleton& operator=(Singleton const&) = delete;


protected:
	//Disable the Constructor
	Singleton() {}

	//Disable the Destructor
	~Singleton() {}


};

