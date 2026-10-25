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
        if (count >= items.length) {
            throw new IllegalStateException("Инвентарь заполнен");
        }

        items[count] = item;
        count++;
    }

    public Item removeItem() {
        checkOpen();

        if (count == 0) {
            throw new IllegalStateException("Инвентарь пуст");
        }

        count--;
        Item removed = items[count];
        items[count] = null;
        return removed;
    }

    public void showInventory() {
        checkOpen();

        System.out.println("Инвентарь (" + count + "/" + items.length + "):");

        if (count == 0) {
            System.out.println("  Пусто");
            return;
        }

        for (int i = 0; i < count; i++) {
            System.out.println("  " + (i + 1) + ". " + items[i].getName());
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
