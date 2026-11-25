static void swap(int *a, int *b)
{
    const int temp = *a;
    *a = *b;
    *b = temp;
}

static int *partation(int *start, int *end)
{
    int *p = start;
    while (start < end){
        if (*start > *end){
            swap (p, start);
            p++;
        }
        start++;
    }
    swap(p, end);
    return p;
}

static void quick_sort(int *start, int *end)
{
    if (start < end){
        int *pivot = partation(start, end);
        quick_sort(start, pivot - 1);
        quick_sort(pivot + 1, end);
    }
}

int hIndex(int* citations, int citationsSize) {

    int * const start = citations;
    int * const end = citations + citationsSize - 1;

    quick_sort(start, end);

    int hIndex = 0;

    for (;hIndex < citationsSize - 1;++hIndex){
        if (hIndex + 1 > *(citations + hIndex)){
            break;
        }
    }

    hIndex += hIndex + 1 <= *(citations + hIndex);
    return hIndex;
}
