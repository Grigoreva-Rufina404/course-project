#pragma once

#include <string>

class Item {
private:
    std::string m_name;
    int m_damage;

public:
    Item(std::string name, int damage);
    Item();

    ~Item();

    void Inspect() const;
    void Use() const;

    const std::string& GetName() const;
    int GetDamage() const;
};
