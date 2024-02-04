#include <stdio.h>
int main(){
 int n, m, i, j, k;
 printf("Enter number of processes:");
 scanf("%d", &n);
 printf("Enter number of resources:");
 scanf("%d", &m);
 int alloc[n][m], max[n][m], need[n][m], av[m];
 for (i = 0; i < n; i++) {
   for (j = 0; j < m; j++) {
     printf("For process %d, Enter allocated resource for resource %d:", i + 1, j + 1);
     scanf("%d", &alloc[i][j]);
    }
  }
 for (i = 0; i < n; i++) {
   for (j = 0; j < m; j++) {
     printf("For process %d, Enter maximum resource for resource %d:", i + 1, j + 1);
     scanf("%d", &max[i][j]);
   }
 }
 for (i = 0; i < m; i++) {
   printf("Enter available instances of resource %d:", i + 1);
   scanf("%d", &av[i]);
 }
 i = 0;
 while (i < m) {
   int sum = 0;
   for (j = 0; j < n; j++) {
     sum = sum + alloc[j][i];
   }
   av[i] = av[i] - sum;
   i++;
 }
 for (i = 0; i < n; i++) {
   for (j = 0; j < m; j++) {
     need[i][j] = max[i][j] - alloc[i][j];
   }
 }
 int f[n], ans[n], ind = 0;
 for (k = 0; k < n; k++) {
   f[k] = 0;
 }
 int y = 0;
 for (k = 0; k < 10; k++) {
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
 int flag = 1;
 for (i = 0; i < n; i++) {
   if (f[i] == 0) {
     flag = 0;
     printf("The given sequence is not safe\n");
     break;
   }
}
 if (flag == 1) {
   printf("Following is the SAFE Sequence:\n");
   for (i = 0; i < n - 1; i++) {
     printf(" P%d ->", ans[i] + 1);
   }
   printf(" P%d\n", ans[n - 1] + 1);
 }
   return 0;
}
