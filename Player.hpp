#pragma once
#include <string>
#include "Inventory.hpp"

class Player{
private:
	std::string m_name;
	int m_health;
	Inventory m_inventory;

public:
	Player(std::string name, int health, int inventory);
	~Player();

	void TakeDamage(int damage);
	void Heal(int heal);
	void AddItem(Item& item);
	void ShowInventory();
};
