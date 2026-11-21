#include <iostream>
#include <utility>

#include "Player.hpp"

// Конструктор персонажа
Player::Player(std::string name, int health, int inventoryCapacity)
    : m_name{ std::move(name) }
    , m_health{ health }
    , m_inventory{ inventoryCapacity } {
    std::cout << "The player has been created: " << m_name << '\n';

    if (health < 0) {
        std::cout << "ERROR: The player's health cannot be less than zero. Health is set to 0.\n";
        m_health = 0;
    }
    if (health > 100) {
        std::cout << "ERROR: The player's health cannot exceed 100. Health is set to 100.\n";
        m_health = 100;
    }
}

// Деструктор
Player::~Player() {
    std::cout << "The player has been removed: " << m_name << '\n';
}

// Уменьшает здоровье персонажа
void Player::TakeDamage(int damage) {
    m_health = m_health - damage;

    std::cout << "The player has taken damage: " << damage << '\n';

    if (m_health < 0) {
        m_health = 0;
    }

    std::cout << "Player health: " << m_health << '\n';
}

// Восстанавливает здоровье персонажа
void Player::Heal(int heal){
    m_health = m_health + heal;

    std::cout << "The player has taken heal: " << heal << '\n';

    if (m_health > 100){
        m_health = 100;
    }

    std::cout << "Player health: " << m_health << '\n';
}

// Передаёт предмет инвентарю для добавления
void Player::AddItem(const std::shared_ptr<BaseItem>& item){
    m_inventory.AddItem(item);
}

// Передаёт инвентарю команду вывести его содержимое
void Player::ShowInventory() const{
    m_inventory.ShowInventory();
}
