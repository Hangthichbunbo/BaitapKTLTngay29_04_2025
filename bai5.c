#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct DonHang{
    char madon[50], hoten[50];

    struct {
        int ngay, thang, nam;
    } ngaymua;

    int tien;
};
typedef struct DonHang DonHang;

void doc(int *n, FILE **f, DonHang a[]) {
    *f = fopen("donhang.txt", "rt");
    if (*f == NULL) {
        printf("Loi mo file!\n");
        return;
    }
    fscanf(*f, "%d\n", n);
    for (int i = 0; i < *n; i++) {
        fgets(a[i].madon, 50, *f);
        a[i].madon[strcspn(a[i].madon, "\n")] = '\0';

        fgets(a[i].hoten, 50, *f);
        a[i].hoten[strcspn(a[i].hoten, "\n")] = '\0';

        fscanf(*f, "%d/%d/%d\n", &a[i].ngaymua.ngay, &a[i].ngaymua.thang, &a[i].ngaymua.nam);
        fscanf(*f, "%d\n", &a[i].tien);
    }
    fclose(*f);
}

void tongdoanhthu(int n, DonHang a[]) {
    int sum = 0;
    for(int i = 0; i < n; i++) {
        if(a[i].ngaymua.thang == 04 && a[i].ngaymua.nam == 2024) {
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
            printf("Ma don: %s \nTen khach hang: %s\nNgay mua: %d/%d/%d\nTong tien: %d\n",
                a[i].madon, a[i].hoten, a[i].ngaymua.ngay, a[i].ngaymua.thang, a[i].ngaymua.nam, a[i].tien);
        }
    }
}

void thongke(int n, DonHang a[]) {
    int slg[100] = {0};  // Đếm số đơn mỗi ngày
    int so_ngay = 0;
    for(int i = 0; i < n; i++) {
        int found = 0;
        for(int j = 0; j < so_ngay; j++) {
            if (a[j].ngaymua.ngay == a[i].ngaymua.ngay && a[j].ngaymua.thang == a[i].ngaymua.thang && a[j].ngaymua.nam == a[i].ngaymua.nam){
                slg[j]++;
                found = 1;
                break;
            }
        }
        if(!found) {
            slg[so_ngay] = 1;
            so_ngay++;
        }
    }
    printf("--- Thong ke so don hang moi ngay ---\n");
    for(int i = 0; i < so_ngay; i++) {
        printf("Ngay %d/%d/%d: %d don hang\n", a[i].ngaymua.ngay, a[i].ngaymua.thang, a[i].ngaymua.nam, slg[i]);
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
