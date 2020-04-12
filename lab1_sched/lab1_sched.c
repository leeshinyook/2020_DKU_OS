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
#include <limits.h>
#include "lab1_sched_types.h"
/*
 * you need to implement FCFS, RR, SPN, SRT, HRRN, MLFQ scheduler. 
 */
// burstTime, turnaroundTime,
typedef struct process {
    char processName; // 프로세스 번호, priority
    int serviceTime; // 동작시간
    int arriveTime; // 도착시간
    int waitTime; // 대기시간
    /*for stride----*/
    int stride;
    int ticket;
    int passValue = 0; // initialize
    /*--------------*/
} process;
struct queue
{
    int q[100];
    int begin = 0;
    int end = 0;
    void push(int); // input process
    void pop(); // remove first process
    bool empty(); // check all process is done
    int size(); // count of existent process 
    int front(); // first existent process
    int back(); // last existent process
};
void queue::push(int data)
{
    q[end] = data;
    end += 1;
}
void queue::pop()
{
    q[begin] = 0;
    begin += 1;
}
bool queue::empty()
{
    if(begin == end) return true; 
    else return false;
}
int queue::size()
{
    return end - begin; 
}
int queue::front()
{
    return q[begin]; 
}
int queue::back()
{
    return q[end]; 
}
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
void Stride(process *p, int n) {
    int commonMultiple = 0;
    int min = INT_MIN;
    for (int i = 0; i < n; i++) { // 공배수 계산 -> *유클리드 호제법으로 리팩토링필요
        commonMultiple += p[i].ticket;
    }
    for (int i = 0; i < n; i++) { // process마다 stride 설정
        p[i].stride = commonMultiple / p[i].ticket;
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


