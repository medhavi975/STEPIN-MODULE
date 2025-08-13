#include <stdio.h>

int isLeap(int y) {
    if (y % 400 == 0) return 1;
    if (y % 100 == 0) return 0;
    if (y % 4 == 0) return 1;
    return 0;
}

int monthDays[] = {31,28,31,30,31,30,31,31,30,31,30,31};

int main() {
    char s1[16], s2[16];
    if(scanf("%s %s", s1, s2) < 1) return 0;          
    if(s2[0] == '\0') scanf("%s", s2);              

    int d1,m1,y1, d2,m2,y2;
    sscanf(s1, "%d-%d-%d", &d1, &m1, &y1);
    sscanf(s2, "%d-%d-%d", &d2, &m2, &y2);

    int ans = 0;
    while (1) {
        long long num = d1;
        num = num * 100 + m1;
        num = num * 10000 + y1;

        if (num % 4 == 0 || num % 7 == 0) ans++;

        if (d1 == d2 && m1 == m2 && y1 == y2) break;

        d1++;
        if (m1 == 2 && isLeap(y1)) {
            if (d1 > 29) { d1 = 1; m1++; }
        } else {
            if (d1 > monthDays[m1 - 1]) { d1 = 1; m1++; }
        }
        if (m1 > 12) { m1 = 1; y1++; }
    }

    printf("%d\n", ans);
    return 0;
}
