


int main() {

    int x = 10;
    char a = 'a';
    float pi = 3.14;

    int* p1;
    char* p2;
    float* p3;

    p1 = &x;
    p2 = &a;
    p3 = &pi;

    *p1 = 20;
    *p2 = 'b';
    *p3 = 5.17;

    printf("%d, %c, %f", x, a, pi);

    return 0;
}