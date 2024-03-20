#include <iostream>

class Stack
{
private:
    int max_size;
    int *stack;
    int top;

public:
    Stack(int size)
    {
        max_size = size;
        stack = new int[max_size];
        top = -1;
    }

    ~Stack()
    {
        delete[] stack;
    }

    bool is_empty()
    {
        return top == -1;
    }

    int size()
    {
        return top + 1;
    }

    void push(int item)
    {
        if (top < max_size - 1)
        {
            stack[++top] = item;
            /*  t = t + 1
		        S[t] = e
        */
        }
        else
        {
            std::cout << "Stack is full. Cannot push item: " << item << std::endl;
        }
    }

    int pop()
    {
        if (!is_empty())
        {
            return stack[top--]; /*stack[top--] is an expression that does the following:
    It accesses the element in the stack at the current value of top.
    After accessing that element, it decrements the top variable by 1. This means it reduces the value of top by 1 after retrieving the element.*/
        }
        else
        {
            std::cout << "Stack is empty. Cannot pop an item." << std::endl;
            return -1;
        }
    }

    /*Algorithm pop(){
	if empty() then
		throw EmptyStackException
	 else  
		t = t - 1
		return S[t + 1]
    }
    */
    
};

int main()
{
    int stackSize;
    std::cout << "Enter the size of the stack: ";
    std::cin >> stackSize;

    Stack stack(stackSize);

    int num;
    std::cout << "Enter elements to push onto the stack (0 to stop): ";
    while (true)
    {
        std::cin >> num;
        if (num == 0)
        {
            break;
        }
        stack.push(num);
    }

    std::cout << "Size of stack: " << stack.size() << std::endl;

    std::cout << "Popped item: " << stack.pop() << std::endl;

    std::cout << "Size of stack after popping: " << stack.size() << std::endl;

    std::cout << "Is stack empty? " << stack.is_empty() << std::endl;

    return 0;
}

/*
Enter the size of the stack: 5
Enter elements to push onto the stack (0 to stop): 34 56 37 58 89 0
Size of stack: 5
Popped item: 89
Size of stack after popping: 4
Is stack empty? 0
*/