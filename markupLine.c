#include <stdlib.h>

// markupLine: return s with pattern markupped
char* markupLine(char* s, char* pattern) {
    char *out = (char*)malloc(len(s)+10);
    
    int from = strIndex(s, pattern);
    
    #ifdef DEBUG
        printf("DEBUG, from: %d\n", from);
    #endif
    
    /*
    if (from < 0)
        return ...;
    */
    
    int i, j;
    for (i = 0, j = 0; i < from; i++, j++)
	out[j] = s[i];
	
    out[j++] = '*';
    
    int k;
    for (k = 0; k < len(pattern); k++, j++)
        out[j] = pattern[k];
    
    out[j++] = '*';    
    
    i += len(pattern);
    
    for (; s[i] != '\0'; i++, j++)
	out[j] = s[i];
	
    out[j] = '\0';
    
    return out;
}
