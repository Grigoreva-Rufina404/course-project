#include <iostream>
#include <memory>

#include "BaseItem.hpp"
#include "Weapon.hpp"
#include "Consumable.hpp"
#include "QuestItem.hpp"
#include "Enemy.hpp"

struct ShallowCopyDemo {
    std::shared_ptr<EnemyStats> stats;
};

int main()
{
    // Клонирование оружия
    std::unique_ptr<BaseItem> weapon =
        std::make_unique<Weapon>("Sword", 20);

    std::unique_ptr<BaseItem> weaponCopy = weapon->Clone();

    weapon->Inspect();
    weaponCopy->Inspect();

    std::cout << "\n";

    // Клонирование расходника
    std::unique_ptr<BaseItem> consumable =
        std::make_unique<Consumable>("Potion", 50, EffectType::HealthRestoration);

    std::unique_ptr<BaseItem> consumableCopy = consumable->Clone();

    consumable->Inspect();
    consumableCopy->Inspect();

    std::cout << "\n";

    // Клонирование квестового предмета
    std::unique_ptr<BaseItem> questItem =
        std::make_unique<QuestItem>("Ancient key");

    std::unique_ptr<BaseItem> questItemCopy = questItem->Clone();

    questItem->Inspect();
    questItemCopy->Inspect();

    // Поверхностное копирование

    auto stats = std::make_shared<EnemyStats>();
    stats->damage = 10;

    ShallowCopyDemo original{ stats };
    ShallowCopyDemo copy = original;

    copy.stats->damage = 50;

    std::cout << "Original damage: "
        << original.stats->damage << '\n';

    std::cout << "Copy damage: "
        << copy.stats->damage << '\n';

    auto enemyStats = std::make_shared<EnemyStats>();
    enemyStats->damage = 10;

    Enemy enemyOriginal("Deceased", 100, enemyStats);
    Enemy enemyCopy = enemyOriginal;

    enemyCopy.SetDamage(50);

    std::cout << "Original damage: "
        << enemyOriginal.GetDamage() << '\n';

    std::cout << "Copy damage: "
        << enemyCopy.GetDamage() << '\n';
}