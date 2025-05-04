#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char madon[50], hoten[50], ngay[10];
    int tien;
} DonHang;

void doc(int *n, FILE **f, DonHang a[]) {
    *f = fopen("donhang.txt", "rt");
    if(*f == NULL) {
        printf("loi mo file!");
        return;
    }
    fscanf(*f, "%d\n", n);
    for(int i = 0; i < *n; i++) {
        fgets(a[i].madon, 50, *f);
        a[i].madon[strlen(a[i].madon) - 1] = '\0';
        fgets(a[i].hoten, 50, *f);
        a[i].hoten[strlen(a[i].hoten) - 1] = '\0';
        fgets(a[i].ngay, 50, *f);
        a[i].ngay[strlen(a[i].ngay) - 1] = '\0';
        fscanf(*f, "%d\n", &a[i].tien);
    }
    fclose(*f);
}

void tongdoanhthu(int n, DonHang a[]) {
    int sum = 0;
    char s[] = "04/2024";
    for(int i = 0; i < n; i++) {
//strstr(cái to, cái nhỏ) != NULL thì cái nhỏ cóa trong cái to
        if(strstr(a[i].ngay, s) != NULL) {
            sum += a[i].tien;
        }
    }
    printf("Tong doanh thu thang 4 nam 2024 la: %d\n", sum);
}

void dondatnhat(int n, DonHang a[]) {
    int max = a[0].tien;
    for(int i = 1; i < n; i++) {
        if(max < a[i].tien) {
            max = a[i].tien;
        }
    }
    printf("---Don hang co gia tien cao nhat la---\n");
    for(int i = 0; i < n; i++) {
        if(max == a[i].tien) {
            printf("Ma don: %s \nTen khach hang: %s\nNgay mua: %s\nTong tien: %d\n", a[i].madon, a[i].hoten, a[i].ngay, a[i].tien);
        }
    }
}

void thongke(int n, DonHang a[]) {
    char ngay[100][11]; // Lưu các ngày duy nhất
    int slg[100] = {0};    // Đếm số đơn mỗi ngày
    int so_ngay = 0;
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < so_ngay; j++) {
            if(strcmp(a[i].ngay, ngay[j]) == 0) {
                slg[j]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            strcpy(ngay[so_ngay], a[i].ngay);
            slg[so_ngay] = 1;
            so_ngay++;
        }
    }
    printf("--- Thong ke so don hang moi ngay ---\n");
    for(int i = 0; i < so_ngay; i++) {
        printf("Ngay %s: %d don hang\n", ngay[i], slg[i]);
    }
}



int main() {
    int n;
    FILE *f;
    DonHang a[100];
    doc(&n, &f, a);

    tongdoanhthu(n, a);

    dondatnhat(n, a);

    thongke(n, a);

    return 0;
}
