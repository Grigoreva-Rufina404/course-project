#pragma once

#include <string>

#include "BaseItem.hpp"


class QuestItem : public BaseItem {
public:
	QuestItem(std::string name);
	QuestItem();

	~QuestItem() override;

	void Use() const override;
	void Inspect() const override;

	std::unique_ptr<BaseItem> Clone() const override;
};
