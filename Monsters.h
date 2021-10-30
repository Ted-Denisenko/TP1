#pragma once
#include "All_headers.h"

class Monsters : public Heroes_and_Villains
{
	// Для каждого монстра : наименование, описание внешнего вида.
private:
	string name{ 0 };
	string appearence{ 0 };
public:
	// конструктор без параметров(по умолчанию)
	Monsters();
	// конструктор с параметрами
	Monsters(string _name, string _appearence);
	Monsters(const Monsters& monster);
	~Monsters();

	void setName(string _name);
	void setAppearence(string _appearence);
	string getName();
	string getAppearence();

	virtual void editUnit() override;
	virtual void editStats(int num_str, string new_stat) override;
	void showUnit() override;
	virtual void save() override;
};

