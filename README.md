# Circular Queue

This project contains a generic, fixed-capacity circular queue implementation in [`craxy.py`](./craxy.py). The queue stores items in a circular buffer, reusing freed slots after items are removed.

## Requirements

- Python 3.10 or later

## Run the example

From the project directory, run:

```powershell
py craxy.py
```

The example enqueues values, displays the queue, removes an item, and peeks at the next item.

## Check whether a number is odd or even

Run [`check_odd_even.py`](./check_odd_even.py) and enter an integer when prompted:

```powershell
py check_odd_even.py
```

The program reports whether the integer is odd or even and displays a message if the input is not a valid integer.

## Use the queue

```python
from craxy import CircularQueue

queue: CircularQueue[str] = CircularQueue(3)
queue.enqueue("first")
queue.enqueue("second")

print(queue.peek())       # first
print(queue.dequeue())    # first
print(queue.is_empty())   # False
print(queue.is_full())    # False
queue.display()           # second
```

`CircularQueue` accepts a positive capacity and can store values of a chosen type.

## Methods

| Method | Description |
| --- | --- |
| `enqueue(value)` | Adds a value to the rear. If the queue is full, prints `Queue is full` and leaves the queue unchanged. |
| `dequeue()` | Removes and returns the front value. If empty, prints `Queue is empty` and returns `None`. |
| `peek()` | Returns the front value without removing it. If empty, prints `Queue is empty` and returns `None`. |
| `is_empty()` | Returns whether the queue contains no values. |
| `is_full()` | Returns whether the queue has reached its capacity. |
| `display()` | Prints the values from front to rear, or prints `Queue is empty` when empty. |

Creating a queue with a capacity of zero or less raises `ValueError`.

## Internal hackathon event website

Open [`index.html`](./index.html) in a browser to preview the responsive Northstar Build Fest event website. January 15–16, 2027, the ₹500/team registration fee, and the ₹15,000/₹10,000/₹5,000 prize amounts are proposed placeholders and should be confirmed by the event organizers. The registration form is a front-end demonstration; it does not save submissions or process payments. Connect an approved form service and payment process before accepting registrations.
