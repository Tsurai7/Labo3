#include <stdio.h>
#include "tasks.h"
#include "inputCheck.h"

int main()
{
	printf("Enter the task number:\n1 - Task1.14\n2 - Task2.14\n3 - Task3.14\n");
	int input = Inputcheck();


	switch (input)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		printf("Wrong input\n");
		main();
		break;
	}
	return 0;
}