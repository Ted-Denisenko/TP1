#pragma once
#include <iostream>

using namespace std;

class Heroes_and_Villains
{


public:
	Heroes_and_Villains()
	{
		std::cout << "HaV ctor" << std::endl;
	}
	virtual ~Heroes_and_Villains()
	{
		std::cout << "HaV dtor" << std::endl;
	}
	virtual void showUnit() = 0;
	virtual void editUnit() = 0;
	virtual void saveToFile() = 0;
	virtual void editStats(int num_str, string new_stat) = 0;
};

typedef struct Element
{
	Heroes_and_Villains* m_data;
	Element* next;
} Element;

