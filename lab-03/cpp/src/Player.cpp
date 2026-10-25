#include "Player.hpp"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <utility>

Player::Player(std::string name, int health, int inventoryCapacity)
    : m_name{ std::move(name) }
    , m_health{ std::clamp(health, 0, 100) }
    , m_inventory{ inventoryCapacity }
{
    std::cout << "Player created: " << m_name << '\n';
}

Player::~Player() {
    std::cout << "Player destroyed: " << m_name << '\n';
}

void Player::TakeDamage(int damage) {
    if (damage < 0) {
        throw std::invalid_argument("Damage cannot be negative");
    }

    m_health = std::max(0, m_health - damage);

    std::cout << "Player took damage: " << damage << '\n';
    std::cout << "Player health: " << m_health << '\n';
}

void Player::Heal(int amount) {
    if (amount < 0) {
        throw std::invalid_argument("Healing amount cannot be negative");
    }

    m_health = std::min(100, m_health + amount);

    std::cout << "Player healed: " << amount << '\n';
    std::cout << "Player health: " << m_health << '\n';
}

void Player::AddItem(const std::shared_ptr<Item>& item) {
    m_inventory.AddItem(item);
}

void Player::ShowInventory() const {
    m_inventory.ShowInventory();
}
