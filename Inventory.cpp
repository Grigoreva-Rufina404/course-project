#include <iostream>
#include "Inventory.hpp"

Inventory::Inventory() {
	std::cout << "Inventory created\n";
}

Inventory::~Inventory() {
	std::cout << "The inventory is destroyed\n";
}

void Inventory::AddItem(Item& item) {
	if (m_count >= 2) {
		std::cout << "The inventory is full.\n";
	}
	else {
		m_items[m_count] = &item;
		m_count++;

		std::cout << "The item has been added to the inventory.\n";
	}
}

void Inventory::RemoveItem() {
	if (m_count > 0) {
		m_items[m_count - 1] = nullptr;
		m_count--;

		std::cout << "The item has been removed from the inventory.\n";
	}
	else {
		std::cout << "The inventory is empty.\n";
	}
}

void Inventory::ShowInventory() {
	for (int i = 0; i < m_count; i++) {
		m_items[i]->Inspect();
	}
}

