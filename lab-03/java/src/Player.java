public class Player implements AutoCloseable {
    private final String name;
    private int health;
    private final Inventory inventory;

    public Player(String name, int health, int inventoryCapacity) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Имя игрока не может быть пустым");
        }
        if (health < 0 || health > 100) {
            throw new IllegalArgumentException("Здоровье должно быть от 0 до 100");
        }

        this.name = name;
        this.health = health;
        // Композиция: игрок сам создаёт инвентарь и не отдаёт его наружу.
        this.inventory = new Inventory(inventoryCapacity);
    }

    public String getName() {
        return name;
    }

    public int getHealth() {
        return health;
    }

    public void takeDamage(int damage) {
        if (damage < 0) {
            throw new IllegalArgumentException("Урон не может быть отрицательным");
        }

        health = Math.max(0, health - damage);
        System.out.println(name + " получил урон. Здоровье: " + health);
    }

    public void heal(int amount) {
        if (amount < 0) {
            throw new IllegalArgumentException("Лечение не может быть отрицательным");
        }

        health = Math.min(100, health + amount);
        System.out.println(name + " восстановил здоровье. Здоровье: " + health);
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
