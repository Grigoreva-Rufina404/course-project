public class Item {
    private final String name;
    private final int damage;

    public Item(String name, int damage) {
        if (name == null || name.isBlank()) {
            throw new IllegalArgumentException("Название предмета не может быть пустым");
        }

        this.name = name;

        // Как в ЛР 2: сообщаем об ошибке и подставляем значение по умолчанию.
        if (damage < 0) {
            System.out.println("ERROR: урон не может быть отрицательным. Урон установлен в 0.");
            this.damage = 0;
        } else {
            this.damage = damage;
        }
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
        System.out.println("Использован предмет: " + name + ", нанесён урон: " + damage);
    }

    @Override
    public String toString() {
        return name + " (урон " + damage + ")";
    }
}
