#include <iostream>
#include <utility>

#include "Consumable.hpp"

// Преобразует тип эффекта в строку для вывода пользователю
std::string EffectTypeToString(EffectType type) {
	switch (type) {
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

// Конструктор с параметрами
Consumable::Consumable(std::string name, int effect, EffectType type) : BaseItem(std::move(name)), m_effect{ effect }, m_type{ type } {
	std::cout << "The consumable created: " << m_name << '\n';

	if (effect < 0) {
		std::cout << "ERROR: Effect cannot be negative. Effect is set to 0 by default." << '\n';
		m_effect = 0;
	}
}

// Конструктор по умолчанию
Consumable::Consumable() : BaseItem(), m_effect{ 0 }, m_type{ EffectType::HealthRestoration	} {
	std::cout << "The consumable created: " << m_name << '\n';
}

// Деструктор
Consumable::~Consumable() {
	std::cout << "The consumable is destroyed: " << m_name << '\n';
}

// Выводит информацию об использовании предмета и его эффекте
void Consumable::Use() const {
	std::cout << "You used the consumable: " << m_name << '\n';
	std::cout << "Effect of the consumable: " << EffectTypeToString(m_type) << " " << m_effect << '\n';
}

// Формирует описание расходуемого предмета
std::string Consumable::Describe() const {
	return "Consumable: " + m_name +
		", effect: " + EffectTypeToString(m_type) +
		", value: " + std::to_string(m_effect);
}

// Создаёт копию текущего объекта Consumable
std::unique_ptr<BaseItem> Consumable::Clone() const {
	return std::make_unique<Consumable>(*this);
}