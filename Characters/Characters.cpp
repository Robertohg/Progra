

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
	virtual void print() = 0;

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
	void print() override;
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
	cout << "Ingrese nombre del guerrero" << endl;
	cin >> this->m_Name;
}
void Figther::print() {
	cout << endl;
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Name = " << this->m_Name << endl;
	cout << "Class = " << this->m_ClassName << endl;
	cout << "Weapon Range = " << this->m_WeaponRange << endl;
	cout << "Level = " << this->m_level << endl;
	cout << "XP = " << this->m_ExpPoints << endl;
	cout << "Armor = " << this->m_Armor << endl;
	cout << "Strength = " << this->m_Strength << endl;
	cout << "Weapon = " << this->m_Weapon << endl;
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
	
}
class Wizard : public Character {
public:
	Wizard();
	int m_MagicArmor;
	string m_Spell;
	int m_Intelligence;
	void setName();
	void setIntelligence(int t_Intelligence) { m_Intelligence = t_Intelligence; }
	void print();
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
void Wizard::print() {
	cout << endl;
	cout << "PLAYER STATS" << endl;
	cout << "============" << endl;
	cout << endl;
	cout << "Name = " << this->m_Name << endl;
	cout << "Class = " << this->m_ClassName << endl;
	cout << "Weapon Range = " << this->m_WeaponRange << endl;
	cout << "Level = " << this->m_level << endl;
	cout << "XP = " << this->m_ExpPoints << endl;
	cout << "Magic Armor = " << this->m_MagicArmor << endl;
	cout << "Intelligence = " << this->m_Intelligence << endl;
	cout << "Spell = " << this->m_Spell << endl;
	cout << endl;
	cout << "END PLAYER STATS" << endl;
	cout << "================" << endl;
	cout << endl;
}
void Wizard::setName() {
	cout << "Ingrese nombre del mago" << endl;
	cin >> this->m_Name;
}
int main()
{

	Figther PC1;
	Wizard PC2;

	PC1.setArmor(10);
	PC1.setName();

	PC2.setName();

	PC2.print();
	PC1.print();
	return 0;
}

