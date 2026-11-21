#include <iostream>
#include <utility>

#include "Weapon.hpp"

// Конструктор с параметрами
Weapon::Weapon(std::string name, int damage) : BaseItem(std::move(name)), m_damage{ damage } {
	std::cout << "The weapon created: " << m_name << '\n';

	if (damage < 0) {
		std::cout << "ERROR: Damage cannot be negative. Damage is set to 0 by default." << '\n';
		m_damage = 0;
	}
}

// Конструктор по умолчанию
Weapon::Weapon() : BaseItem(), m_damage{ 5 } {
	std::cout << "The weapon created: " << m_name << '\n';
}

// Деструктор
Weapon::~Weapon() {
	std::cout << "The weapon is destroyed: " << m_name << '\n';
}

// Выводит информацию об использовании оружия и наносимом уроне
void Weapon::Use() const {
	std::cout << "You used the weapon: " << m_name << '\n';
	std::cout << "Damage has been caused: " << m_damage << '\n';
}

// Формирует описание оружия
std::string Weapon::Describe() const {
	return BaseItem::Describe() +
		", damage: " + std::to_string(m_damage);
}

// Создаёт полную копию текущего объекта Weapon
std::unique_ptr<BaseItem> Weapon::Clone() const {
	return std::make_unique<Weapon>(*this);
}