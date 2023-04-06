#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch[20];
    printf("ENTER STRING : ");
    gets(ch);//used as a scanf for storing string with in between spaces (it is inbuilt function)
    printf("%s",ch);
    return 0;
}
