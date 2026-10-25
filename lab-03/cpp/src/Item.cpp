#include "Item.hpp"

#include <iostream>
#include <utility>

Item::Item(std::string name, int damage)
    : m_name{ std::move(name) }
    , m_damage{ damage < 0 ? 0 : damage }
{
    if (damage < 0) {
        std::cout << "Damage cannot be negative. Set to 0.\n";
    }

    std::cout << "Item created: " << m_name << '\n';
}

Item::Item()
    : m_name{ "default item" }
    , m_damage{ 0 }
{
    std::cout << "Item created: " << m_name << '\n';
}

Item::~Item() {
    std::cout << "Item destroyed: " << m_name << '\n';
}

void Item::Inspect() const {
    std::cout << "Item: " << m_name << '\n';
    std::cout << "Damage: " << m_damage << '\n';
}

void Item::Use() const {
    std::cout << "Used item: " << m_name << '\n';
    std::cout << "Damage caused: " << m_damage << '\n';
}

const std::string& Item::GetName() const {
    return m_name;
}

int Item::GetDamage() const {
    return m_damage;
}
