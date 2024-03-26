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
    
    printf("Enter a string: ");
    scanf("%s", str);

    printf("Reverse of the string: ");
    reverseString(str);
    
    return 0;
}

