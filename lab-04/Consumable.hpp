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

class Consumable : public BaseItem {
private:
	int m_effect;
	EffectType m_type;

public:
	Consumable(std::string name, int effect, EffectType type);
	Consumable();

	~Consumable() override;

	void Use() const override;
	void Inspect() const override;

	std::unique_ptr<BaseItem> Clone() const override;
};

