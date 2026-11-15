#pragma once

#include <string>
#include <memory>

class BaseItem {
protected:
	std::string m_name;

	BaseItem(const BaseItem& other) = default;

public:
	BaseItem(std::string name);
	BaseItem();

	virtual ~BaseItem();

	virtual void Use() const = 0;
	virtual void Inspect() const = 0;

	virtual std::unique_ptr<BaseItem> Clone() const = 0;
};