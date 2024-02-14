#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, i, j, k, hit = 0;
    printf("Enter number of frames: ");
    scanf("%d", &n);
    printf("Enter number of processes: ");
    scanf("%d", &m);
    int p[m], hi[m];
    printf("Enter processes: ");
    for (i = 0; i < m; i++) {
        scanf("%d", &p[i]);
    }
    int a[n][m];
    memset(a, -1, sizeof(a));
    int mp[m];
    memset(mp, 0, sizeof(mp));
    for (i = 0; i < m; i++) {
        int c[m][2], cn = 0;
        for (j = 0; j < m; j++) {
            if (mp[j] > 0) {
                c[cn][0] = mp[j];
                c[cn][1] = j;
                cn++;
            }
        }
        for (j = 0; j < n; j++) {
            if (a[j][i] == p[i]) {
                hit++;
                hi[i] = 1;
                mp[p[i]]++;
                break;
            }
            if (a[j][i] == -1) {
                for (k = i; k < m; k++) {
                    a[j][k] = p[i];
                }
                mp[p[i]]++;
                break;
            }
        }
        if (j == n) {
            int maxc = c[0][0], maxj = c[0][1];
            for (j = 1; j < cn; j++) {
                if (c[j][0] > maxc) {
                    maxc = c[j][0];
                    maxj = c[j][1];
                }
            }
            for (j = 0; j < n; j++) {
                if (a[j][i] == maxj) {
                    mp[a[j][i]] = 0;
                    for (k = i; k < m; k++) {
                        a[j][k] = p[i];
                    }
                    mp[p[i]]++;
                    break;
                }
            }
        }
        for (j = 0; j < m; j++) {
            if (p[i] != j && mp[j] > 0) {
                mp[j]++;
            }
        }
    }
    printf("Process ");
    for (i = 0; i < m; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("Frame %d ", i);
        for (j = 0; j < m; j++) {
            if (a[i][j] == -1) {
                printf("E ");
            } else {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
    for (i = 0; i < m; i++) {
        if (hi[i] == 0) {
            printf(" ");
        } else {
           // printf("%d ", hi[i]);
        }
    }
    printf("\nPage Fault %d\n", m - hit);
    return 0;
}

