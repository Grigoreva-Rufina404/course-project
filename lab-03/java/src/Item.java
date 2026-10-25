public class Item {
    private final String name;
    private final int damage;

    public Item(String name, int damage) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Название предмета не может быть пустым");
        }
        if (damage < 0) {
            throw new IllegalArgumentException("Урон не может быть отрицательным");
        }

        this.name = name;
        this.damage = damage;
    }

    public String getName() {
        return name;
    }

    public int getDamage() {
        return damage;
    }

    public void inspect() {
        System.out.println("Предмет: " + name + ", урон: " + damage);
    }

    public void use() {
        System.out.println("Использован предмет: " + name);
    }
}
