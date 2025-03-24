#include <stdio.h>
#include "functions.c"

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
<<<<<<< HEAD
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
=======
    char TenSanPham[100];
    int SoLuong;
    float Gia, TongTien, Thue, GiamGia;

    char TenKhachHang[100];
    printf("Nhap ten khach hang: ");
    fgets(TenKhachHang, sizeof(TenKhachHang), stdin);
    TenKhachHang[strcspn(TenKhachHang, "\n")] = '\0';

    ThemSanPhamVaoGioHang(TenSanPham, &SoLuong, &Gia, &TongTien, &Thue, &GiamGia);
>>>>>>> deeafb4dfb4c46ac1be55d08c06411b3d58e6962

    return 0;
}