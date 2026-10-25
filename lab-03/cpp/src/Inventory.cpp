#include "Inventory.hpp"

#include <cstddef>
#include <iostream>
#include <stdexcept>

Inventory::Inventory(int capacity)
    : m_capacity{ capacity }
{
    if (capacity <= 0)
    {
        throw std::invalid_argument("Inventory capacity must be positive");
    }

    m_items = std::make_unique<std::weak_ptr<Item>[]>(static_cast<std::size_t>(capacity));

    std::cout << "Inventory created\n";
}

Inventory::~Inventory()
{
    std::cout << "The inventory is destroyed\n";
}

void Inventory::AddItem(const std::shared_ptr<Item>& item)
{
    if (!item)
    {
        std::cout << "Cannot add an empty item reference.\n";
        return;
    }

    if (m_count >= m_capacity)
    {
        std::cout << "The inventory is full.\n";
    }
    else
    {
        m_items[m_count] = item;
        m_count++;

        std::cout << "The item has been added to the inventory.\n";
    }
}

void Inventory::RemoveItem()
{
    if (m_count > 0)
    {
        m_items[m_count - 1].reset();
        m_count--;

        std::cout << "The item has been removed from the inventory.\n";
    }
    else
    {
        std::cout << "The inventory is empty.\n";
    }
}

void Inventory::ShowInventory() const
{
    for (int i = 0; i < m_count; i++)
    {
        // Перед использованием проверяем, жив ли предмет.
        if (const auto item = m_items[i].lock())
        {
            item->Inspect();
        }
        else
        {
            std::cout << "Item is no longer available.\n";
        }
    }
}
