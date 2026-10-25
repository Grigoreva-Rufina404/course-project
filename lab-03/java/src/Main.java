import java.lang.ref.WeakReference;

public class Main {
    public static void main(String[] args) {
        Item sword = new Item("Старый меч", 15);

        // Две переменные ссылаются на один объект.
        Item sameSword = sword;
        System.out.println("Один ли это объект? " + (sword == sameSword));
        sameSword.inspect();

        // Слабая ссылка не препятствует сборке объекта.
        WeakReference<Item> weakSword = new WeakReference<>(sword);
        System.out.println(
                "Слабая ссылка доступна: " + (weakSword.get() != null)
        );

        // Инвентарь закрывается автоматически после завершения блока.
        try (Player player = new Player(
                "Странник", 80, new Inventory(3))) {

            player.addItem(sword);
            player.addItem(new Item("Зелье", 0));

            player.showInventory();
            sword.use();

            player.takeDamage(25);
            player.heal(10);
        }

        System.out.println("Блок try-with-resources завершён.");

        // Убираем обычные ссылки на меч.
        sword = null;
        sameSword = null;

        System.out.println(
                "Слабая ссылка до запроса GC: "
                        + (weakSword.get() != null)
        );

        // Это запрос сборщику мусора, а не гарантия удаления объекта.
        System.gc();

        System.out.println(
                "Слабая ссылка после запроса GC: "
                        + (weakSword.get() != null)
        );
    }
}
