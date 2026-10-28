from typing import Generic, TypeVar, cast


T = TypeVar("T")


class CircularQueue(Generic[T]):
    def __init__(self, capacity: int) -> None:
        if capacity <= 0:
            raise ValueError("capacity must be greater than zero")

        self.capacity = capacity
        self._items: list[T | None] = [None] * capacity
        self._front = 0
        self._size = 0

    def is_empty(self) -> bool:
        return self._size == 0

    def is_full(self) -> bool:
        return self._size == self.capacity

    def enqueue(self, value: T) -> None:
        if self.is_full():
            print("Queue is full")
            return
        rear = (self._front + self._size) % self.capacity
        self._items[rear] = value
        self._size += 1

    def dequeue(self) -> T | None:
        if self.is_empty():
            print("Queue is empty")
            return None
        value = cast(T, self._items[self._front])
        self._items[self._front] = None
        self._front = (self._front + 1) % self.capacity
        self._size -= 1
        return value

    def peek(self) -> T | None:
        if self.is_empty():
            print("Queue is empty")
            return None
        return cast(T, self._items[self._front])

    def display(self) -> None:
        if self.is_empty():
            print("Queue is empty")
            return
        for i in range(self._size):
            index = (self._front + i) % self.capacity
            print(self._items[index], end=" ")
        print()


if __name__ == "__main__":
    queue: CircularQueue[int] = CircularQueue(5)
    queue.enqueue(10)
    queue.enqueue(20)
    queue.enqueue(30)
    queue.display()
    print(queue.dequeue())
    queue.display()
    queue.enqueue(40)
    queue.enqueue(50)
    queue.enqueue(60)
    print(queue.peek())