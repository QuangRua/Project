#define FUNCTIONS_H
#define FUNCTIONS_H

void NhapSanPham(char TenSanPham[], int *SoLuong, float *Gia);
float TinhTongTien(int SoLuong, float Gia, float *Thue);
float KiemTraGiamGia(float TongTien);
void InThongTinDonHang(char TenKhachHang[], char TenSanPham[], int SoLuong, float Gia, float TongTien, float Thue, float GiamGia);
void ThemSanPhamVaoGioHang(char TenSanPham[], int *SoLuong, float *Gia, float *TongTien, float *Thue, float *GiamGia);


