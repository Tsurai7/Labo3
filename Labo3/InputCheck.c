#include <stdio.h>
#include <locale.h>

int abs_(int number)
{
    return number < 0 ? -number : number;
}

double pow_(double number, double degree)
{
    double res = 1.0;

    for (int i = 0; i < abs_(degree); i++)
        res *= number;

    return degree == 0 ? res : degree < 0 ? 1.0 / res : res;
}

int Inputcheck()
{
    int symbolcnt = 0, result = 0, mincnt = 0, dot = 0, dotcnt = 0;
    char string[15];

    gets_s(string, 15);


    if (!string[0])
    {
        printf("Invalid input.Empty field.Try again.\n");
        return Inputcheck();
    }
    for (int i = 0; string[i] != '\0'; i++)
    {
        if (string[i] == 44 || string[i] == 46)
        {
            dotcnt++; //подсчет точек
        }
        symbolcnt++; //Подсчет символов
        if (string[i] == 45)
        {
            mincnt++; //Подсчет минусов
        }
        if (string[0] == 45 && string[1] == 48) //Проверка на -0
        {
            printf("Invalid input.Try again\n");
            return Inputcheck();
        }
    }

    if (symbolcnt > 9 || mincnt > 1 || dotcnt > 1) //Проеверка на переполнение и на колличесвто минусов
    {
        printf("Invalid input.Try again\n");
        return Inputcheck();
    }

    if (string[0] == 45) //Если первый символ минус-сдвигаем массив влево
    {
        for (int i = 1; i < symbolcnt; i++)
        {
            string[i - 1] = string[i];
        }
    }
    for (int i = 0; string[i] != '\0'; i++) //поиск индекса точки/запятой
    {
        if (string[i] == 44 || string[i] == 46)
        {
            dot = i;
        }
    }
    if (dotcnt != 0) //Проверка на точку или запятую(если есть сдвигаем влево после запаятой/точки)
    {
        for (int i = dot + 1; i < symbolcnt; i++)
        {
            if (string[i] != 48)
            {
                printf("Invalid input.Try again1\n");
                return Inputcheck();
            }
            string[i - 1] = string[i];
        }
        symbolcnt--;
    }
    for (int i = 0; string[i] != '\0'; i++)
    {

        if (string[i] < 48 || string[i] > 57) //Проверка на что-либо кроме цифр
        {
            printf("Invalid input.Try again\n");
            return Inputcheck();
        }
    }

    int symbolcnt2 = symbolcnt; //Дубляж для цикла
    if (mincnt == 1 && dotcnt == 1)
    {
        int dot2 = dot;
        symbolcnt2--;
        symbolcnt--;
        for (int i = 0; i < dot2; i++) // Перевод из char в int отрицательные
        {
            result += (string[i] - '0') * pow_(10, dot - 1);
            dot--;
        }
        return -1 * result;
    }
    if (mincnt == 1 && dotcnt == 0)
    {
        symbolcnt2--;
        symbolcnt--;
        for (int i = 0; i < symbolcnt2; i++) // Перевод из char в int отрицательные
        {
            result += (string[i] - '0') * pow_(10, symbolcnt - 1);
            symbolcnt--;
        }
        return -1 * result;
    }
    if (mincnt == 0 && dotcnt == 0)
    {
        for (int i = 0; i < symbolcnt2; i++) // Перевод из char в int отрицательные
        {
            result += (string[i] - '0') * pow_(10, symbolcnt - 1);
            symbolcnt--;
        }
        return result;
    }
    if (mincnt == 0 && dotcnt == 1)
    {
        int dot2 = dot;
        for (int i = 0; i < dot2; i++) // Перевод из char в int отрицательные
        {
            result += (string[i] - '0') * pow_(10, dot - 1);
            dot--;
        }
        return result;
    }
}
