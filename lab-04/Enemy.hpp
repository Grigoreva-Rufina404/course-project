#pragma once

#include <string>
#include <memory>

// ѕредварительные объ€влени€ классов
class Enemy;
class EnemyInspector;

// —труктура с характеристиками противника
struct EnemyStats {
	int damage{ 0 };
	int defense{ 0 };
	const std::string description{ "Default enemy" };
};

//  ласс противника
class Enemy {
private:
	std::string m_name;
	int m_health;
	std::shared_ptr<EnemyStats> m_stats;

	static int m_createdCount;

public:
	Enemy(std::string name, int health, const std::shared_ptr<EnemyStats> &stats);
	Enemy();

	//  онструктор копировани€ и оператор копирующего присваивани€
	Enemy(const Enemy& other);
	Enemy& operator = (const Enemy& other);

	//  онструктор перемещени€ и оператор перемещающего присваивани€
	Enemy(Enemy&& other) noexcept;
	Enemy& operator=(Enemy&& other) noexcept = default;

	// »змен€ет и возвращает значение урона противника
	void SetDamage(int damage);
	int GetDamage() const;

	void SendTo(const EnemyInspector& inspector) const;

	static int GetCreatedCount();

	~Enemy();
};

//  ласс дл€ получени€ информации о противнике
class EnemyInspector {
public:
	void Inspect(const Enemy* enemy) const;
};