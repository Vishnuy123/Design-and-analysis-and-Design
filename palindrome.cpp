#include <stdio.h>
#include <string.h>
#include <stdbool.h>
bool isPalindrome(const char *str) {
    int length = strlen(str);
    for (int i = 0; i < length / 2; i++) {
        if (str[i] != str[length - 1 - i]) {
            return false; 
        }
    }
    return true; 
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    
    if (isPalindrome(str)) {
        printf("Yes, it's a palindrome.\n");
    } else {
        printf("No, it's not a palindrome.\n");
    }
    
    return 0;
}

