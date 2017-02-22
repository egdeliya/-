#include <iostream>

class A
{
public:
	A()
	{
		static int key = 0;
		key++;
		if (key > 1)
			exit(1);
		else
			std::cout << "Hello from singleton" << std::endl;

	}
};

int main()
{
	A obj;
	system("pause");
	A obj1;
	system("pause");
	return 0;
}