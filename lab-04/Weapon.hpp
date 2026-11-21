#pragma once

#include <string>

#include "BaseItem.hpp"

// Класс оружия
class Weapon : public BaseItem {
private:
	int m_damage;

public:
	Weapon(std::string name, int damage);
	Weapon();

	Weapon(const Weapon& other) = default;
	Weapon(Weapon&& other) noexcept = default;
	Weapon& operator=(const Weapon& other) = default;
	Weapon& operator=(Weapon&& other) noexcept = default;

	~Weapon() override;

	// Реализация использования и описания оружия
	void Use() const override;
	std::string Describe() const override;

	// Создаёт копию объекта Weapon и возвращает её через указатель на базовый класс BaseItem
	std::unique_ptr<BaseItem> Clone() const override;
};