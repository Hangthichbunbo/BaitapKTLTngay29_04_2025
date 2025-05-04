#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoten[50];
    float diem;
    char truong;
} thisinh;

void doc(int *n, FILE **f, char *filename, thisinh a[]) {
    printf("Nhap ten file input: ");
    gets(filename);
    *f = fopen(filename, "rt");
    if(*f == NULL) {
        printf("Khong the mo file");
        return;
    }
    fscanf(*f, "%d\n", n);
    for(int i = 0; i < *n; i++) {
        fgets(a[i].hoten, 50, *f);
        a[i].hoten[strcspn(a[i].hoten, "\n")] ='\0';
        fscanf(*f,"%f\n", &a[i].diem);
        fscanf(*f, "%c\n", &a[i].truong);
    }
    fclose(*f);
}

void tongdiem(int n, thisinh a[]) {
    float suma = 0, sumb = 0, sumc = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].truong == 'A'){
            suma += a[i].diem;
        }
        else if(a[i].truong == 'B'){
            sumb += a[i].diem;
        }
        else sumc += a[i].diem;
    }
    printf("Tong diem cua truong A la: %.1f\n", suma);
    printf("Tong diem cua truong B la: %.1f\n", sumb);
    printf("Tong diem cua truong C la: %.1f\n", sumc);
}

void diemmax(int n, thisinh a[]) {
    float max = a[0].diem;
    for(int i = 1; i < n; i++) {
        if(a[i].diem >= max) {
            max = a[i].diem;
        }
    }
    printf("Diem cao nhat ma thi sinh dat duoc la: %.1f\n", max);
    printf("\nDanh sach thi sinh dat diem cao nhat\n");
    printf("%s %25s %10s\n", "Ho ten", "Diem", "Truong");
    for(int i = 0; i < n; i++) {
        if(max == a[i].diem) {
            printf("%s %20.2f %10c", a[i].hoten, a[i].diem, a[i].truong);
        }
    }
}

int main() {
    int n;
    FILE *f;
    char filename[50];
    thisinh a[100];
    doc(&n, &f,filename, a);

    tongdiem(n, a);

    diemmax(n, a);

    return 0;
}