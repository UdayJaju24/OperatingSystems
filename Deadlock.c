#include <stdio.h>

int main() {
    int n, m, i, j, k;

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    printf("Enter the number of resources: ");
    scanf("%d", &m);

    int alloc[n][m], max[n][m], need[n][m], av[m];

    // Input allocation matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("For process %d, enter allocated resource for resource %d: ", i + 1, j + 1);
            scanf("%d", &alloc[i][j]);
        }
    }

    // Input maximum matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            printf("For process %d, enter maximum resource for resource %d: ", i + 1, j + 1);
            scanf("%d", &max[i][j]);
        }
    }

    // Input available resources
    for (i = 0; i < m; i++) {
        printf("Enter available instances of resource %d: ", i + 1);
        scanf("%d", &av[i]);
    }

    // Calculate available resources
    for (i = 0; i < m; i++) {
        int sum = 0;
        for (j = 0; j < n; j++) {
            sum += alloc[j][i];
        }
        av[i] -= sum;
    }

    // Calculate need matrix
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Initialize flags and answer array
    int f[n], ans[n], ind = 0;

    for (k = 0; k < n; k++) {
        f[k] = 0;
    }

    int y = 0;

    // Find safe sequence
    for (k = 0; k < n; k++) {
        for (i = 0; i < n; i++) {
            if (f[i] == 0) {
                int flag = 0;
                for (j = 0; j < m; j++) {
                    if (need[i][j] > av[j]) {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0) {
                    ans[ind++] = i;
                    for (y = 0; y < m; y++) {
                        av[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Check if the sequence is safe
    int flag = 1;
    for (i = 0; i < n; i++) {
        if (f[i] == 0) {
            flag = 0;
            printf("The given sequence is not safe\n");
            break;
        }
    }

    // Print the safe sequence
    if (flag == 1) {
        printf("Following is the SAFE Sequence:\n");
        for (i = 0; i < n - 1; i++) {
            printf(" P%d ->", ans[i] + 1);
        }
        printf(" P%d\n", ans[n - 1] + 1);
    }

    return 0;
}
