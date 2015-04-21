#include <iostream>
#include <malloc.h>
#include <assert.h>

using namespace std;

template <typename Data_t>
class stack
{
private:
	Data_t* StackData;
	int StackCurrSize;
	int StackMaxSize;	
	int StackSizeAdd();

public:
	stack(int size);
	~stack();
	int StackOk();
	int push(Data_t NewVal);
	Data_t pop();
};

template <typename Data_t>
stack<Data_t>::stack(int size)
{
	StackMaxSize = size;
	StackCurrSize = -1;                         //for first 	use must be -1

	StackData = new Data_t[StackMaxSize];
}

template <typename Data_t>
stack<Data_t>::~stack()
{
	delete [] StackData;
}

template <typename Data_t>
int stack<Data_t>::StackSizeAdd()
{
	StackMaxSize *= 2;
	StackData = (Data_t*)realloc(StackData, StackMaxSize);
	if (!StackData)
    {
		cout << "NO MEMORY" << endl;
		assert (0);
    }
	return 0;
}

template <typename Data_t>
int stack<Data_t>::push(Data_t NewVal)
{
	StackCurrSize++;
	if (StackCurrSize > StackMaxSize)
		this->StackSizeAdd();
	if (this->StackOk())
		StackData[StackCurrSize] = NewVal;
	else cout << "Stack not OK" << endl;
	return 0;
}

template <typename Data_t>
Data_t stack<Data_t>::pop()
{

	if (this->StackOk())
	{
		StackCurrSize--;
		return (StackData[StackCurrSize + 1]);
		
	}
	else
		cout << "STACK IS EMPTY" << endl;
	return 0;
}

template <typename Data_t>
int stack<Data_t>::StackOk()
{
	return ((StackData != NULL) && (StackCurrSize >= 0) && (StackCurrSize <= StackMaxSize));
}


int main()
{
	stack<int> test_stack(5);

	for (int i = 0; (i < 8); i++)
	{
		    printf("i = %d start: ", i);
			test_stack.push(i);
			printf("i = %d\n", i);
	}
	
	return 0;
}





















