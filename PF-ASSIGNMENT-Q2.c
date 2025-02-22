#include <stdio.h>
#include <string.h>

int main() {
    const char *slogans[] = {"buy now", "save big", "limited offer"};
    int n = sizeof(slogans) / sizeof(slogans[0]);

    for (int i = 0; i < n; i++) {
        int freq[26] = {0}; 
        int len = strlen(slogans[i]);

        
        for (int j = 0; j < len; j++) {
            char ch = slogans[i][j];
            if (ch >= 'a' && ch <= 'z') {
                freq[ch - 'a']++;
            } else if (ch >= 'A' && ch <= 'Z') {
                freq[ch - 'A']++;
            }
        }

    
        printf("For \"%s\": ", slogans[i]);
        for (int j = 0; j < 26; j++) {
            if (freq[j] > 0) {
                printf("{%c: %d, ", (char)(j + 'a'), freq[j]);
            }
        }
        printf("}\n");
    }
    return 0;
}


