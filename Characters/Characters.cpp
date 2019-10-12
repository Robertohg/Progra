// Characters.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
using namespace std;

class Character {
public:
	Character();
	string m_ClassName;
	string m_Name;
	int m_WeaponRange;
	int m_level;
	int m_ExpPoints;
	virtual void setName() = 0;

};

Character::Character() {
	m_Name = "Default";
	m_ClassName = "Default";
	m_WeaponRange = 0;
	m_level = 1;
	m_ExpPoints = 0;
}
class Figther : public Character {
public:
	Figther();
	int m_Armor;
	string m_Weapon;
	int m_Strength;
	void setName();
	void setArmor(int t_Armor) { this->m_Armor = t_Armor; }
};
Figther::Figther() {
	m_ClassName = "Fighter";
	m_Name = "Default";
	m_WeaponRange = 1;
	m_level = 1;
	m_ExpPoints = 0;
	m_Armor = 4;
	m_Strength = 16;
	m_Weapon = "Sword";
}
void Figther::setName() {
	cout << "Ingrese nombre" << endl;
	cin >> this->m_Name;
}
class Wizard :public Character {
	Wizard();
	int m_MagicArmor;
	string m_Spell;
	int m_Intelligence;
	void setName();
	void setIntelligence(int t_Intelligence) { m_Intelligence = t_Intelligence; }

};
Wizard::Wizard() {
	m_ClassName = "Wizard";
	m_Name = "Default";
	m_WeaponRange = 6;
	m_level = 1;
	m_ExpPoints = 0;
	m_MagicArmor = 2;
	m_Intelligence = 18;
	m_Spell = "Fire Ball";
}
void Wizard::setName() {
	cout << "Ingrese nombre" << endl;
	cin >> this->m_Name;
}
int main()
{
	Figther PC1;
	PC1.setArmor(10);
	cout << PC1.m_Armor << endl;

}

