#pragma once

#include <memory>

#include "Item.hpp"

class Inventory {
private:
    std::unique_ptr<std::weak_ptr<Item>[]> m_items;
    int m_count{ 0 };
    int m_capacity;

public:
    explicit Inventory(int capacity);
    ~Inventory();

    Inventory(const Inventory&) = delete;
    Inventory& operator=(const Inventory&) = delete;

    void AddItem(const std::shared_ptr<Item>& item);
    void RemoveItem();
    void ShowInventory() const;
};