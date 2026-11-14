#pragma once
#include <string>
#include "BaseItem.hpp"


class QuestItem : public BaseItem {		//	Êגוסעמגûי ןנוהלוע

public:
	QuestItem(std::string name);
	QuestItem();
	~QuestItem() override;

	void Use() const override;
	void Inspect() const override;
};
