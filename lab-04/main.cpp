#include <iostream>
#include <memory>
#include <utility>

#include "BaseItem.hpp"
#include "Weapon.hpp"
#include "Consumable.hpp"
#include "QuestItem.hpp"
#include "Enemy.hpp"

// Структура для демонстрации поверхностного копирования
struct ShallowCopyDemo {
    std::shared_ptr<EnemyStats> stats;
};

int main() {
    // Массив предметов разных дочерних классов
    std::unique_ptr<BaseItem> items[] = {
        std::make_unique<Weapon>("Sword", 20),
        std::make_unique<Consumable>( "Potion", 50, EffectType::HealthRestoration),
        std::make_unique<QuestItem>("Ancient key")
    };

    // Демонстрация полиморфизма
    std::cout << "\n=== Item descriptions ===\n";

    for (const auto& item : items) {
        std::cout << item->Describe() << '\n';
    }

    // Демонстрация виртуального метода Clone()
    std::cout << "\n=== Cloning ===\n";

    for (const auto& item : items) {
        std::unique_ptr<BaseItem> copy = item->Clone();

        std::cout << "Original: " << item->Describe() << '\n';
        std::cout << "Copy: " << copy->Describe() << '\n';
    }

    // Демонстрация основных операций со строками.
    std::cout << "\n=== String operations ===\n";

    std::string itemName = "Ancient key";

    // Конкатенация
    std::string description = "Quest item: " + itemName;
    std::cout << "Concatenation: " << description << '\n';

    // Поиск
    std::size_t position = itemName.find("key");
    std::cout << "Find: " << position << '\n';

    // Выделение подстроки
    std::string part = itemName.substr(0, 7);
    std::cout << "Substring: " << part << '\n';

    // Сравнение
    std::string anotherName = "Ancient key";

    if (itemName == anotherName) {
        std::cout << "Names are equal\n";
    }
    else {
        std::cout << "Names are different\n";
    }

    // Демонстрация поверхностного копирования
    std::cout << "\n=== Shallow copy ===\n";

    auto stats = std::make_shared<EnemyStats>();
    stats->damage = 10;

    ShallowCopyDemo original{ stats };
    ShallowCopyDemo copy = original;

    copy.stats->damage = 50;

    std::cout << "Original damage: " << original.stats->damage << '\n';

    std::cout << "Copy damage: " << copy.stats->damage << '\n';

    // Демонстрация глубокого копирования
    std::cout << "\n=== Deep copy ===\n";

    auto enemyStats = std::make_shared<EnemyStats>();
    enemyStats->damage = 10;

    Enemy enemyOriginal("Deceased", 100, enemyStats);
    Enemy enemyCopy = enemyOriginal;

    std::cout << "Created enemies: " << Enemy::GetCreatedCount() << '\n';

    enemyCopy.SetDamage(50);

    std::cout << "Original damage: " << enemyOriginal.GetDamage() << '\n';

    std::cout << "Copy damage: " << enemyCopy.GetDamage() << '\n';

    // Демонстрация передачи текущего объекта инспектору
    EnemyInspector inspector;
    enemyOriginal.SendTo(inspector);

    // Демонстрация конструктора по умолчанию
    std::cout << "\n=== Default constructor ===\n";
    Enemy defaultEnemy;

    // Демонстрация конструктора перемещения
    std::cout << "\n=== Move constructor ===\n";
    Enemy movedEnemy = std::move(enemyCopy);

    // Демонстрация оператора копирующего присваивания.
    std::cout << "\n=== Copy assignment ===\n";

    Enemy assignedEnemy;
    assignedEnemy = enemyOriginal;

    std::cout << "Created enemies: " << Enemy::GetCreatedCount() << '\n';

    return 0;
}
