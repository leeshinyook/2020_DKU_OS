/*
*	DKU Operating System Lab
*	    Lab1 (Scheduler Algorithm Simulator)
*	    Student id : 
*	    Student name : 
*
*   lab1_sched.c :
*       - Lab1 source file.
*       - Must contains scueduler algorithm function'definition.
*
*/

#include <aio.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>
#include <sys/time.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <assert.h>
#include <pthread.h>
#include <asm/unistd.h>
#include "lab1_sched_types.h"
/*
 * you need to implement FCFS, RR, SPN, SRT, HRRN, MLFQ scheduler. 
 */
// burstTime, turnaroundTime,
typedef struct process {
    int processNumber; // 프로세스 번호, priority
    int serviceTime; // 동작시간
    int arriveTime; // 도착시간
    int waitTime; // 대기시간
} process;

void Swap(process *a, process *b) {
    int temp = b;
    b = a;
    a = temp;
}
/*
 * 일단, BubbleSort로 구현했음.
 * **리팩토링시 다른 정렬으로 교체필요**
 */
void SortByArriveTime(process *p, int n) { // 도착시간이 빠른 것 부터, 정렬
    process temp;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < i; j++) {
            if(p[j].arriveTime > p[j + 1].arriveTime) {
//                temp = p[j + 1];
//                p[j + 1] = p[j];
//                p[j] = temp;
                Swap(p[j], p[j + 1]);
            } else if(p[j].arriveTime == p[j + 1].arriveTime && p[j].processNumber > p[j + 1].processNumber) { // 번호가 빠른 것 부터
                Swap(p[j], p[j + 1]);
            }
        }
    }
}
void PrintProcess() {

}
void FIFO(process *p, int n) {
    int Turnaround[n] = {p[0].serviceTime, };
    int Wait[n] = {0, };
    printf("Process number : %d, Turnaround time : %d, Wait time : %d\n", p[0].processNumber, Turnaround[0], Wait[0])
    for(int i=1;i<n;i++)
    {
        Turnaround[i] = Turnaround[i-1] + p[i].serviceTime;
        Wait[i] = Turnaround[i-1] - p[i].arriveTime;
        printf("Process number : %d, Turnaround time : %d, Wait time : %d\n", p[i].processNumber, Turnaround[i], Wait[i])
    }
}
int main() {
    process ps[5];//reference 24page workload (5 process)
    //int num (number of process)
    //scanf("%d", &num)
    for(int i=0;i<5;i++)//insert process information
        scanf("Process number : %d, Arrive time : %d, Service time : %d", &ps[i].processNumber, &ps[i].arriveTime, &ps[i].serviceTime);    
    SortByArriveTime(ps, 5);
    FIFO(ps, 5)
}


