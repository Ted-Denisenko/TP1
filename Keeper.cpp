#pragma warning( disable : 6386 )
#pragma warning( disable : 26451 )
#include "All_headers.h"

Keeper::Keeper() : m_size(0), head(nullptr) {}
Keeper::Keeper(int size) : head(nullptr) { this->m_size = size; }
Keeper::~Keeper()
{
	if (head != NULL)
	{
		Element* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Heroes_and_Villains();
			delete(buffer);
		}
		head->m_data->~Heroes_and_Villains();
		delete(head);
	}
}

Heroes_and_Villains* Keeper::operator[] (const int index)
{
	if ((index >= m_size) || (index < 0))
	{
		throw "Incorrect index!";
	}
	else
	{
		Element* buffer = head;
		for (int i = 0; i < m_size - index - 1; i++)
		{
			buffer = buffer->next;
		}
		return (buffer->m_data);
	}
}

void Keeper::insert(Heroes_and_Villains* n_data)
{
	Element* tmp;
	tmp = new Element;

	if (m_size == 0)
	{
		tmp->m_data = n_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = n_data;
		tmp->next = head;
		++m_size;
	}

	head = tmp;
}

int Keeper::getSize() { return m_size; }

void Keeper::add(Heroes_and_Villains* n_data)
{
	Element* tmp = new Element;

	if (m_size == 0)
	{
		tmp->m_data = n_data;
		tmp->next = 0;
		++m_size;
	}
	else
	{
		tmp->m_data = n_data;
		tmp->next = head;
		++m_size;
	}

	head = tmp;
}

void Keeper::remove(int index)
{
	if (m_size == 0)
	{
		throw "There's nothing to delete!";
		system("pause");
	}
	int counter = 0;
	while (counter < index - 1)
	{
		head = head->next;
		counter++;
	}

	Element* prev = head;
	prev->next->m_data->~Heroes_and_Villains();
	prev->next->next;
	delete(prev->next);
	--m_size;
}

void Keeper::saveToFile()
{
	ofstream outfile;
	string initfile = "data.txt";
	outfile.open(initfile);
	if (!outfile)
	{
		throw "Error opening file!";
		system("pause");
		exit(1);
	}
	else
	{
		outfile << m_size << endl;
		outfile.close();
	}

	Element* buffer = head;
	for (int i = 0; i < m_size; i++)
	{
		buffer->m_data->save();
		buffer = buffer->next;
	}
}

void Keeper::load()
{
	if (m_size != 0)
	{
		Element* buffer;
		while (head->next != NULL)
		{
			buffer = head;
			head = head->next;
			buffer->m_data->~Heroes_and_Villains();
			delete(buffer);
		}
		head->m_data->~Heroes_and_Villains();
		delete(head);
	}


	ifstream infile;
	int read_size, num_character; //
	string a, b, c, d, e, f, g; //
	string initfile = "data.txt";
	Heroes_and_Villains* character;

	infile.open(initfile);
	if (!infile)
	{
		throw "Error opening!";
		system("pause");
		exit(1);
	}

	infile >> read_size; //

	for (int i = 0; i < read_size; i++)
	{
		infile >> num_character; //
		infile.ignore(32767, '\n');

		if (num_character == 1) //
		{
			//infile >> a >> b >> c >> d >> e;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			Heroes* hero;
			hero = new Heroes;
			hero->setName(a);
			hero->setWeaponType(b);
			hero->setMainSkill(c);
			hero->setSideSkill(d);
			character = hero;
			insert(character);
		}

		if (num_character == 2) //
		{
			//infile >> a >> b >> c >> d >> e >> f >> g;

			getline(infile, a);
			getline(infile, b);
			getline(infile, c);
			getline(infile, d);
			getline(infile, e);
			getline(infile, f);
			Villains* villain;
			villain = new Villains;
			villain->setName(a);
			villain->setWeaponType(b);
			villain->setCrime(c);
			villain->setHabitat(d);
			villain->setMainSkill(e);
			villain->setSideSkill(f);
			character = villain;
			insert(character);
		}

		if (num_character == 3) //
		{
			//infile >> a >> b >> c;

			getline(infile, a);
			getline(infile, b);
			Monsters* monster;
			monster = new Monsters;
			monster->setName(a);
			monster->setAppearence(b);
			character = monster;
			insert(character);
		}
	}
}
