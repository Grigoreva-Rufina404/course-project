#include <iostream>
#include <utility>

#include "QuestItem.hpp"

// Конструктор с параметрами
QuestItem::QuestItem(std::string name) : BaseItem(std::move(name)) {
	std::cout << "The quest item created: " << m_name << '\n';
}

// Конструктор по умолчанию
QuestItem::QuestItem() : BaseItem() {
	std::cout << "The quest item created: " << m_name << '\n';
}

// Деструктор
QuestItem::~QuestItem() {
	std::cout << "The quest item is destroyed: " << m_name << '\n';
}

// Выводит сообщение об использовании сюжетного предмета
void QuestItem::Use() const {
	std::cout << "You used the quest item: " << m_name << '\n';
}

// Создаёт копию текущего объекта QuestItem
std::unique_ptr<BaseItem> QuestItem::Clone() const {
	return std::make_unique<QuestItem>(*this);
}