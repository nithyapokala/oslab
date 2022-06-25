/*This is an approach which considers the next CPU burst. Each process posses its next CPU burst. When CPU is available, the process having the smallest next CPU burst is allocated CPU.Now it may happen that two or more processes have the same next CPU burst. Then which process to allocate will be decided as per FCFS scheduling*/
#include <stdio.h>
int main() {
 int bt[100], p[100], wt[100], tat[100], i, j, n, total = 0, pos, temp;
 float avg_wt, avg_tat;
 printf("Enter number of process:");
 scanf("%d", &n);
 printf("\nEnter Burst Time:\n");
 for (i = 0; i < n; i++) {
 printf("p%d:", i + 1);
 scanf("%d", &bt[i]);
 p[i] = i + 1;
 }
 for (i = 0; i < n; i++) {
 pos = i;
 for (j = i + 1; j < n; j++) {
 if (bt[j] < bt[pos])
 pos = j;
 }
 temp = bt[i];
 bt[i] = bt[pos];
 bt[pos] = temp;
 temp = p[i];
 p[i] = p[pos];
 p[pos] = temp;
 }
 wt[0] = 0;
 for (i = 1; i < n; i++) {
 wt[i] = 0;
 for (j = 0; j < i; j++)
 wt[i] += bt[j];
 total += wt[i];
 }
printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
 for (i = 0; i < n; i++) {
 tat[i] = bt[i] + wt[i];
 total += tat[i];
 printf("\np%d\t\t %d\t\t %d\t\t%d", p[i], bt[i], wt[i], tat[i]);
 }
avg_wt = (float)total / n;
 total = 0;
 avg_tat = (float)total / n;
 printf("\n\nAverage Waiting Time=%f", avg_wt);
 printf("\nAverage Turnaround Time=%f\n", avg_tat);
}
