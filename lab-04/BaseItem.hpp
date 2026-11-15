#pragma once
#include <string>

class BaseItem {
protected:
	std::string m_name;

public:
	BaseItem(std::string name);
	BaseItem();
	virtual ~BaseItem();

	virtual void Use() const = 0;
	virtual void Inspect() const = 0;
};