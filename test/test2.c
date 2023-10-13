#include<stdio.h>
#include<string.h>

#define MAX 81

void reverse(char str[]) 
{
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) 
    {
        char temp = str[i];
        str[i] = str[length - i - 1];
        str[length - i - 1] = temp;
    }
}

int main()
{
    char array[MAX];
    char all_array[MAX][MAX];
    int char_Count = 0;
    while (fgets(array, sizeof(array), stdin) !=NULL)
    {   
        if (array[strlen(array) - 1] == '\n') 
        {
            array[strlen(array) - 1] = '\0';
        }
        reverse(array);
        strncpy(all_array[char_Count], array, MAX);
        char_Count++;
    }
    
    for (int i = 0; i < char_Count; i++) {
        printf("%s\n", all_array[i]);
    }
    return 0;
}