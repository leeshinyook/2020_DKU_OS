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
    char processName; // 프로세스 번호
    int runTime; // 동작시간
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
            } else if(p[j].arriveTime == p[j + 1].arriveTime && p[j].processName > p[j + 1].processName) { // 이름순.
                Swap(p[j], p[j + 1]);
            }
        }
    }
}
void PrintProcess() {

}

int main() {

}


