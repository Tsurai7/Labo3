#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "inputCheck.h"

void ManualInput(int* arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		printf("arr[%d] = ", i);
		arr[i] = Inputcheck();
	}

	for (int i = 0; i < length; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

}


void RandFill(int* arr, int length)
{
	srand(time(0));
	length = (length <= 0) ? 1 : length;

	for (int i = 0; i < length; i++)
		arr[i] = rand() % 100;

	for (int i = 0; i < length; i++)
		printf("arr[%d] = %d\n", i, arr[i]);

}


void FillType(int* arr, int length)
{
	printf("Choose your fill preferences:\n1 - Manual input\n2 - Rand input\n");
	int input = Inputcheck();


	switch (input)
	{
	case 1:
		ManualInput(arr, length);
		break;
	case 2:
		RandFill(arr, length);
		break;
	default:
		FillType(arr, length);
		break;
	}
}