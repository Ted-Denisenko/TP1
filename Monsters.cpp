#include "All_headers.h"

Monsters::Monsters()
{
	std::cout << "Default ctor: Monsters" << std::endl;
	name = "Default name";
	appearence = "Default appearence";
}

Monsters::Monsters(string _name, string _appearence) :
	name(_name), appearence(_appearence)
{
	std::cout << "Default ctor: Monsters" << std::endl;
}

Monsters::Monsters(const Monsters& monster) :
	name(monster.name),
	appearence(monster.appearence)
{
	std::cout << "Copy ctor: Monsters" << std::endl;
}

Monsters::~Monsters()
{
	std::cout << "Dtor: Monsters" << std::endl;
}

//сеттеры
void Monsters::setName(string _name) { this->name = _name; }
void Monsters::setAppearence(string _appearence) { this->appearence = _appearence; }
//геттеры
string Monsters::getName() { return this->name; }
string Monsters::getAppearence() { return this->appearence; }

void Monsters::editUnit()
{
	cout << "------------------------------------" << endl;
	cin.ignore(32767, '\n');
	cout << "Unit: Monster" << endl;
	cout << "Input new name: ";
	getline(cin, name);
	cout << "Input new appearence: ";
	getline(cin, appearence);
	cout << "Editting finished" << endl;
	cout << "------------------------------------" << endl;
}
void Monsters::editStats(int num_str, string new_stat)
{
	switch (num_str)
	{
	case 1:
		this->name = new_stat;
		break;
	case 2:
		this->appearence = new_stat;
		break;
	default:
		throw "Incorrect number of string!";
		break;
	}
}
void Monsters::showUnit()
{
	std::cout << "Monster: " << name << std::endl;
	std::cout << "Appearence: " << appearence << std::endl << std::endl;
	return;
}
void Monsters::save()
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
		outfile << 3 << endl << name << endl << appearence;
		outfile.close();
	}
}
