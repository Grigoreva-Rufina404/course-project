#pragma once

#include <memory>
#include <string>

#include "Inventory.hpp"
#include "BaseItem.hpp"

class Player {
private:
    std::string m_name;
    int m_health;
    Inventory m_inventory;

public:
    Player(std::string name, int health, int inventoryCapacity);
    ~Player();

    void TakeDamage(int damage);
    void Heal(int heal);
    void AddItem(const std::shared_ptr<BaseItem>& item);
    void ShowInventory() const;
};
