int main (void) {
    int i; int *p;
    i = 1234; p = &i;
    printf ("*p = %d\n", *p);
    printf (" p = %ld\n", p);
    printf (" p = %p\n", p);
    printf ("&p = %p\n", &p);
    return 0;
}