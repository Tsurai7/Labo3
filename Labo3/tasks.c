#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "inputCheck.h"
#include "FillType.h"
#define LENGTH 20

void InputArr(int* arr);
void ShowArr(int* arr);
int* Subtractor(int* firstNum, int* secondNum, int* flag);
char* itoa_(int* number, int length, int flag);
int* ArrBuilder(int length);


void task1()
{
	int arr[100];
	printf("Enter length of array:\n");
	int length = Inputcheck();

	while (length < 1)
	{
		printf("Error: invalid length\n");
		printf("Enter length of array:\n");
		int length = Inputcheck();
	}

	FillType(arr, length);

	int minElindex = 0, firstNegInd = 0, sum = 0, negCounter = 0, secondNegInd = 0;


	for (int i = 0; i < length; i++)
	{
		minElindex = (arr[i] < arr[i + 1]) ? i + 1 : minElindex;
		negCounter += (arr[i] < 0) ? 1 : 0;
		secondNegInd = (arr[i] < 0) ? i : secondNegInd;
	}

	for (int i = length; i > 0; i--)
		firstNegInd = (arr[i] < 0) ? i : firstNegInd;


	if (negCounter > 1)
	{
		for (int i = firstNegInd; i < secondNegInd; i++)
			sum += arr[i];
	}

	printf("Min element = %d index = %d\nSum between first and second negative = %d\n", arr[minElindex], minElindex, sum);
}

void task2()
{

}

void task3()
{
	srand(time(0));
	int flag = 0;

	int* num1 = ArrBuilder(LENGTH);
	int* num2 = ArrBuilder(LENGTH);

	printf("First num: \t");
	ShowArr(num1);
	printf("Second num: \t");
	ShowArr(num2);

	int* answer = Subtractor(num1, num2, &flag);

	printf("  Answer: \t");
	printf("%s", itoa_(answer, LENGTH, flag));
}

int* Subtractor(int* firstNum, int* secondNum, int* flag)
{
	int* res = calloc(LENGTH, sizeof(int));

	if (secondNum[0] > firstNum[0])
	{
		for (int i = LENGTH - 1; i >= 0; i--)
		{
			if (secondNum[i] - firstNum[i] < 0)
			{
				secondNum[i - 1 > 0 ? i - 1 : 0]--;
				secondNum[i] += 10;
				i++;
			}
			res[i] = secondNum[i] - firstNum[i];
			*flag = 1;
		}
	}
	else
		for (int i = LENGTH - 1; i >= 0; i--)
		{
			if (firstNum[i] - secondNum[i] < 0)
			{
				firstNum[i - 1 > 0 ? i - 1 : 0]--;
				firstNum[i] += 10;
				i++;
			}
			res[i] = firstNum[i] - secondNum[i];
		}

	return res;
}

char* itoa_(int* number, int length, int flag)
{
	if (flag)
	{
		char* result = malloc((length + 2) * sizeof(char));
		result[0] = '-';

		for (int i = 0; i < length; i++)
			result[i + 1] = number[i] + '0';

		result[length + 1] = '\0';
		return result;
	}

	char* result = calloc((length + 1), sizeof(char));

	for (int i = 0; i < length; i++)
		result[i] = number[i] + '0';

	result[length] = '\0';
	return result;
}

void InputArr(int* arr)
{
	for (int i = 0; i < LENGTH; i++)
	{
		printf("arr[%d] = ", i);
		scanf_s("%d", &arr[i]);
	}
}

int* ArrBuilder(int length)
{

	int* number = calloc(length, sizeof(int));

	for (int i = 0; i < length; i++)
		number[i] = rand() % 10;

	return number;
}

void ShowArr(int* arr)
{
	for (int i = 0; i < LENGTH; i++)
		printf("%d", arr[i]);

	printf("\n");
}
