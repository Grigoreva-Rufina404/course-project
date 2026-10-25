#include "Item.hpp"
#include "Inventory.hpp"
#include "Player.hpp"

#include <iostream>
#include <memory>

int main() {
    std::cout << "=== Shared ownership and aggregation ===\n";

    auto sword = std::make_shared<Item>("Rusty sword", 5);
    auto secondSwordReference = sword;

    std::cout << "Shared owners: " << sword.use_count() << '\n';

    std::weak_ptr<Item> weakSword = sword;
    std::cout << "Weak reference available: "
        << !weakSword.expired() << '\n';

    auto potion = std::make_shared<Item>("Regeneration potion", 0);

    {
        Player player("Wanderer", 80, 3);

        player.AddItem(sword);
        player.AddItem(potion);

        player.ShowInventory();

        player.TakeDamage(25);
        player.Heal(10);

        std::cout << "Sword owners: " << sword.use_count() << '\n';
    }

    std::cout << "\n=== Unique ownership ===\n";

    auto dynamicItem = std::make_unique<Item>("Dynamic sword", 10);
    dynamicItem->Inspect();

    std::cout << "\n=== Dynamic array ===\n";

    auto items = std::make_unique<Item[]>(3);
    items[0].Inspect();
    items[1].Use();

    std::cout << "\n=== Releasing strong references ===\n";

    secondSwordReference.reset();
    sword.reset();

    std::cout << "Weak reference available: "
        << !weakSword.expired() << '\n';

    if (auto item = weakSword.lock()) {
        item->Inspect();
    }
    else {
        std::cout << "The sword no longer exists.\n";
    }

    std::cout << "\n=== End of program ===\n";

    return 0;
}
