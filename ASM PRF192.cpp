#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Khai báo c?u trúc c?a m?t s?n ph?m giày
struct Giay {
    char ten[100];
    float gia;
    int size;
    int soLuong;
};

// Hàm d? thêm m?t s?n ph?m m?i vào danh sách
void themGiay(struct Giay *kho, int *dem) {
    printf("Nhap ten giay: ");
    scanf("%s", kho[*dem].ten);
    printf("Nhap gia: ");
    scanf("%f", &kho[*dem].gia);
    printf("Nhap size: ");
    scanf("%d", &kho[*dem].size);
    printf("Nhap so luong: ");
    scanf("%d", &kho[*dem].soLuong);
    (*dem)++;
    printf("Da them giay thanh cong.\n");
}

// Hàm d? hi?n th? danh sách các s?n ph?m trong c?a hàng
void hienThiKho(const struct Giay *kho, int dem) {
    printf("Kho hang:\n");
    for (int i = 0; i < dem; i++) {
        printf("Ten: %s, Gia: %.2f VND, Size: %d, So luong: %d\n", kho[i].ten, kho[i].gia, kho[i].size, kho[i].soLuong);
    }
}

// Hàm d? c?p nh?t thông tin c?a m?t s?n ph?m trong danh sách
void capNhatGiay(struct Giay *kho, int dem) {
    char ten[100];
    printf("Nhap ten giay muon cap nhat: ");
    scanf("%s", ten);
    for (int i = 0; i < dem; i++) {
        if (strcmp(kho[i].ten, ten) == 0) {
            printf("Nhap gia moi: ");
            scanf("%f", &kho[i].gia);
            printf("Nhap size moi: ");
            scanf("%d", &kho[i].size);
            printf("Nhap so luong moi: ");
            scanf("%d", &kho[i].soLuong);
            printf("Thong tin giay da duoc cap nhat thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay giay.\n");
}

// Hàm d? xóa m?t s?n ph?m kh?i danh sách
void xoaGiay(struct Giay *kho, int *dem) {
    char ten[100];
    printf("Nhap ten giay muon xoa: ");
    scanf("%s", ten);
    for (int i = 0; i < *dem; i++) {
        if (strcmp(kho[i].ten, ten) == 0) {
            for (int j = i; j < *dem - 1; j++) {
                kho[j] = kho[j + 1];
            }
            (*dem)--;
            printf("Giay da duoc xoa thanh cong.\n");
            return;
        }
    }
    printf("Khong tim thay giay.\n");
}

int main() {
    struct Giay kho[100];
    int dem = 0;
    char luaChon;
    do {
        printf("Menu:\n");
        printf("1. Them giay\n");
        printf("2. Hien thi kho hang\n");
        printf("3. Cap nhat giay\n");
        printf("4. Xoa giay\n");
        printf("5. Thoat\n");
        printf("Nhap lua chon cua ban: ");
        scanf(" %c", &luaChon);
        switch (luaChon) {
            case '1':
                themGiay(kho, &dem);
                break;
            case '2':
                hienThiKho(kho, dem);
                break;
            case '3':
                capNhatGiay(kho, dem);
                break;
            case '4':
                xoaGiay(kho, &dem);
                break;
            case '5':
                printf("Dang thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long thu lai.\n");
                break;
        }
    } while (luaChon != '5');

    return 0;
}

