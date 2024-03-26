#include <stdio.h>

void reverseString(char str[]) {
    if (str[0] == '\0') 
        return;
    else {
        reverseString(&str[1]); 
        printf("%c", str[0]);  
    }
}

int main() {
    char str[100];
    
    printf("Enter a number: ");
    scanf("%s", str);

    printf("Reverse of the number: ");
    reverseString(str);
    
    return 0;
}

