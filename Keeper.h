#pragma once
#include "All_headers.h"
class Keeper
{
private:
	int m_size = 0;
	Element* head = NULL;
	/*
	���������� � �������� ����������� �������� ������������ ������ Base (������� ����� ������������ �������� �������� �������);
	������ ���������� ���� � �����;
	������ �������������� ���� �� �����.
	*/
public:
	Keeper();
	Keeper(int size);
	~Keeper();

	Heroes_and_Villains* operator[] (int index);
	void insert(Heroes_and_Villains* n_data);
	int getSize();
	void add(Heroes_and_Villains* n_data);
	void remove(int index);
	void saveToFile();
	void load();
};

