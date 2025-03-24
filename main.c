#include <stdio.h>
#include "functions.c"

int main() {
    char TenSanPham[100];
    int SoLuong;
    float Gia, TongTien, Thue, GiamGia;
    ThemSanPhamVaoGioHang(TenSanPham, &SoLuong, &Gia, &TongTien, &Thue, &GiamGia);

    return 0;
}