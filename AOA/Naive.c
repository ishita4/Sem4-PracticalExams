#include <stdio.h>
#include <string.h>
char str[20], pat[20];

int main()
{
    int i,j;

    printf("Enter string:\n");
    gets(str);

    printf("Enter pattern:\n");
    gets(pat);

   for(i=0;i<strlen(str);i++)
   {
       for(j=0;j<strlen(pat);j++)
       {
           if(str[i+j] != pat[j])
               break;
       }

       if(pat[j]=='\0')
        printf("Pattern found at position %d",i+1);
   }

    return 0;
}
