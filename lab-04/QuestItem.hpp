#pragma once

#include <string>

#include "BaseItem.hpp"

// Класс сюжетного предмета
class QuestItem final: public BaseItem {
public:
	explicit QuestItem(std::string name);
	QuestItem();

	~QuestItem() override;

	// Реализация использования сюжетного предмета
	void Use() const override;

	// Создаёт копию текущего объекта QuestItem
	std::unique_ptr<BaseItem> Clone() const override;
};
