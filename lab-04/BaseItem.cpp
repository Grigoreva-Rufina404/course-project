#include <iostream>
#include <utility>

#include "BaseItem.hpp"

// Конструктор с параметрами
BaseItem::BaseItem(std::string name)
	: m_name{ std::move(name) } {
	std::cout << "The object created: " << m_name << '\n';
}

// Конструктор по умолчанию
BaseItem::BaseItem()
    : m_name{ "Default object" } {
    std::cout << "The object created: " << m_name << '\n';
}

// Возвращает текстовое описание предмета
std::string BaseItem::Describe() const {
	return "Item: " + m_name;
}

// Виртуальный деструктор базового класса
BaseItem::~BaseItem() {
	std::cout << "The object is destroyed: " << m_name << '\n';
}