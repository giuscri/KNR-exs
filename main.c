#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 200

int main(int argc, char** argv)
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
