#include <iostream>
#include <utility>

#include "Enemy.hpp"

int Enemy::m_createdCount = 0;

// Конструктор с параметрами
Enemy::Enemy(std::string name, int health, const std::shared_ptr<EnemyStats>& stats)
	: m_name{ std::move(name) }
	, m_health{ health }
	, m_stats{ stats } {

	m_createdCount++;

	std::cout << "The enemy created: " << m_name << '\n';
}

// Конструктор по умолчанию
Enemy::Enemy()
	: m_name{ "Default enemy" }
	, m_health{ 100 }
	, m_stats{ std::make_shared<EnemyStats>() } {

	m_createdCount++;

	std::cout << "The enemy created: " << m_name << '\n';
}

// Конструктор копирования
Enemy::Enemy(const Enemy& other)
	: m_name{ other.m_name }
	, m_health{ other.m_health }
	, m_stats{ std::make_shared<EnemyStats>(*other.m_stats)} {

	m_createdCount++;

	std::cout << "The enemy copied: " << m_name << '\n';
}

// Конструктор перемещения
Enemy::Enemy(Enemy&& other) noexcept
	: m_name{ std::move(other.m_name) }
	, m_health{ other.m_health }
	, m_stats{ std::move(other.m_stats) } {

	m_createdCount++;

	std::cout << "The enemy moved: " << m_name << '\n';
}

// Оператор копирующего присваивания
Enemy& Enemy :: operator = (const Enemy& other) {
	if (this == &other) {
		return *this;
	}

	m_name = other.m_name;
	m_health = other.m_health;
	m_stats = std::make_shared<EnemyStats>(*other.m_stats);

	std::cout << "The enemy assigned: " << m_name << '\n';

	return *this;
}

// Изменяет значение урона противника
void Enemy::SetDamage(int damage){
	m_stats->damage = damage;
}

// Возвращает значение урона противника
int Enemy::GetDamage() const{
	return m_stats->damage;
}

// Передаёт указатель на текущий объект инспектору
void Enemy::SendTo(const EnemyInspector& inspector) const {
	inspector.Inspect(this);
}

// Получает информацию о переданном противнике
void EnemyInspector::Inspect(const Enemy* enemy) const {
	std::cout << "Enemy received. Damage: " << enemy->GetDamage() << '\n';
}

// Возвращает значение статического счётчика
int Enemy::GetCreatedCount() {
	return m_createdCount;
}

// Деструктор
Enemy::~Enemy(){
		std::cout << "The enemy is destroyed: " << m_name << '\n';
}