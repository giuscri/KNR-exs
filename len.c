// len: return length of s
int len(char* s) {
    int i;
    for (i = 0; s[i] != '\0'; i++)
        ;
    return i;
}
