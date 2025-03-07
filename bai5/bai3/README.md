*Đỗ Việt Long - 15/06/2024*
# Đổ nước

## 1. Thuật toán
0. Khởi tạo a[k][i] là lượng nước trong bình i, trong đó:
- k là đỉnh của đồ thị
- i = 0, 1, 2 ứng với lần lượt bình 10, 7, 4 lít (lưu vào L[i])

1. Chạy thuật toán DFS từ đỉnh 0
- Với 3 bình, ta xét tất cả các cách chuyển thỏa mãn đề bài
- `H = min(L[i] - a[k][i], a[k][j])` là min của lượng nước làm đầy bình i hoặc đổ hết từ bình j sang bình i
- Thêm H vào bình i, bớt H từ bình j và bình còn lại giữ nguyên, ta được đỉnh mới

2. Truy vết
- Mảng `prev[k]` để lưu cha của đỉnh k 
- Biến `e = k` là vị trí kết thúc khi 1 trong 2 bình 7l hoặc 4l có đúng 2l trong bình

## Các bước chạy chương trình
- Sử dụng command line
- Chạy lệnh: `gcc donuoc.c -o out`