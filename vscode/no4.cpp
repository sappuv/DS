//implement circular queue using array and perform insertion deletion and display cpp

#include <iostream>

const int MAX_SIZE = 3;

class Queue
{
private:
    int arr[MAX_SIZE];
    int front;
    int rear;
    int count;

public:
    Queue()
    {
        front = 0;
        rear = MAX_SIZE - 1;
        count = 0;
    }

    bool isFull()
    {
        return (count == MAX_SIZE);
    }

    bool isEmpty()
    {
        return (count == 0);
    }
    bool enqueue(int element)
    {
        if (isFull())
        {
            std::cout << "Queue is full!" << std::endl;
            return false;
        }

        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = element;
        count++;
        return true;
    }
    bool dequeue()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return false;
        }
        front = (front + 1) % MAX_SIZE;
        count--;
        return true;
    }

    int getFront()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return -1;
        }
        return arr[front];
    }

    void display()
    {
        if (isEmpty())
        {
            std::cout << "Queue is empty!" << std::endl;
            return;
        }

        std::cout << "Elements of the queue: ";
        for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
        {
            std::cout << arr[i] << " ";
        }
        std::cout << arr[rear] << std::endl;
    }
};

int main()
{
    Queue q;

    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.display();

    q.dequeue();

    q.display();

    q.enqueue(4);
    q.enqueue(7);
    q.display();
    return 0;
}