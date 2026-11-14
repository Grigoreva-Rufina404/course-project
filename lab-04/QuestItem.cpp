#include <iostream>
#include <utility>
#include "QuestItem.hpp"

QuestItem::QuestItem(std::string name) : BaseItem(std::move(name)) {
	std::cout << "The quest item created: " << m_name << '\n';
}

QuestItem::QuestItem() : BaseItem() {
	std::cout << "The quest item created: " << m_name << '\n';
}

QuestItem::~QuestItem() {
	std::cout << "The quest item is destroyed: " << m_name << '\n';
}

void QuestItem::Use() const {
	std::cout << "You used the quest item: " << m_name << '\n';
}

void QuestItem::Inspect() const {
	std::cout << "Quest item: " << m_name << '\n';
}