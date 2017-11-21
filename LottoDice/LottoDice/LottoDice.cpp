// LottoDice.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <conio.h>

using namespace std;
void swap(int *a, int* b);
void BubbleSort(int arr[], int N);
void disArr(int arr[], int N);

int main()
{
    srand(time(0));
    const int maxNum = 33;
    int results[maxNum][6];
    int sum = 0;
    for (int i = 0; i < maxNum; i++)
    {
        bool lotteryNumbers[58];
        int chosenNumbers[6];
        int num = 0;
        int j = 0;
        for (int n = 0; n < 58; n++)
        {
            lotteryNumbers[n] = false;
        }

        while (j < 6)
        {
            num = (rand() % 59) + 1;
            if (!lotteryNumbers[num])
            {
                lotteryNumbers[num] = true;
                chosenNumbers[j] = num;
                j++;
            }
        }

        int sz = sizeof(chosenNumbers) / sizeof(int);
        BubbleSort(chosenNumbers, sz);
        disArr(chosenNumbers, sz);
        cout << endl;
        for (int k = 0; k < sz; k++)
        {
            results[i][k] = chosenNumbers[k];
        }
    }

    int winNumbers[6];

    for (int i = 0; i < 6; i++)
    {
        sum = 0;
        for (int j = 0; j < maxNum; j++)
        {
            sum += results[j][i];
        }
        winNumbers[i] = sum / maxNum;
    }

    int sizeWin = sizeof(winNumbers) / sizeof(int);
    cout << "Final result" << endl;
    disArr(winNumbers, sizeWin);
    cout << endl;
    _getch();
    return 0;
}


// Bubble sort
void BubbleSort(int arr[], int N)
{
    int i, j;
    for (i = 0; i < N; i++)
    {
        for (j = N - 1; j > i; j--)
        {
            if (arr[j] < arr[j - 1])
                swap(&arr[j], &arr[j - 1]);
        }
    }
}

void swap(int *a, int* b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void disArr(int arr[], int N)
{
    int i;
    for (i = 0; i < N; i++)
    {
        printf("%d\t", arr[i]);
    }
}
