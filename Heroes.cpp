#include "All_headers.h"

Heroes::Heroes()
{
	std::cout << "Default ctor: Heroes" << std::endl;
	name = "Daan";
	weaponType = "Anti-matter rifle";
	mainSkill = "Take aim";
	sideSkill = "Burst fire";
}

Heroes::Heroes(string _name,
	string _weaponType,
	string _mainSkill,
	string _sideSkill)
	:
	name(_name),
	weaponType(_weaponType),
	mainSkill(_mainSkill),
	sideSkill(_sideSkill)
{
	std::cout << "Argument ctor: Heroes" << std::endl;
}

Heroes::Heroes(const Heroes& hero):
name(hero.name),
weaponType(hero.weaponType),
mainSkill(hero.mainSkill),
sideSkill(hero.sideSkill)
{
	std::cout << "Copy ctor: Heroes" << std::endl;
}

Heroes::~Heroes()
{
		std::cout << "Dtor: Heroes" << std::endl;
}


// сеттеры
void Heroes::setName(string _name) { this->name = _name; }
void Heroes::setWeaponType(string _weaponType) { this->weaponType = _weaponType; }
void Heroes::setMainSkill(string _mainSkill) { this->mainSkill = _mainSkill; }
void Heroes::setSideSkill(string _sideSkill) { this->sideSkill = _sideSkill; }

// геттеры
string Heroes::getName() const { return this->name; }
string Heroes::getWeaponType() const { return this->weaponType; }
string Heroes::getMainSkill() const { return this->mainSkill; }
string Heroes::getSideSkill() const { return this->sideSkill; }

void Heroes::editUnit()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Unit: Hero" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new weapon: ";
	getline(cin, weaponType);
	cout << "Input new main skill: ";
	getline(cin, mainSkill);
	cout << "Input new side skill: ";
	getline(cin, sideSkill);
	cout << "Editting finished" << endl;
	cout << "------------------------------------" << endl;
}

void Heroes::editStats(int num_str, string new_stat)
{
	switch (num_str)
	{
	case 1:
		this->name = new_stat;
		break;
	case 2:
		this->weaponType = new_stat;
		break;
	case 3:
		this->mainSkill = new_stat;
		break;
	case 4:
		this->sideSkill = new_stat;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}

void Heroes::showUnit()
{
	std::cout << "Hero: " << name << std::endl;
	std::cout << "Weapon: " << weaponType << std::endl;
	std::cout << "Main skill: " << mainSkill << std::endl;
	std::cout << "Side skill: " << sideSkill << std::endl;
	return;
}

void Heroes::save()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile, ios_base::app);
	if (!outfile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << 1 << endl << name << endl << weaponType << endl << mainSkill << endl << sideSkill << endl;
		outfile.close();
	}
}
