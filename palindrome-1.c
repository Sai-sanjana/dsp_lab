// program to find the longest palindromic substring

#include <stdio.h>
#include <string.h>

//function to print string
void display_string(char* str, int start, int end)
{
	int i;
    for (i = start; i <= end; ++i)
        printf("%c", str[i]);
}

//function to find longest palindrome
int longest_palindrome(char* str)
{

    int len = strlen(str);
    int substr_len = 1;

    int start, end,i,temp=0;

    for (i = 1; i < len; ++i) 
	{
        start = i - 1;
        end = i;
        while (start >= 0 && end < len && str[start] == str[end]) 
		{
            --start;
            ++end;
        }
        
        ++start; --end;
        if (str[start] == str[end] && end - start + 1 > substr_len)
		{
        	temp = start;
            substr_len = end - start + 1;
        }
        start = i - 1;
        end = i + 1;
        while (start >= 0 && end < len && str[start] == str[end]) 
		{
            --start;
            ++end;
        }
      
        ++start; --end;
        if(str[start] == str[end] && end - start + 1 > substr_len) 
		{
            temp = start;
              substr_len = end - start + 1;
        }
    }

    printf("Longest palindrome substring is: ");
    display_string(str, temp, temp + substr_len - 1);

    return substr_len;
}


int main()
{
    char str[20]={};
    printf("\n Enter input string: ");
    scanf("%[^\t\n]s",str); //to consider spaces
    printf("\n\n Output: \n");
    longest_palindrome(str);
    printf("\n\n");
    return 0;
}
