#include <stdio.h>
#include <string.h>

void nhapSanPham(char tenSanPham[], int *soLuong, float *gia) {
    printf("Nhap ten san pham: ");
    fgets(tenSanPham, 100, stdin); 
    tenSanPham[strcspn(tenSanPham, "\n")] = '\0'; 

    printf("Nhap so luong: ");
    scanf("%d", soLuong);

    printf("Nhap gia tien: ");
    scanf("%f", gia);

    getchar();  
}


float tinhTongTien(int soLuong, float gia, float *thue) {
    float tongTien = soLuong * gia;
    *thue = tongTien * 0.1;  
    return tongTien + *thue;
}


float kiemTraGiamGia(float tongTien) {
    if (tongTien >= 1000) {
        printf("Chuc mung! Ban duoc giam gia 10%%.\n");
        return tongTien * 0.1;
    } else {
        return 0;
    }
}


void hienThiDonHang(char tenKhachHang[], char tenSanPham[], int soLuong, float gia, float tongTien, float thue, float giamGia) {
    printf("\n---------------------- THONG TIN DON HANG ----------------------\n");
    printf("Ten khach hang: %s\n", tenKhachHang);
    printf("San pham: %s\n", tenSanPham);
    printf("So luong: %d\n", soLuong);
    printf("Gia tien: %.2f VND\n", gia);
    printf("Tong tien: %.2f VND\n", tongTien);
    printf("Thue (10%%): %.2f VND\n", thue);
    printf("Giam gia: %.2f VND\n", giamGia);
    printf("Tong thanh toan: %.2f VND\n", tongTien + thue - giamGia);
    printf("---------------------------------------------------------------\n");
}


void muaHang(char tenKhachHang[]) {
    int soLuong;
    float gia, tongTien, thue, giamGia;
    char tenSanPham[100];
    char tiepTuc;

    do {
        printf("\nNhap thong tin san pham:\n");
        nhapSanPham(tenSanPham, &soLuong, &gia);
        
        
        tongTien = soLuong * gia;
        giamGia = kiemTraGiamGia(tongTien);
        tongTien = tinhTongTien(soLuong, gia, &thue);

        
        hienThiDonHang(tenKhachHang, tenSanPham, soLuong, gia, tongTien, thue, giamGia);

        
        printf("Ban co muon mua them (y/n)? ");
        scanf(" %c", &tiepTuc);  
        getchar();  

    } while (tiepTuc == 'y' || tiepTuc == 'Y');
}

int main() {
    char tenKhachHang[100];

    
    printf("Nhap ten khach hang: ");
    fgets(tenKhachHang, sizeof(tenKhachHang), stdin);
    tenKhachHang[strcspn(tenKhachHang, "\n")] = '\0';  

    muaHang(tenKhachHang);

    return 0;
}
