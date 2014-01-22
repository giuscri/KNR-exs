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
