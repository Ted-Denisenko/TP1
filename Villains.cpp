#include "All_headers.h"

Villains::Villains()
{
	std::cout << "Default ctor: Villains" << std::endl;
	name = "Volan";
	weaponType = "Magic wand";
	mainSkill = "Perma-kill";
	sideSkill = "Teleport";
}

Villains::Villains(string _name,
	string _weaponType,
	string _crime,
	string _habitat,
	string _mainSkill,
	string _sideSkill) :
	name(_name),
	weaponType(_weaponType),
	crime(_crime),
	habitat(_habitat),
	mainSkill(_mainSkill),
	sideSkill(_sideSkill)
{
	std::cout << "Argument ctor: Villains" << std::endl;
}

Villains::Villains(const Villains& villain) :
	name(villain.name),
	weaponType(villain.weaponType),
	crime(villain.crime),
	habitat(villain.habitat),
	mainSkill(villain.mainSkill),
	sideSkill(villain.sideSkill)
{
	std::cout << "Copy ctor: Villains" << std::endl;
}

Villains::~Villains()
{
	std::cout << "Detor: Villains" << std::endl;
}

// сеттеры
void Villains::setName(string _name) { this->name = _name; }
void Villains::setWeaponType(string _weaponType) { this->weaponType = _weaponType; }
void Villains::setCrime(string _crime) { this->crime = _crime; }
void Villains::setHabitat(string _habitat) { this->habitat = _habitat; }
void Villains::setMainSkill(string _mainSkill) { this->mainSkill = _mainSkill; }
void Villains::setSideSkill(string _sideSkill) { this->sideSkill = _sideSkill; }
// геттеры
string Villains::getName() { return this->name; }
string Villains::getWeaponType() { return this->weaponType; }
string Villains::getCrime() { return this->crime; }
string Villains::getHabitat() { return this->habitat; }
string Villains::getMainSkill() { return this->mainSkill; }
string Villains::getSideSkill() { return this->sideSkill; }

void Villains::editUnit()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Unit: Villain" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new weapon: ";
	getline(cin, weaponType);
	cout << "Input new crime: ";
	getline(cin, crime);
	cout << "Input new habitat: ";
	getline(cin, habitat);
	cout << "Input new main skill: ";
	getline(cin, mainSkill);
	cout << "Input new side skill: ";
	getline(cin, sideSkill);
	cout << "Editting finished" << endl;
	cout << "------------------------------------" << endl;
}
void Villains::editStats(int num_str, string new_stat)
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
		this->crime = new_stat;
		break;
	case 4:
		this->habitat = new_stat;
		break;
	case 5:
		this->mainSkill = new_stat;
		break;
	case 6:
		this->sideSkill = new_stat;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}
void Villains::showUnit()
{
	std::cout << "Villain: " << name << std::endl;
	std::cout << "Weapon: " << weaponType << std::endl;
	std::cout << "Crime: " << crime << std::endl;
	std::cout << "Habitat: " << habitat << std::endl;
	std::cout << "Main skill: " << mainSkill << std::endl;
	std::cout << "Side skill: " << sideSkill << std::endl;
	return;
}
void Villains::save()
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
		outfile << 2 << endl << name << endl << weaponType << endl << crime << endl << habitat << endl << mainSkill << endl << sideSkill << endl;
		outfile.close();
	}
}
