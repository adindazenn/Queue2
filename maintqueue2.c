/************************************/
/* Program   : maintqueue2.c */
/* Deskripsi : driver main modul tqueue2 */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 3 Oktober 2021*/
/***********************************/
#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

int main(){
    //kamus main
    tqueue2 A;
    char c;

    //algoritma
    createQueue2(&A);
    printQueue2(A);
    printf("\n");
    if (isEmptyQueue2(A)){
        printf("Queue kosong\n");
    }
    else{
        printf("Queue tidak kosong\n");
    }
    if (isFullQueue2(A)){
        printf("Queue penuh\n");
    }
    else{
        printf("Queue tidak penuh\n");
    }
    enqueue2(&A,'d');
    if(isOneElement2(A)){
        printf("Queue memiliki satu elemen\n");
    }
    else {
        printf("elemen bukan terdiri atas satu elemen\n");
    }
    printf("indeks head A : %d\n", head2(A));
    printf("indeks tail A : %d\n", tail2(A));
    printf("info head A = %c\n", infoHead2(A));
    printf("info tail A = %c\n", infoTail2(A));
    enqueue2(&A,'i');
    enqueue2(&A,'n');
    enqueue2(&A,'d');
    enqueue2(&A,'a');
    printf("indeks head A : %d\n", head2(A));
    printf("size queue A = %d\n", sizeQueue2(A));
    if(isTailStop2(A)){
        printf("tail tidak dapat digeser lagi\n");
    }
    else {
        printf("tail dapat bergeser lagi\n");
    }
    viewQueue2(A);
    dequeue2(&A,&c);
    viewQueue2(A);
    printf("indeks head A : %d\n", head2(A));
    resetHead2(&A);
    printf("setelah reset head\n");
    printf("indeks head A : %d\n", head2(A));

    return 0;
}
