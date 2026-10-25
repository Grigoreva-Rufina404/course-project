public class Inventory implements AutoCloseable {
    private final Item[] items;
    private int count = 0;
    private boolean closed = false;

    public Inventory(int capacity) {
        if (capacity <= 0) {
            throw new IllegalArgumentException("Вместимость должна быть положительной");
        }
        items = new Item[capacity];
    }

    public void addItem(Item item) {
        checkOpen();

        if (item == null) {
            throw new IllegalArgumentException("Предмет не может быть null");
        }

        // Как в ЛР 2: переполнение не ломает программу, а выводит сообщение.
        if (count >= items.length) {
            System.out.println("Инвентарь заполнен.");
            return;
        }

        items[count] = item;
        count++;
        System.out.println("Предмет добавлен в инвентарь: " + item.getName());
    }

    public void removeItem() {
        checkOpen();

        if (count == 0) {
            System.out.println("Инвентарь пуст.");
            return;
        }

        count--;
        items[count] = null;
        System.out.println("Предмет убран из инвентаря.");
    }

    public void showInventory() {
        checkOpen();

        for (int i = 0; i < count; i++) {
            items[i].inspect();
        }
    }

    @Override
    public String toString() {
        if (closed) {
            return "Инвентарь (закрыт)";
        }
        StringBuilder sb = new StringBuilder("Инвентарь (" + count + "/" + items.length + ")");
        for (int i = 0; i < count; i++) {
            sb.append(i == 0 ? ": " : ", ").append(items[i]);
        }
        return sb.toString();
    }

    private void checkOpen() {
        if (closed) {
            throw new IllegalStateException("Инвентарь уже закрыт");
        }
    }

    @Override
    public void close() {
        if (!closed) {
            for (int i = 0; i < count; i++) {
                items[i] = null;
            }
            count = 0;
            closed = true;
            System.out.println("Ресурс Inventory закрыт");
        }
    }
}
