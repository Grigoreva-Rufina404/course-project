#pragma once

#include <string>
#include <memory>

struct EnemyStats {
	int damage{ 0 };
	int defense{ 0 };
	const std::string description{ "Default enemy" };
};

class Enemy {
private:
	std::string m_name;
	int m_health;
	std::shared_ptr<EnemyStats> m_stats;

public:
	Enemy(std::string name, int health, const std::shared_ptr<EnemyStats> &stats);
	Enemy();
	// Копирование
	Enemy(const Enemy& other);
	Enemy& operator = (const Enemy& other);
	// Перемещение
	Enemy(Enemy&& other) noexcept = default;
	Enemy& operator=(Enemy&& other) noexcept = default;

	void SetDamage(int damage);
	int GetDamage() const;

	~Enemy();
};
