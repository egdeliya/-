#include <iostream>

class A
{
public:
	A()
	{
		key++;
		if (key > 1)
		{
			exit(1);
		}
	}
private:
	int key = 0;
};

int main()
{
	A obj;
	A obj1;
	std::cout << "это программа не должна вывести" << std::endl;
	system("pause");
	return 0;
}