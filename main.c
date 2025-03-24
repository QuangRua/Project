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

#include <ctype.h>

// Hàm kiểm tra tiêu đề phim có chứa ký tự đặc biệt
int contains_special_character(char* title) {
    char special_characters[] = "@#$%^&*()!<>?/[]{}";
    for (int i = 0; title[i] != '\0'; i++) {
        for (int j = 0; special_characters[j] != '\0'; j++) {
            if (title[i] == special_characters[j]) {
                return 1; // Nếu tìm thấy ký tự đặc biệt
            }
        }
    }
    return 0; 
}

int main() {
    int n;
    
    // Nhập số vé
    printf("Nhap so luong ve: ");
    scanf("%d", &n);
    
    // Khai báo các mảng lưu thông tin vé
    char customer_name[100][100];
    char movie_title[100][100];
    char show_date[100][20];
    int ticket_code[100];
    
    // Nhập thông tin từng vé
    for (int i = 0; i < n; i++) {
        // Nhập tên khách hàng
        printf("Nhap ten khach hang %d: ", i + 1);
        getchar(); 
        fgets(customer_name[i], sizeof(customer_name[i]), stdin);
        customer_name[i][strcspn(customer_name[i], "\n")] = '\0'; 
        
        // Nhập tiêu đề phim với kiểm tra ký tự đặc biệt
        do {
            printf("Nhap tieu de phim %d: ", i + 1);
            fgets(movie_title[i], sizeof(movie_title[i]), stdin);
            movie_title[i][strcspn(movie_title[i], "\n")] = '\0'; 
            
            if (contains_special_character(movie_title[i])) {
                printf("Tieu de phim chua ky tu dac biet! Vui long nhap lai.\n");
            }
        } while (contains_special_character(movie_title[i]));
        
        // Nhập ngày chiếu
        printf("Nhap ngay chieu cua phim %d: ", i + 1);
        fgets(show_date[i], sizeof(show_date[i]), stdin);
        show_date[i][strcspn(show_date[i], "\n")] = '\0'; 
        
        // Nhập mã vé
        printf("Nhap ma ve cua phim %d: ", i + 1);
        scanf("%d", &ticket_code[i]);
    }
    
    // Hiển thị thông tin vé
    printf("\nDanh sach ve da nhap:\n");
    for (int i = 0; i < n; i++) {
        printf("\nVe %d:\n", i + 1);
        printf("Ten khach hang: %s\n", customer_name[i]);
        printf("Tieu de phim: %s\n", movie_title[i]);
        printf("Ngay chieu: %s\n", show_date[i]);
        printf("Ma ve: %d\n", ticket_code[i]);
    }

    return 0;
}