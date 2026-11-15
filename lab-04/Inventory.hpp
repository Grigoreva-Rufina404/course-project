#pragma once

#include <memory>

#include "BaseItem.hpp"

class Inventory {
private:
    // Массив принадлежит Inventory (один владелец), а предметы в нём -
    // только наблюдаемые объекты: ими владеют те, кто их создал.
    std::unique_ptr<std::weak_ptr<BaseItem>[]> m_items;
    int m_count{ 0 };
    int m_capacity;

public:
    explicit Inventory(int capacity);
    ~Inventory();

    Inventory(const Inventory&)            = delete;
    Inventory& operator=(const Inventory&) = delete;

    void AddItem(const std::shared_ptr<BaseItem>& item);
    void RemoveItem();
    void ShowInventory() const;
};
