#ifndef MERGESORTSHOWS_H
#define MERGESORTSHOWS_H

#include "Store.h"

class MergeSortShows
{
private:
    static void mergeSort(int arr[], int left, int right, const Store &store);
    static void merge(int arr[], int left, int mid, int right, const Store &store);

public:
    static void sortIndices(int arr[], int count, const Store &store);
};

#endif