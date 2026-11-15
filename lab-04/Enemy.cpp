#include <iostream>
#include <utility>
#include "Enemy.hpp"

Enemy::Enemy(std::string name, int health, const std::shared_ptr<EnemyStats>& stats)
	: m_name{ std::move(name) }
	, m_health{ health }
	, m_stats{ stats } {
	std::cout << "The enemy created: " << m_name << '\n';
}

Enemy::Enemy()
	: m_name{ "Default enemy"}
	, m_health{ 100 }
	, m_stats{std::make_shared<EnemyStats>()} {
		std::cout << "The enemy created: " << m_name << '\n';
}

// Конструктор копирования
Enemy::Enemy(const Enemy& other)
	: m_name{ other.m_name }
	, m_health{ other.m_health }
	, m_stats{ std::make_shared<EnemyStats>(*other.m_stats)} {
	std::cout << "The enemy copied: " << m_name << '\n';
}

Enemy::~Enemy(){
		std::cout << "The enemy is destroyed: " << m_name << '\n';
}