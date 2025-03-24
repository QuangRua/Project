#include <stdio.h>
#include "functions.c"

int main() {
    char TenSanPham[100];
    int SoLuong;
    float Gia, TongTien, Thue, GiamGia;

    char TenKhachHang[100];
    printf("Nhap ten khach hang: ");
    fgets(TenKhachHang, sizeof(TenKhachHang), stdin);
    TenKhachHang[strcspn(TenKhachHang, "\n")] = '\0';

    ThemSanPhamVaoGioHang(TenSanPham, &SoLuong, &Gia, &TongTien, &Thue, &GiamGia);

    return 0;
}
