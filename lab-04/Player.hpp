#pragma once

#include <memory>
#include <string>

#include "Inventory.hpp"
#include "BaseItem.hpp"

// Класс игрового персонажа
class Player {
private:
    std::string m_name;
    int m_health;
    Inventory m_inventory;

public:
    Player(std::string name, int health, int inventoryCapacity);
    ~Player();

    void TakeDamage(int damage);    // Уменьшает здоровье персонажа
    void Heal(int heal);            // Восстанавливает здоровье персонажа
    void AddItem(const std::shared_ptr<BaseItem>& item);     // Добавляет предмет в инвентарь персонажа
    void ShowInventory() const;     // Выводит содержимое инвентаря
};
