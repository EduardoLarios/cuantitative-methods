#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <random>
#include <iostream>
#include <algorithm>

using namespace std;

double linearCong(double x, double a, double c, double m)
{
    long long int r = (int)((x * a) + c) % (int)m;
    return r / 100000.0;
}

int main()
{
    random_device rd;
    mt19937 gen(rd());

    long long int x, a, c, m = 0;
    cout << "Input seed: ";
    cin >> x;
    cout << "Input a: ";
    cin >> a;
    cout << "Input c: ";
    cin >> c;
    cout << "Input mod: ";
    cin >> m;

    double arr[101] = {};
    arr[0] = linearCong(x, a, c, m);

    for (int i = 1; i < 101; i++)
    {
        arr[i] = linearCong(arr[i - 1], a, c, m);
    }

    int j = 10;
    cout << endl ;
    while (j < 101)
    {
        cout << j << ") " << arr[j] << endl;
        j = j + 10;
    }

    sort(arr, arr + 101);
    float median = 0;

    if (101 % 2 != 0)
    {
        median = arr[101 / 2];
    }
    else
    {
        median = (arr[(101 - 1) / 2] + arr[101 / 2]) / 2.0;
    }

    cout << "\nMediana: " << median << endl;
    double s = 0.0;
    for (int i = 0; i < 101; i++)
    {
        s = s + arr[i];
    }

    double promedio = s / 101;
    cout << "\nPromedio: " << promedio << endl;

    cout << "\nMax: " << arr[100] << endl;
    cout << "\nMin: " << arr[0] << endl;

    double acumvar = 0;
    for (int i = 0; i < 101; i++)
    {
        acumvar = acumvar + ((arr[i] - promedio) * (arr[i] - promedio));
    }

    double var = acumvar / 101;
    double stdd = sqrt(var);
    cout << "Deviation: " << arr[0] << endl;

    uniform_real_distribution<> dis(0.0, 1.0);

    float chi_sq = 0;
    int freq[10], e = 100 / 10;

    for (int i = 0; i < 10; i++)
    {
        freq[i] = 0;
    }

    for (int i = 0; i < 101; i++)
    {
        if (arr[i] >= 0 && arr[i] < 0.1)
        {
            freq[0]++;
        }
        else if (arr[i] >= 0.1 && arr[i] < 0.2)
        {
            freq[1]++;
        }
        else if (arr[i] >= 0.2 && arr[i] < 0.3)
        {
            freq[2]++;
        }
        else if (arr[i] >= 0.3 && arr[i] < 0.4)
        {
            freq[3]++;
        }
        else if (arr[i] >= 0.4 && arr[i] < 0.5)
        {
            freq[4]++;
        }
        else if (arr[i] >= 0.5 && arr[i] < 0.6)
        {
            freq[5]++;
        }
        else if (arr[i] >= 0.6 && arr[i] < 0.7)
        {
            freq[6]++;
        }
        else if (arr[i] >= 0.7 && arr[i] < 0.8)
        {
            freq[7]++;
        }
        else if (arr[i] >= 0.8 && arr[i] < 0.9)
        {
            freq[8]++;
        }
        else if (arr[i] >= 0.9 && arr[i] <= 1)
        {
            freq[9]++;
        }
    }

    printf("\nRango\t\t Frecuencia\n");
    printf("[0.0 - 0.1)\t %i\n", freq[0]);
    printf("[0.1 - 0.2)\t %i\n", freq[1]);
    printf("[0.2 - 0.3)\t %i\n", freq[2]);
    printf("[0.3 - 0.4)\t %i\n", freq[3]);
    printf("[0.4 - 0.5)\t %i\n", freq[4]);
    printf("[0.5 - 0.6)\t %i\n", freq[5]);
    printf("[0.6 - 0.7)\t %i\n", freq[6]);
    printf("[0.7 - 0.8)\t %i\n", freq[7]);
    printf("[0.8 - 0.9)\t %i\n", freq[8]);
    printf("[0.9 - 1.0]\t %i\n\n", freq[9]);

    for (int i = 0; i < 10; i++)
    {
        chi_sq += pow((freq[i] - e), 2) / e;
    }

    printf("X2 = %f\n", chi_sq);

    if (chi_sq <= 16.919)
    {
        printf("Se acepta\n");
    }
    else
    {
        printf("Se rechaza\n");
    }

    return 0;
}
