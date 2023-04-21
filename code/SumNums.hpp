#pragma once
#include <iostream>

int sumNums(int n) 
{
    bool a[n][n+1];
    int sum = n;
    n && (sum += sumNums(n - 1));
    return sum;
}