/** EL2008 Praktikum Pemecahan Masalah dengan Pemrograman 2025/2026
 *   Modul               : 5 - Foundation of Algorithm
 *   Hari dan Tanggal    : 11 Mei 2026
 *   Nama (NIM)          : Michelle (13224098)
 *   Nama File           : soal2.c
 *   Deskripsi           : Membaca sebuah peta koneksi ruangan yang tersimpan dalam bentuk adjacency matric,
 *                          dan menghasilkan ringkasan konektivitas berdasarkan perhitungan derajat setiap simpul,
 *                          simpul maksimum, dan menentukan apakah terdapat simpul yang terisolasi.
 */
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int size;

void readMatrix(int adjmatrix[][size], int size){
    int val;
    for(int i=0; i<size; i++){
        for(int j=0; j<size; j++){
            scanf("%d", &val);
            adjmatrix[i][j]=val;
        }
    }
}

void degree(int adjmatrix[][size], int size, int deg[]){
    for(int i=0; i<size; i++){
        deg[i]=0;
        for(int j=0; j<size; j++){
            if(adjmatrix[i][j]==1){
                deg[i]++;
            }
        }
        printf("DEGREE %d %d\n", i, deg[i]);
    }
}

int maxVertex(int deg[], int size){
    int temp=0;
    for(int i=0; i<size; i++){
        if(deg[temp]<deg[i]){
            temp=i;
        }
    }
    printf("MAX_VERTEX %d\n", temp);
}
void isolasi(int deg[], int size){
    int j=0;
    printf("ISOLATED ");
    for(int i=0; i<size; i++){
        if(deg[i]==0){
            printf("%d ", i);
            j++;
        }
    }if(j==0){
        printf("NONE");
    }
    printf("\n");

}

int main(){
    
    if (scanf("%d", &size) == 1){
        int adjmatrix[size][size];
        readMatrix(adjmatrix, size);
        int deg[size];
        degree(adjmatrix, size, deg);
        maxVertex(deg, size);
        isolasi(deg, size);
    }

}
