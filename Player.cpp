#include "Player.hpp"
#include <iostream>

Player::Player(std::string name, int health, int inventory)
	: m_name{ name }
	, m_health{ health }
	, m_inventory {inventory}
{
	std::cout << "The player has been created: " << m_name << '\n';

	if (health < 0) {
		std::cout << "ERROR: The player’s health cannot be less than zero. Health is set to 0.\n";
		m_health = 0;
	}
	if (health > 100) {
		std::cout << "ERROR: The player’s health cannot  exceed 100. Health is set to 100.\n";
		m_health = 100;
	}
}

Player::~Player() {
	std::cout << "The player has been removed: " << m_name << '\n';
}

void Player::TakeDamage(int damage) {
	m_health = m_health - damage;

	std::cout << "The player has taken damage: " << damage << '\n';

	if (m_health < 0) {
		m_health = 0;
	}

	std::cout << "Player health: " << m_health << '\n';
}

void Player::Heal(int heal) {
	m_health = m_health + heal;

	std::cout << "The player has taken heal: " << heal << '\n';

	if (m_health > 100) {
		m_health = 100;
	}

	std::cout << "Player health: " << m_health << '\n';
}

void Player::AddItem(Item& item) {
	m_inventory.AddItem(item);
}

void Player::ShowInventory() {
	m_inventory.ShowInventory();
}