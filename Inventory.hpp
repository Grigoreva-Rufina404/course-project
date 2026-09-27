#pragma once

#include "Item.hpp"

class Inventory {
private:
	Item* m_items[2]{};
	int m_count{ 0 };

public:
	Inventory();
	~Inventory();

	void AddItem(Item& item);
	void RemoveItem();
	void ShowInventory();
};
