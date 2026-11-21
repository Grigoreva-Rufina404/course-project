#pragma once

#include <string>
#include <memory>

// Предварительные объявления классов
class Enemy;
class EnemyInspector;

// Структура с характеристиками противника
struct EnemyStats {
	int damage{ 0 };
	int defense{ 0 };
	const std::string description{ "Default enemy" };
};

// Класс противника
class Enemy {
private:
	std::string m_name;
	int m_health;
	std::shared_ptr<EnemyStats> m_stats;

	static int m_createdCount;

public:
	Enemy(std::string name, int health, const std::shared_ptr<EnemyStats> &stats);
	Enemy();

	// Конструктор копирования и оператор копирующего присваивания
	Enemy(const Enemy& other);
	Enemy& operator = (const Enemy& other);

	// Конструктор перемещения и оператор перемещающего присваивания
	Enemy(Enemy&& other) noexcept;
	Enemy& operator=(Enemy&& other) noexcept = default;

	// Изменяет и возвращает значение урона противника
	void SetDamage(int damage);
	int GetDamage() const;

	void SendTo(const EnemyInspector& inspector) const;

	static int GetCreatedCount();

	~Enemy();
};

// Класс для получения информации о противнике
class EnemyInspector {
public:
	void Inspect(const Enemy* enemy) const;
};