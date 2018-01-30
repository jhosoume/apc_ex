#include <stdio.h>

void fun1(int f, int *j) {
    f = 2;
    j[2] = f*(j[1]);
}

void fun2(int *t, int y) {
    t[2] = 67;
}

void fun3(int *t, int y) {
    *t = 67;
}
 
void fun4(int *t, int y, int *h) {
    *t = 67;
    *h = y*2;
}

void fun5(int *t, int y, int *h) {
    *t = 67;
    fun1(*t, h);
    h[1] = y*2;
}

int main() {
    int v[3], a, b;
    v[0] = 7;
    v[1] = 3;
    v[2] = 90;
    a = 5;
    b = 45;
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 5 15 7 3 90 */
    fun2(v, a);
    /* 
     * Could be
     *      fun2(&a, b)
     *      fun2(&b, b)
     *      fun2(v, a)
     */
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 5 45 7 3 67 */
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 5 45 67 3 67 */
    fun3(&a, a);
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 67 45 7 3 67 */
    fun4(&a, a, &b);
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 67 10 7 3 67 */
    v[0] = 7;
    v[1] = 3;
    v[2] = 90;
    a = 5;
    b = 45;
    fun5(&a, a, v);
    printf("%d %d %d %d %d\n", a, b, v[0], v[1], v[2]);
    /* Output is 67 45 7 10 6 */
    return 0;
}
