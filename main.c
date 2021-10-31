#include <stdio.h>
#define S 5
void inputdata(int *A)
{
    for (int i = 0; i < S; i++)
    {
        printf("Enter the element number %d = ", i);
        scanf("%d", &A[i]);
    }
}
void display(int *A, int n)
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("}");
    printf("\n");
}
int isUnion(int union1[], int arr1[], int arr2[])
{
    int i, j, k = 0;
    for (i = 0; i < S; i++)
    {
        union1[k] = arr1[i];
        k++;
    }
    for (i = 0; i < S; i++)
    {
        for (j = 0; j < S; j++)
        {
            if (arr1[j] == arr2[i])
            {
                break;
            }
        }
        if (j == S)
        {
            union1[k] = arr2[i];
            k++;
        }
    }
    return k;
}
int isIntersection(int Inter[], int arr1[], int arr2[])
{
    int k = 0, j;
    for (int i = 0; i < S; i++)
    {
        for (int j = 0; j < S; j++)
        {
            if (arr1[j] == arr2[i])
            {
                Inter[k] = arr2[i];
                k++;
            }
        }
    }
    return k;
}
int isDifference(int diff[], int arr1[], int arr2[])
{
    int k = 0, j;
    for (int i = 0; i < S; i++)
    {
        int flag = 1;
        for (int j = 0; j < S; j++)
        {
            if (arr1[i] == arr2[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            diff[k] = arr1[i];
            k++;
        }
    }
    return k;
}
int isSymmetric(int symm[], int arr1[], int arr2[], int diff[])
{
    int k = 0, j;
    for (int i = 0; i < S; i++)
    {
        int flag = 1;
        for (int j = 0; j < S; j++)
        {
            if (arr1[i] == arr2[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            symm[k] = arr1[i];
            k++;
        }
    }
    for (int i = 0; i < S; i++)
    {
        int flag = 1;
        for (int j = 0; j < S; j++)
        {
            if (arr2[i] == arr1[j])
            {
                flag = 0;
                break;
            }
        }
        if (flag == 1)
        {
            symm[k] = arr2[i];
            k++;
        }
    }
    return k;
}
int main()
{
    int n, arr1[S], arr2[S], Union_arr[S * 2], Inter_arr[S * 2], differ_arr[S * 2], symmetr_arr[S * 2];
    char operator;
    printf("Enter the elements of array 1\n");
    inputdata(arr1);
    display(arr1, S);
    printf("Enter the elements of array 2\n");
    inputdata(arr2);
    display(arr2, S);
    do
    {
        printf("Enter which operation you want to perform\n");
        printf("1 = Union\n2 = Intersection\n3 = Difference\n4 = Symmetric Difference\n");
            scanf(" %c", &operator);
        switch (operator)
        {
        case '1':
            n = isUnion(Union_arr, arr1, arr2);
            printf("Union of two arr1 and arr2 is :- ");
            display(Union_arr, n);
            break;
        case '2':
            n = isIntersection(Inter_arr, arr1, arr2);
            printf("Intersection of two arr1 and arr2 is :- ");
            display(Inter_arr, n);
            break;
        case '3':
            n = isDifference(differ_arr, arr1, arr2);
            printf("Difference of two arr1 and arr2 is :- ");
            display(differ_arr, n);
            break;
        case '4':
            n = isSymmetric(symmetr_arr, arr1, arr2, differ_arr);
            printf("Symmetric Difference of two arr1 and arr2 is :- ");
            display(symmetr_arr, n);
            break;
        }
        printf("Do you want to perform operation again(Y/N) = ");
        scanf(" %c", &operator);
    } while (operator== 'Y' || operator== 'y');
    return 0;
}