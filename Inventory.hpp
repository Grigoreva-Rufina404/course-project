#pragma once

#include "Item.hpp"

class Inventory {
private:
	Item** m_items;
	int m_count{ 0 };
	int m_capacity;

public:
	Inventory(int capacity);
	~Inventory();

	void AddItem(Item& item);
	void RemoveItem();
	void ShowInventory();
};
