#include <iostream>
#include <utility>

#include "Weapon.hpp"

Weapon::Weapon(std::string name, int damage) : BaseItem(std::move(name)), m_damage{ damage } {
	std::cout << "The weapon created: " << m_name << '\n';

	if (damage < 0) {
		std::cout << "ERROR: Damage cannot be negative. Damage is set to 0 by default." << '\n';
		m_damage = 0;
	}
}

Weapon::Weapon() : BaseItem(), m_damage{ 5 } {
	std::cout << "The weapon created: " << m_name << '\n';
}

Weapon::~Weapon() {
	std::cout << "The weapon is destroyed: " << m_name << '\n';
}

void Weapon::Use() const {
	std::cout << "You used the weapon: " << m_name << '\n';
	std::cout << "Damage has been caused: " << m_damage << '\n';
}

void Weapon::Inspect() const {
	std::cout << "Weapon: " << m_name << '\n';
	std::cout << "Damage: " << m_damage << '\n';
}

std::unique_ptr<BaseItem> Weapon::Clone() const {
	return std::make_unique<Weapon>(*this);
}