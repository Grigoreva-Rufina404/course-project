#pragma once
#include <string>
#include "BaseItem.hpp"

class Weapon : public BaseItem {	//	Оружие

private:
	int m_damage;

public:
	Weapon(std::string name, int damage);
	Weapon();
	~Weapon() override;

	void Use() const override;
	void Inspect() const override;
};