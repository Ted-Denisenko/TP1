#pragma once
#include "All_headers.h"

class Villains : public Heroes_and_Villains
{
	// Для каждого злодея определено : имя, тип оружия, какое злодеяние совершил, где обитает, основные навыки.
private:
	string name{ 0 };
	string weaponType{ 0 };
	string crime{ 0 };
	string habitat{ 0 };
	string mainSkill{ 0 };
	string sideSkill{ 0 };
public:
	// конструктор без параметров(по умолчанию)
	Villains();
	// конструктор с параметрами
	Villains(string _name, string _weaponType, string _crime, string _habitat, string _mainSkill, string _sideSkill);
	// конструктор копирования
	Villains(const Villains& villain);
	~Villains();

	void setName(string _name);
	void setWeaponType(string _weaponType);
	void setCrime(string _crime);
	void setHabitat(string _habitat);
	void setMainSkill(string _mainSkill);
	void setSideSkill(string _sideSkill);

	string getName();
	string getWeaponType();
	string getCrime();
	string getHabitat();
	string getMainSkill();
	string getSideSkill();

	virtual void editUnit() override;
	virtual void editStats(int num_str, string new_stat) override;
	virtual void save() override;
	void showUnit() override;
};

