//implement circular queue using array and perform insertion deletion and display cpp

#include <iostream.h>
#include<conio.h>

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

    isFull()
    {
	return (count == MAX_SIZE);
    }

    isEmpty()
    {
	return (count == 0);
    }
    enqueue(int element)
    {
	if (isFull())
	{
	    cout << "Queue is full!" << endl;
	    return 1;
	}

	rear = (rear + 1) % MAX_SIZE;
	arr[rear] = element;
	count++;
	return 0;
    }
    dequeue()
    {
	if (isEmpty())
	{
	    cout << "Queue is empty!" << endl;

	    return 1;
	}
	front = (front + 1) % MAX_SIZE;
	count--;
	return 0;
    }

    int getFront()
    {
	if (isEmpty())
	{
	    cout << "Queue is empty!" << endl;
	    return -1;
	}
	return arr[front];
    }

    void display()
    {
	if (isEmpty())
	{
	    cout << "Queue is empty!" << endl;

	}
	else{
		cout << "Elements of the queue: ";
		for (int i = front; i != rear; i = (i + 1) % MAX_SIZE)
		{
		 cout << arr[i] << " ";
		}
		cout << arr[rear] << endl;
	  }
    }
};

int main()
{
    clrscr();
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

    getch();
    return 0;
}