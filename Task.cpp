//
// Created by Kate on 28.04.2020.
//

#include "Task.h"
#include "helpers.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE 6
void Task()
{
    int v[SIZE]; // вже відвідані вершини
    int a[SIZE][SIZE]; // матриця зв'язків
    int d[SIZE]; // мінімальна відстань
    int length, nomer_min, min;
    int begin = 0;
    system("cls"); //очищення екрану консолі
    // Створення матриці зв'язків:
    for (int i = 0; i < SIZE; i++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j < SIZE; j++) {
            printf("Enter the length %d - %d: ", i + 1, j + 1);
            length = PositiveInteger("Your input is: ");
            a[i][j] = length;
            a[j][i] = length;
        }
    }
    // Вивід матриці:
    for (int i = 0; i<SIZE; i++)
    {
        for (int j = 0; j<SIZE; j++)
            printf("%5d ", a[i][j]);
        printf("\n");
    }
    //Ініціалізація відстаней та вершин:
    for (int i = 0; i<SIZE; i++)
    {
        d[i] = 10000;
        v[i] = 1;
    }
    d[begin] = 0;
    // Крок алгоритму:
    do {
        nomer_min = 10000;
        min = 10000;
        for (int i = 0; i<SIZE; i++)
        { // Якщо вершину ще не обійшли і її "вага" < min:
            if ((v[i] == 1) && (d[i]<min))
            {
                min = d[i];
                nomer_min = i;
            }
        }
        // Знайдена мін. вага + вага вершини і порівняння її з поточною мінімальною вагою:
        if (nomer_min != 10000)
        {
            for (int i = 0; i<SIZE; i++)
            {
                if (a[nomer_min][i] > 0)
                {
                    length = min + a[nomer_min][i];
                    if (length < d[i])
                    {
                        d[i] = length;
                    }
                }
            }
            v[nomer_min] = 0;
        }
    } while (nomer_min < 10000);
    //Вивід мінімальних відстаней до вершин:
    printf("\nThe shortest length: \n");
    for (int i = 0; i<SIZE; i++)
        printf("%5d ", d[i]);

    int vertic[SIZE]; //відвідані вершини
    int end = 4; //індекс кінцевої вершини (5-1)
    vertic[0] = end + 1; //початковий елемент - кінцева вершина
    int k = 1; //індекс попередньої вершини
    int weight = d[end]; //вага кінцевої вершини

    while (end != begin)
    {
        for (int i = 0; i<SIZE; i++)
            if (a[i][end] != 0)   // якщо є зв'зок:
            {    //Запис нової ваги, якщо така виявиться при перевірці, у масив:
                int temp = weight - a[i][end];
                if (temp == d[i])
                {
                    weight = temp;
                    end = i;
                    vertic[k] = i + 1;
                    k++;
                }
            }
    }
    // Вивід шляху:
    printf("\nOutput of the shortest length:\n");
    for (int i = k - 1; i >= 0; i--)
        printf("%3d ", vertic[i]);
    getchar(); getchar();
}
