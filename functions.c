#include <stdio.h>
#include "functions.h"
#include <string.h>

void NhapSanPham(char TenSanPham[], int *SoLuong, float *Gia) {
    printf("Nhap ten san pham: ");
    fgets(TenSanPham, 100, stdin);
    TenSanPham[strcspn(TenSanPham, "\n")] = '\0';

    printf("Nhap so luong: ");
    scanf("%d", SoLuong);

    printf("Nhap gia: ");
    scanf("%f", Gia);
    getchar();
}

float TinhTongTien(int SoLuong, float Gia, float *Thue) {
    float TongTien = SoLuong * Gia;
    *Thue = TongTien * 0.1;
    return TongTien + *Thue;
}

float KiemTraGiamGia(float TongTien) {
    if (TongTien >= 1000) {
        printf("Chuc mung! Ban duoc giam gia 15%%.\n");
        return TongTien * 0.15;
    } else {
        return 0;
    }
}

void InThongTinDonHang(char TenKhachHang[], char TenSanPham[], int SoLuong, float Gia, float TongTien, float Thue, float GiamGia) {
    printf("\n---------------------- THONG TIN DON HANG ----------------------\n");
    printf("Ten khach hang: %s\n", TenKhachHang);
    printf("San pham: %s\n", TenSanPham);
    printf("So luong: %d\n", SoLuong);
    printf("Gia tien: %.2f VND\n", Gia);
    printf("Tong tien: %.2f VND\n", TongTien);
    printf("Thue (10%%): %.2f VND\n", Thue);
    printf("Giam gia: %.2f VND\n", GiamGia);
    printf("Tong thanh toan: %.2f VND\n", TongTien + Thue - GiamGia);
    printf("---------------------------------------------------------------\n");
}

void ThemSanPhamVaoGioHang(char TenSanPham[], int *SoLuong, float *Gia, float *TongTien, float *Thue, float *GiamGia) {
    char TiepTuc;
    do {
        printf("\nNhap thong tin san pham:\n");
        NhapSanPham(TenSanPham, SoLuong, Gia);

        *TongTien = TinhTongTien(*SoLuong, *Gia, Thue);
        *GiamGia = KiemTraGiamGia(*TongTien);

        InThongTinDonHang("Khach Hang", TenSanPham, *SoLuong, *Gia, *TongTien, *Thue, *GiamGia);

        printf("Ban co muon mua them (y/n)? ");
        scanf(" %c", &TiepTuc);
    } while (TiepTuc == 'y');
    return 0;
}
