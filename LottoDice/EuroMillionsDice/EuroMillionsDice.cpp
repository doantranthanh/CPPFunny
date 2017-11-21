// EuroMillions.cpp : Defines the entry point for the console application.
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
    const int maxRoll = 26;
    const int maxNum = 7;
    const int firstFiveNumber = 5;
    const int twoLuckyStar = 2;
    int results[maxRoll][maxNum];
    int sum = 0;

    // First Five Numbers

    for (int i = 0; i < maxRoll; i++)
    {
        bool lotteryNumbers[50];
        int chosenNumbers[firstFiveNumber];
        int num = 0;
        int j = 0;
        for (int n = 0; n < 50; n++)
        {
            lotteryNumbers[n] = false;
        }

        while (j < firstFiveNumber)
        {
            num = (rand() % 50) + 1;
            if (!lotteryNumbers[num])
            {
                lotteryNumbers[num] = true;
                chosenNumbers[j] = num;
                j++;
            }
        }

        int sz = sizeof(chosenNumbers) / sizeof(int);
        BubbleSort(chosenNumbers, sz);
        for (int k = 0; k < sz; k++)
        {
            results[i][k] = chosenNumbers[k];
        }
    }

    // Lucky Star Numbers

    for (int i = 0; i < maxRoll; i++)
    {
        bool luckyStarNumbers[12];
        int chosenLuckyStarNumbers[twoLuckyStar];
        int num = 0;
        int j = 0;
        for (int n = 0; n < 12; n++)
        {
            luckyStarNumbers[n] = false;
        }

        while (j < twoLuckyStar)
        {
            num = (rand() % 12) + 1;
            if (!luckyStarNumbers[num])
            {
                luckyStarNumbers[num] = true;
                chosenLuckyStarNumbers[j] = num;
                j++;
            }
        }

        int sz = sizeof(chosenLuckyStarNumbers) / sizeof(int);
        BubbleSort(chosenLuckyStarNumbers, sz);
        for (int k = firstFiveNumber; k < sz+ firstFiveNumber; k++)
        {
            results[i][k] = chosenLuckyStarNumbers[k- firstFiveNumber];
        }
    }


    int winNumbers[maxNum];

    for (int i = 0; i < firstFiveNumber; i++)
    {
        sum = 0;
        for (int j = 0; j < maxRoll; j++)
        {
            sum += results[j][i];
        }
        winNumbers[i] = sum / maxRoll;
    }

    for (int i = firstFiveNumber; i < twoLuckyStar + firstFiveNumber; i++)
    {
        sum = 0;
        for (int j = 0; j < maxRoll; j++)
        {
            sum += results[j][i];
        }
        winNumbers[i] = sum / maxRoll;
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
