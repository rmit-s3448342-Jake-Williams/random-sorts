#include <iostream>
#include <stdlib.h>

void selection(int[], int n);
void bubble(int[], int n);
void insertion(int[], int);
void insert_alt(int[], int);
void quicksort(int[], int, int);
int partition(int[], int, int);
void mergesort(int[], int);
void copy(int[], int[], int, int, int);
void merge(int[], int[], int[], int, int);
void shell(int[], int);

void print(int[], int n);
void swap(int[], int, int);

int main(int argc, char** argv)
{
    int array[] = { 3, 9, 4, 2, 7, 5, 1, 6, 10, 8 };
    int n = sizeof array / sizeof(int);
   
    switch (argv[1][0])
    {
        case 's': selection(array, n); break;
        case 'b': bubble(array, n); break;
        case 'i': insert_alt(array, n); break;
        case 'm': mergesort(array, n); break;
        case 'q': quicksort(array, 0, n-1); break;
    }    

    print(array, n);
}

void print(int array[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << array[i] << " ";
    
    std::cout << std::endl;
}

void selection(int array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min = i;

        for (int j = i + 1; j < n; j++)
        {
            if (array[j] < array[min])
                min = j;
        }

        swap(array, i, min);
    }
}

void bubble(int array[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (array[j] > array[j+1])
                swap(array, j, j+1);
        }
    }
}

void insertion(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int v = array[i];
        int j = i-1;

        while (j >= 0 && array[j] > v)
        {
            array[j+1] = array[j];
            j--;
        }

        array[j+1] = v;
    }
}

void insert_alt(int array[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i-1;

        while (j >= 0 && array[j] > array[j+1])
        {
            swap(array, j, j+1);
            j--;
        }
    }
}

void merge(int a[], int b[], int c[], int nb, int nc)
{
    int i = 0, j = 0, k = 0;

    while (i < nb && j < nc)
    {
        if (b[i] <= c[j])
            a[k] = b[i++];

        else
            a[k] = c[j++];
        
        k++;
    }

    if (i == nb)
        copy(a, c, k, j, nc-j);     
    else
        copy(a, b, k, i, nb-i);
}

void copy(int a[], int b[], int starta, int startb, int n)
{
    for (int i = 0; i < n; i++)
        a[starta++] = b[startb++];
}

void mergesort(int array[], int n)
{
    if (n<=1)
        return;

    int sizeb = n/2;
    int sizec = n-n/2;
    
    int* b = (int*)malloc(sizeb*sizeof(int));
    int* c = (int*)malloc(sizec*sizeof(int));
    
    copy(b, array, 0, 0, sizeb);
    copy(c, array, 0, sizeb, sizec);

    mergesort(b, sizeb);
    mergesort(c, sizec);
    merge(array, b, c, sizeb, sizec);
}

void swap(int array[], int i, int j)
{
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void quicksort(int array[], int low, int high)
{
    if (low < high)
    {
        int p = partition(array, low, high);
        quicksort(array, low, p);
        quicksort(array, p+1, high);
    }
}


int partition(int array[], int low, int high)
{
    int pivot = array[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do { i++; } while (array[i] < pivot);
        do { j--; } while (array[j] > pivot);

        if (i >= j)
            return j;

        swap(array, i, j);
    }
}


















