#include <stdio.h>
#include <stdlib.h>

#define MAXLINE 200

int getLine(char*, int);
int strIndex(char*, char*);
void printWithMarkdown(char*, char*);
int len(char*);
char *markupLine(char*, char*);

int main(int argc, char* argv[])
{

    if (argc < 2) {
        printf("Usage: %s <pattern_to_search>\n", argv[0]);
        return 1;
    }
	
    char* pattern = argv[1];
    
    char tmpLine[MAXLINE];
    
    int lineCounter = 1;
    
    while (getLine(tmpLine, MAXLINE) != EOF) {
    
        if (strIndex(tmpLine, pattern) >= 0) {
	    printf("%d: %s\n", lineCounter, markupLine(tmpLine, pattern));
	}
    
        lineCounter++;
    
    }
    
}


int len(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

char *markupLine(char* s, char* pattern) {
    //char out[len(s) + 2];
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
        //printf("%c", s[i]);
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

void printWithMarkdown(char* s, char *pattern) {
    int from = strIndex(s, pattern);
    
    #ifdef DEBUG
        printf("DEBUG, from: %d\n", from);
    #endif
    
    if (from < 0)
        return;
    
    int i;
    for (i = 0; i < from; i++)
        printf("%c", s[i]);
	
    printf("*%s*", pattern);
    
    i += len(pattern);
    
    for (; s[i] != '\0'; i++)
        printf("%c", s[i]);
	
    printf("\n");
}


// getLine: get line into s, return length
int getLine(char s[], int lim) {
    int c, i;

    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;

    s[i] = '\0';

    if (c != EOF)
        return i;
    else
        return EOF;
}


// strIndex: return index of t in s, -1 if none
int strIndex(char s[], char t[])
{
    int i, j, from;

    for (i = 0; s[i] != '\0'; i++) {
    
        from = i;
    
        for (j = 0; t[j] == s[i]; ) {
	
	    j++;
	    i++;
	    
	    if (t[j] == '\0')
	        return from;
	
	}
    
    }
    
    if (s[i] == '\0')
        return -1;

}

