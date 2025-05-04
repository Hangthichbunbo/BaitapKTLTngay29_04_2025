#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char hoten[50];
    int luong, mvc;
} nvien;

void doc(int *n, FILE **f, char *filename, nvien a[]) {
    printf("Nhap ten file input: ");
    gets(filename);
    *f = fopen(filename, "rt");
    if(*f == NULL) {
        printf("Loi mo file");
        return;
    }
    fscanf(*f, "%d\n",n);
    for(int i = 0; i < *n; i++) {
        fgets(a[i].hoten, 50, *f);
        a[i].hoten[strcspn(a[i].hoten, "\n")] = '\0';
        fscanf(*f, "%d\n", &a[i].luong);
        fscanf(*f, "%d\n", &a[i].mvc);
    }
    fclose(*f);
}

void soluong(int n, nvien a[]) {
    int sl1 = 0, sl2 = 0, sl3 = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].mvc == 1) {
            sl1++;
        }
        else if (a[i].mvc == 2) {
            sl2++;
        }
        else sl3++;
    }
    printf("So luong cua mvc 1, 2, 3 lan luot la: %d, %d, %d", sl1, sl2, sl3);
}

void timthongtin(int n, nvien a[]) {
    char ten_tim[50];
    printf("Nhap ten nhan vien can tim: ");
    fflush(stdin);
    gets(ten_tim);
    for(int i = 0; i < n; i++) {
        if(strcmp(a[i].hoten, ten_tim) == 0) {
            printf("Ho ten: %s\t\tLuong: %d\tMVC: %d", a[i].hoten, a[i].luong, a[i].mvc);
        }
    }
}

void sapxep(int n, nvien a[]) {
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[j].luong > a[i].luong) {
                nvien tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
    printf("\nDanh sach nhan vien sau sap xep la\n");
    printf("%s %20s %10s\n", "Ho ten", "Luong", "MVC");
    for(int i = 0; i < n; i++) {
        printf("%s %10d %10d\n", a[i].hoten, a[i].luong, a[i].mvc);
    }
}

int main() {
    int n;
    FILE *f;
    char filename[50];
    nvien a[100];
    doc(&n, &f, filename, a);

    timthongtin(n, a);
    sapxep(n, a);

    return 0;
}