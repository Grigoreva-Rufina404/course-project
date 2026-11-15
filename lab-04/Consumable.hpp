#pragma once

#include <string>

#include "BaseItem.hpp"

enum class EffectType {
	HealthRestoration,	// Восстановление здоровья
	DealDamage,			// Нанесение урона
	IncreaseAttack,		// Повышение атаки
	DecreaseAttack,		// Понижение атаки
};

std::string EffectTypeToString(EffectType type);

// Класс расходуемого предмета
class Consumable : public BaseItem {
private:
	int m_effect;
	EffectType m_type;

public:
	Consumable(std::string name, int effect, EffectType type);
	Consumable();

	~Consumable() override;

	// Реализация использования и описания расходуемого предмета
	void Use() const override;
	std::string Describe() const override;

	// Создаёт копию текущего объекта Consumable
	std::unique_ptr<BaseItem> Clone() const override;
};

