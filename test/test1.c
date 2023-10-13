#include<stdio.h>
#include<stdbool.h>
#define MAX 50



void merge_and_sort(int arr1[], int size1, int arr2[], int size2, int result[], int *res_size) 
{
    int temp[MAX];
    int i = 0, j = 0, k = 0;
    
    // 合并两个数组
    while (i < size1 && j < size2) 
    {
        if (arr1[i] < arr2[j]) 
        {
            temp[k++] = arr1[i++];
        } else 
        {
            temp[k++] = arr2[j++];
        }
    }
    
    while (i < size1) 
    {
        temp[k++] = arr1[i++];
    }
    while (j < size2) 
    {
        temp[k++] = arr2[j++];
    }
    
    // 去除重复的数字并存储到结果数组
    int lastIndex = -1;
    for (i = 0; i < k; i++) 
    {
        if (lastIndex == -1 || temp[i] != result[lastIndex]) 
        {
            result[++lastIndex] = temp[i];
        }
    }
    *res_size = lastIndex + 1;
}

int main() {
    int arr1[50], arr2[50], result[MAX][MAX], sizes[MAX], size1, size2, res_size, idx = 0;
    
    while (true) 
    {
        size1 = 0;
        size2 = 0;

        if (scanf("%d", &arr1[size1++]) == EOF) 
        {
            break; // 结束循环，如果没有更多的数据输入
        }
        while (getchar() != '\n') 
        {
            scanf("%d", &arr1[size1++]);
        }
        
        if (scanf("%d", &arr2[size2++]) == EOF)
        {
            break; // 结束循环，如果没有更多的数据输入
        }
        while (getchar() != '\n') 
        {
            scanf("%d", &arr2[size2++]);
        }

        merge_and_sort(arr1, size1, arr2, size2, result[idx], &res_size);
        sizes[idx] = res_size;
        idx++;
    }

    for (int i = 0; i < idx; i++) 
    {
        for (int j = 0; j < sizes[i]; j++) 
        {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}