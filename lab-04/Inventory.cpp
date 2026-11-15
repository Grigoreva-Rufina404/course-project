#include <cstddef>
#include <iostream>
#include <stdexcept>

#include "Inventory.hpp"

// Конструктор инвентаря
Inventory::Inventory(int capacity)
    : m_capacity{ capacity } {
    if (capacity <= 0) {
        throw std::invalid_argument("Inventory capacity must be positive");
    }

    m_items = std::make_unique<std::weak_ptr<BaseItem>[]>(static_cast<std::size_t>(capacity));

    std::cout << "Inventory created\n";
}

// Деструктор
Inventory::~Inventory() {
    std::cout << "The inventory is destroyed\n";
}

// Добавляет предмет в инвентарь
void Inventory::AddItem(const std::shared_ptr<BaseItem>& item) {
    if (!item) {
        std::cout << "Cannot add an empty item reference.\n";
        return;
    }

    if (m_count >= m_capacity) {
        std::cout << "The inventory is full.\n";
    }
    else {
        m_items[m_count] = item;
        m_count++;

        std::cout << "The item has been added to the inventory.\n";
    }
}

// Удаляет последний предмет из инвентаря
void Inventory::RemoveItem() {
    if (m_count > 0) {
        m_items[m_count - 1].reset();
        m_count--;

        std::cout << "The item has been removed from the inventory.\n";
    }
    else {
        std::cout << "The inventory is empty.\n";
    }
}

// Выводит описание каждого предмета
void Inventory::ShowInventory() const {
    for (int i = 0; i < m_count; i++) {
        if (const auto item = m_items[i].lock()) {
            std::cout << item->Describe() << '\n';
        }
        else {
            std::cout << "Item is no longer available.\n";
        }
    }
}
