// Курсовой проект: Разработка программного игрового приложения на основе сюжетов музыкальных композиций группы «Король и Шут»
// Студент: Григорьева Р. И., группа ПИ-51.

#include "Inventory.hpp"
#include "Item.hpp"
#include "Player.hpp"

#include <iostream>
#include <memory>
#include <utility>

namespace
{

const char* State(const std::unique_ptr<Item>& pointer)
{
    return pointer ? "not empty" : "empty";
}

} // namespace

int main()
{
    std::cout << std::boolalpha;

    // Агрегация:
    // Item создаются отдельно от Player и Inventory.
    // Владелец предметов - main, поэтому они лежат в shared_ptr.
    auto sword1 = std::make_shared<Item>("Rusty sword", 5);
    auto sword2 = std::make_shared<Item>("Sharp blade", 30);
    auto potion = std::make_shared<Item>("Regeneration potion", 0);
    auto book   = std::make_shared<Item>("Tales of the Headless One", 0);

    std::cout << "\n=== Aggregation and composition ===\n";

    {
        // Композиция:
        // Player содержит Inventory внутри себя с вместимостью 3
        Player player("Ivan", 100, 3);

        // Агрегация:
        // уже существующие Item передаются Player -> Inventory
        player.AddItem(sword1);
        player.AddItem(sword2);
        player.AddItem(potion);

        std::cout << "Owners of the sword (inventory only observes): "
                  << sword1.use_count() << '\n';

        // Состояние инвентаря
        player.ShowInventory();

        // Попытка нарушить правило вместимости
        player.AddItem(book);

        // Состояние инвентаря
        player.ShowInventory();

        // Работа с состоянием Player
        player.TakeDamage(40);
        player.Heal(20);

        // Попытка нарушить правило наносимого урона/восстановленного здоровья
        player.TakeDamage(120);
        player.Heal(180);
    }
    // Player и его Inventory уничтожены
    // Предметы продолжают существовать
    book->Inspect();
    sword2->Use();

    std::cout << "\n=== shared_ptr: owner counter ===\n";

    std::cout << "Owners of the sword: " << sword1.use_count() << '\n';

    auto swordCopy = sword1;
    std::cout << "After copying the pointer: " << sword1.use_count() << '\n';

    {
        auto swordCopyInBlock = sword1;
        std::cout << "After one more copy in a block: " << sword1.use_count() << '\n';
    }

    std::cout << "The copy from the block is destroyed: " << sword1.use_count() << '\n';

    std::cout << "\n=== weak_ptr: the object is alive ===\n";

    std::weak_ptr<Item> weakSword = sword1;
    std::cout << "Weak reference available: " << !weakSword.expired() << '\n';

    if (const auto lockedSword = weakSword.lock())
    {
        lockedSword->Inspect();
        std::cout << "Owners while lock() result is alive: " << sword1.use_count() << '\n';
    }

    std::cout << "Owners after lock() result is gone: " << sword1.use_count() << '\n';

    std::cout << "\n=== unique_ptr: dynamic object ===\n";

    {
        auto dynamicItem = std::make_unique<Item>("Dynamic sword", 10);

        dynamicItem->Inspect();

        std::cout << "Leaving the block, no manual cleanup is needed\n";
    }

    std::cout << "The block is left\n";

    std::cout << "\n=== unique_ptr: transfer of ownership ===\n";

    {
        auto firstOwner = std::make_unique<Item>("Moved sword", 7);
        std::cout << "Before move, first owner is " << State(firstOwner) << '\n';

        auto secondOwner = std::move(firstOwner);
        std::cout << "After move, first owner is " << State(firstOwner) << '\n';
        std::cout << "After move, second owner is " << State(secondOwner) << '\n';

        secondOwner->Inspect();
    }

    std::cout << "The block is left\n";

    std::cout << "\n=== unique_ptr: dynamic array ===\n";

    {
        auto items = std::make_unique<Item[]>(3);

        items[0].Inspect();
        items[1].Use();
    }

    std::cout << "\n=== unique_ptr: array of dynamic objects ===\n";

    {
        std::unique_ptr<Item> itemsPointers[2];

        itemsPointers[0] = std::make_unique<Item>("Axe", 8);
        itemsPointers[1] = std::make_unique<Item>("Stone", 2);

        itemsPointers[0]->Use();
        itemsPointers[1]->Inspect();
    }

    std::cout << "\n=== weak_ptr: the object is destroyed ===\n";

    swordCopy.reset();
    std::cout << "One owner is gone, owners left: " << sword1.use_count() << '\n';

    sword1.reset();

    std::cout << "Weak reference available: " << !weakSword.expired() << '\n';

    if (const auto item = weakSword.lock())
    {
        item->Inspect();
    }
    else
    {
        std::cout << "The sword no longer exists.\n";
    }

    std::cout << "\n=== End of program ===\n";

    return 0;
}
