/*23. Создайте класс динамического массива, в котором реализована проверка выхода 
за границы массива. Перегрузите операторы: [ ], =, +, -,++ 
(добавление элемента в конец массива),-- (удаление элемента из конца массива). */


#include <iostream>
using namespace std;

class DinArray
{
public:
	DinArray();
	DinArray(unsigned long size);
	DinArray(DinArray &dinArray);
	int& operator [] (unsigned long index);
	DinArray& operator = (DinArray &dinArray);
	DinArray& operator + (int value);
	DinArray& operator - (int value);
	DinArray& operator ++ ();
	DinArray  operator ++ (int);
	DinArray& operator -- ();
	DinArray  operator -- (int);
	~DinArray();
	void init();
	void random_init(int min, int max);
	void show();
	unsigned long GetSize() { return size; };

private:
	unsigned long size;
	int* array;
};

DinArray::DinArray()
{
	size = 0;
	array = nullptr;
}

DinArray::DinArray(unsigned long size)
{
	this->size = size;
	array = new int[size];
}

DinArray::DinArray(DinArray &dinArray)
{
	size = dinArray.size;
	array = new int[size];
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] = dinArray.array[i];
	}
}

int& DinArray::operator[](unsigned long index)
{
	if (index < size && index >= 0)
	{
		return array[index];
	}
	else
	{
		return array[0];
	}
}

DinArray & DinArray::operator=(DinArray & dinArray)
{
	if (size == 0)
	{
		size = dinArray.size;
		array = new int[size];
	}
	else if (size != dinArray.size)
	{
		delete[]array;
		size = dinArray.size;
		array = new int[size];
	}

	for (unsigned long i = 0; i < size; i++)
	{
		array[i] = dinArray.array[i];
	}

	return *this;

}

DinArray & DinArray::operator+(int value)
{
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] += value;
	}
	return *this;

}

DinArray & DinArray::operator-(int value)
{
	for (unsigned int i = 0; i < size; i++)
	{
		array[i] -= value;
	}
	return *this;
	
}

DinArray & DinArray::operator++()
{
	DinArray temp(size);
	temp = *this;
	delete[]array;
	size++;
	array = new int[size];
	for (unsigned int i = 0; i < size; i++)
		{
			array[i] = temp[i];
		}
	array[size - 1] = 0;
	return *this;
	
}

DinArray DinArray::operator++(int)
{
	DinArray temp = *this;
	++(*this);
	return temp;	
}

DinArray & DinArray::operator--()
{
	if (size > 1)
		{
			DinArray temp(size);
			temp = *this;
			delete[]array;
			size--;
			array = new int[size];
			for (unsigned int i = 0; i < size; i++)
			{
				array[i] = temp[i];
			}
		}
	return *this;
	
}

DinArray DinArray::operator--(int)
{
	DinArray temp = *this;
	--(*this);
	return temp;
}

DinArray::~DinArray()
{
	if (size != 0)
	{
		delete[]array;
	}
}

void DinArray::init()
{
	if (size == 0)
	{
		cout << "Please enter size array: ";
		cin >> size;
		array = new int[size];
	}

	for (unsigned long i = 0; i < size; i++)
	{
		cout << "Please enter " << i + 1 << " element: ";
		cin >> array[i];
	}
}

void DinArray::random_init(int min, int max)
{
	if (size == 0)
	{
		cout << "Please enter size array: ";
		cin >> size;
		array = new int[size];
	}

	

	for (unsigned long i = 0; i < size; i++)
	{
		array[i] = rand() % (max - min + 1) + min;
	}
}

void DinArray::show()
{
	if (size == 0)
	{
		cout << "Array is empty\n";
		return;
	}

	for (unsigned long i = 0; i < size; i++)
	{
		cout << " " << array[i];
	}

	cout << endl;
}

void main()
{
	DinArray obj(10);
	obj.random_init(1,100);
	obj.show();
	obj+10;
	obj.show();
	obj-5;
	obj.show();
	++obj;
	obj.show();
	obj[obj.GetSize() - 1] = obj.GetSize();
	obj.show();
	obj++;
	obj.show();
	obj[obj.GetSize() - 1] = obj.GetSize();
	obj.show();
	--obj;
	obj.show();
	obj--;
	obj.show();
	for (unsigned long i = 0; i < obj.GetSize() ; i++)
	{
		cout << " " << obj[i];
	}
	cout << endl;

}