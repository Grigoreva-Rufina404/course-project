#pragma once

#include <string>

#include "Inventory.hpp"

class Player {
private:
    std::string m_name;
    int m_health;
    Inventory m_inventory;

public:
    Player(std::string name, int health, int inventoryCapacity);
    ~Player();

    void TakeDamage(int damage);
    void Heal(int amount);

    void AddItem(const std::shared_ptr<Item>& item);
    void ShowInventory() const;
};