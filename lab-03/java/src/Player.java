public class Player implements AutoCloseable {
    private final String name;
    private int health;
    private final Inventory inventory;

    public Player(String name, int health, int inventoryCapacity) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Имя игрока не может быть пустым");
        }

        this.name = name;
        this.health = health;
        // Композиция: игрок сам создаёт инвентарь и не отдаёт его наружу.
        this.inventory = new Inventory(inventoryCapacity);

        System.out.println("Игрок создан: " + name);

        // Как в ЛР 2: сообщаем об ошибке и приводим значение к допустимому.
        if (health < 0) {
            System.out.println("ERROR: здоровье не может быть меньше нуля. Здоровье установлено в 0.");
            this.health = 0;
        }
        if (health > 100) {
            System.out.println("ERROR: здоровье не может превышать 100. Здоровье установлено в 100.");
            this.health = 100;
        }
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public void takeDamage(int damage) {
        health = health - damage;

        System.out.println(name + " получил урон: " + damage);

        if (health < 0) {
            health = 0;
        }

        System.out.println("Здоровье игрока: " + health);
    }

    public void heal(int amount) {
        health = health + amount;

        System.out.println(name + " получил лечение: " + amount);

        if (health > 100) {
            health = 100;
        }

        System.out.println("Здоровье игрока: " + health);
    }

    public void addItem(Item item) {
        inventory.addItem(item);
    }

    public void showInventory() {
        inventory.showInventory();
    }

    @Override
    public String toString() {
        return name + ", здоровье " + health + ", " + inventory;
    }

    @Override
    public void close() {
        inventory.close();
        System.out.println("Ресурсы игрока " + name + " закрыты");
    }
}
