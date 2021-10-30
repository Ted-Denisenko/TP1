#pragma once
#include "All_headers.h"

class Heroes: public Heroes_and_Villains
{
	// Для каждого героя определено : имя, тип оружия, основные навыки(несколько).
private:
	string name{ 0 };
	string weaponType{ 0 };
	string mainSkill{ 0 };
	string sideSkill{ 0 };
public:
	// конструктор без параметров(по умолчанию)
	Heroes();
	// конструктор с параметрами
	Heroes(string _name, string _weaponType, string _mainSkill, string _sideSkill);
	 // конструктор копирования
	Heroes(const Heroes& hero);
	~Heroes();

	void setName(string _name);
	void setWeaponType(string _weaponType);
	void setMainSkill(string _mainSkill);
	void setSideSkill(string _sideSkill);
	
	string getName() const;
	string getWeaponType() const;
	string getMainSkill() const;
	string getSideSkill() const;


	virtual void editUnit() override;
	virtual void editStats(int num_str, string new_stat);
	void showUnit() override;
	virtual void saveToFile() override;
};

