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
	//int StackSizeStep;	
	int StackSizeAdd();

public:
	stack(int size);//, int step);  это лишнее
	~stack();
	int StackOk();
	int StackPush(Data_t NewVal);
	Data_t StackPop();

};

template <typename Data_t>
stack<Data_t>::stack(int size)//, int step)
{
	StackMaxSize = size;
	StackCurrSize = -1;                         //for first 	use must be -1
	//StackSizeStep = sizeof (Data_t);

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
	StackMaxSize *= 2;//SizeStep;
	StackData = (Data_t*)realloc(StackData, StackMaxSize);
	if (!StackData)
    {
		cout << "NO MEMORY" << endl;

		assert (0);
    }
	return 0;
}

template <typename Data_t>
int stack<Data_t>::StackPush(Data_t NewVal)
{
	StackCurrSize++;
	if (StackCurrSize > StackMaxSize)
		this->StackSizeAdd;
	if (this->StackOk())
		StackData[StackCurrSize] = NewVal;
	return 0;
}

template <typename Data_t>
Data_t stack<Data_t>::StackPop()
{
	if (this->StackOk)
	{
		return (StackData[StackCurrSize]);
		StackCurrSize--;
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
	
	return 0;
}





















