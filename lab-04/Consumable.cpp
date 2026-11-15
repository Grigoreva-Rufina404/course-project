#include <iostream>
#include <utility>

#include "Consumable.hpp"

std::string EffectTypeToString(EffectType type) {
	switch (type)
	{
	case EffectType::HealthRestoration:
		return "Health restoration";
	case EffectType::DealDamage:
		return "Deal damage";
	case EffectType::IncreaseAttack:
		return "Increase attack";
	case EffectType::DecreaseAttack:
		return "Decrease attack";
	default:
		return "Unknown effect";
	}
}

Consumable::Consumable(std::string name, int effect, EffectType type) : BaseItem(std::move(name)), m_effect{ effect }, m_type{ type } {
	std::cout << "The consumable created: " << m_name << '\n';

	if (effect < 0) {
		std::cout << "ERROR: Effect cannot be negative. Effect is set to 0 by default." << '\n';
		m_effect = 0;
	}
}

Consumable::Consumable() : BaseItem(), m_effect{ 0 }, m_type{ EffectType::HealthRestoration	} {
	std::cout << "The consumable created: " << m_name << '\n';
}

Consumable::~Consumable() {
	std::cout << "The consumable is destroyed: " << m_name << '\n';
}

void Consumable::Use() const {
	std::cout << "You used the consumable: " << m_name << '\n';
	std::cout << "Effect of the consumable: " << EffectTypeToString(m_type) << " " << m_effect << '\n';
}

void Consumable::Inspect() const {
	std::cout << "Consumable: " << m_name << '\n';
	std::cout << "Type of effect: " << EffectTypeToString(m_type) << '\n';
	std::cout << "Effect: " <<	m_effect << '\n';
}

std::unique_ptr<BaseItem> Consumable::Clone() const {
	return std::make_unique<Consumable>(*this);
}