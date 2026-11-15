#pragma once

#include <string>

#include "BaseItem.hpp"

class Weapon : public BaseItem {
private:
	int m_damage;

public:
	Weapon(std::string name, int damage);
	Weapon();

	~Weapon() override;

	void Use() const override;
	void Inspect() const override;

	std::unique_ptr<BaseItem> Clone() const override;
};