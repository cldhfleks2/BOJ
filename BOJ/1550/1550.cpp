#include <stdio.h>
#include <stdlib.h>

int main(void){
    char c[7];
    scanf("%s", &c);
    
    printf("%d", strtol(c, NULL, 16));
    return 0;
}
