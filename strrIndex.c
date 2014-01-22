// strrIndex(s, t): returns the position of the
// rightmost occurrence of t in s, or -1 if there's none.
int strrIndex(char* s, char* t) {

    int i, j, from = -1;

    for (i = 0; s[i] != '\0'; i++) {
    
        for (j = 0; t[j] != '\0'; j++) {
            if (s[i++] != t[j])
                break;
        }
	
	i = i - j;
	
	if (t[j] == '\0')
	    from = i;

    }

    return from;
}

/*

// Main function, here for testing ...

#include <stdio.h>

int main() {
    char* s = "Hello, World!, orld, or, orld, orld";
    char* t = "orld";

    printf("strrindex(\"%s\", \"%s\") returns %d\n",
              s, t, strrindex(s, t));
}


*/
