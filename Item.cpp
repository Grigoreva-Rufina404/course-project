#include <iostream>
#include "Item.hpp"

Item::Item(std::string name, int damage)
	: m_name{ name }
	, m_damage{ damage }
{
	if (damage < 0) {
		std::cout << "ERROR: Damage cannot be negative. Damage is set to 0 by default." << '\n';
		m_damage = 0;
	}
}

Item::~Item() {
	std::cout << "The object is destroyed: " << m_name << '\n';
}

void Item::Inspect() {
	std::cout << "Item: " << m_name << '\n';
	std::cout << "Damage: " << m_damage << '\n';
}

void Item::Use() {
	std::cout << "You used the item: " << m_name << '\n';
	std::cout << "Damage has been caused: " << m_damage << '\n';
}