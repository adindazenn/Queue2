/************************************/
/* Program   : tqueue2.c */
/* Deskripsi : realisasi body modul tqueue2 */
/* NIM/Nama  : 24060120120012/Adinda Destifany Zenniar*/
/* Tanggal   : 3 Oktober 2021*/
/***********************************/
#include <stdio.h>
#include "tqueue2.h"
#include "boolean.h"

/*function isEmptyQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q kosong}*/
boolean isEmptyQueue2(tqueue2 Q){
    //kamus lokal

    //algoritma
    if (Q.tail == 0 && Q.head==0){
        return true;
    }
    else{
        return false;
    }
};

/*function isFullQueue2(Q:tQueue2) -> boolean
{mengembalikan true jika Q penuh}*/
boolean isFullQueue2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return (head2(Q) == 1 && tail2(Q) == 5);
};

/*function isOneElement2(Q:tQueue2) -> boolean
{mengembalikan true jika Q berisi 1 elemen}*/
boolean isOneElement2(tqueue2 Q){
    //kamus lokal

    //algoritma
    if (Q.head == Q.tail){
        return true;
    }
    else{
        return false;
    }
};

/*procedure createQueue2 ( output Q:tQueue2 )
{I.S.: -}
{F.S.: Q terdefinisi, kosong}
{Proses: mengisi komponen dengan 0, elemen kosong='@'}*/
void createQueue2(tqueue2 *Q){
    //algoritma
    int i;

	//algoritma
	for (i=1;i<=5;i++){
		(*Q).wadah[i] = '@';
	}
	(*Q).head = 0;
	(*Q).tail = 0;
};

/*Function Head2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terdepan} */
int head2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return Q.head;
};

/*Function Tail2(Q:Tqueue2) -> integer
{mengembalikan posisi elemen terakhir} */
int tail2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return Q.tail;
};

/*Function InfoHead2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terdepan} */
char infoHead2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return Q.wadah[Q.head];
};

/*Function InfoTail2(Q:Tqueue2) -> character
{mengembalikan nilai elemen terakhir} */
char infoTail2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return Q.wadah[Q.tail];
};

/*function sizeQueue2(Q:tQueue2)-> integer
{mengembalikan panjang antrian Q} */
int sizeQueue2(tqueue2 Q){
    //kamus lokal

    //algoritma
    if(isEmptyQueue2(Q)){
            return 0;
        }
        else{
            return Q.tail - Q.head+1;
        }
};

/*procedure printQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak semua isi wadah ke layar}*/
void printQueue2(tqueue2 Q){
    //kamus lokal
    int i;

    //algoritma
    for(i=1;i<=5;i++){
        printf("%c", Q.wadah[i]);
    }
};

/*procedure viewQueue2(input Q:tQueue2)
{I.S.: Q terdefinisi}
{F.S.: -}
{proses: mencetak elemen yang tidak kosong ke layar}*/
void viewQueue2(tqueue2 Q){
    //kamus lokal
    int i;

    //algoritma
    if (!isEmptyQueue2(Q)){
		for(i=1;i<=Q.tail;i++){
			printf("%c ",Q.wadah[i]);
		}
	}
	printf("\n");
};

/*Function IsTailStop2(Q:TQueue2) -> boolean
{mengembalikan true jika Tail tidak dapat lagi geser}
{karena sudah di posisi kapasitas} */
boolean isTailStop2(tqueue2 Q){
    //kamus lokal

    //algoritma
    return (Q.head >= 1 && Q.tail == 5);
};

/*Procedure ResetHead2(input/output Q:TQueue2)
{I.S:Tail=kapasitas, head>1; F.S:head=1 }
{Proses: mengembalikan Head ke indeks 1 }
{Elemen selain head ikut bergeser menyesuaikan} */
/*CATATAN: di praktikum ini, resetHead dilakukan ketika Enqueue */
void resetHead2(tqueue2 *Q){
    //kamus lokal
        int i,j;

    //algoritma
        j = 1;
        for(i=(*Q).head; i<=(*Q).tail; i++){
            (*Q).wadah[j] = (*Q).wadah[i];
            j = j+1;
        }
        (*Q).head = 1;
        (*Q).tail = j-1;
};

/*procedure enQueue2( input/output Q:tQueue2, input E: character )
{I.S.: E terdefinisi}
{F.S.: elemen wadah Q bertambah 1 bila belum penuh}
{proses: menambah elemen wadah Q, jika tail(Q)=kapasitas, maka semua elemen digeser lebih dulu sehingga head(Q)=1 } */
void enqueue2(tqueue2 *Q, char E){
	// kamus lokal

    // algoritma
    if(!isFullQueue2(*Q)) {
        if (isEmptyQueue2(*Q)) {
            (*Q).head = 1;
        }
        if(isTailStop2(*Q)) {
            resetHead2(&(*Q));
        }
        (*Q).tail++;
        (*Q).wadah[tail2(*Q)] = E;
    }
};

/*procedure deQueue2( input/output Q:tQueue2, output E: character )
{I.S.: }
{F.S.: elemen wadah Q berkurang 1 (Head), E=infohead(Q) lama, bila kosong, E='@'}
{proses: mengurangi elemen wadah Q, bila 1 elemen, maka Head dan Tail mengacu ke 0 } */
void dequeue2(tqueue2 *Q, char *E){
    //kamus lokal

	//algoritma
	if(!isEmptyQueue2(*Q)){
            *E = (*Q).wadah[(*Q).head];
            (*Q).wadah[(*Q).head] = ' ';
            if((*Q).head!=5){
                (*Q).head = (*Q).head+1;
            }
            else{
                (*Q).head = 0;
            }
        }
        else{
            *E = ' ';
        }
};
