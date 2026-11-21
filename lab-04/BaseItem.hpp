#pragma once

#include <string>
#include <memory>

// Базовый абстрактный класс для всех игровых предметов
class BaseItem {
protected:
	std::string m_name;

	// Конструктор копирования доступен наследникам
	BaseItem(const BaseItem& other) = default;
	BaseItem(BaseItem&& other) noexcept = default;
	BaseItem& operator=(const BaseItem& other) = default;
	BaseItem& operator=(BaseItem&& other) noexcept = default;

public:
	explicit BaseItem(std::string name);
	BaseItem();

	virtual ~BaseItem();

	// Чисто виртуальные методы
	virtual void Use() const = 0;
	virtual std::string Describe() const;

	virtual std::unique_ptr<BaseItem> Clone() const = 0;
};