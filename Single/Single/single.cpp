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
	std::cout << "��� ��������� �� ������ �������" << std::endl;
	system("pause");
	return 0;
}