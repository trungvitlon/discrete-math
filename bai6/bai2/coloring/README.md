# Coloring

## Thuật toán
- Nhập và lưu lại danh sách cạnh của đồ thị 
- Tìm  k là bậc của đỉnh 
- Dùng thuật toán bfs để sắp xếp thứ tự các đỉnh
    + G là đồ thị chính quy: chọn đỉnh bất kì
    + G không chính quy: chọn đỉnh có bậc < k
- Duyệt đồ thị và gán màu hợp lệ nhỏ nhất cho đỉnh

## Các bước chạy chương trình

1. Bước 1: Mở Terminal
2. Bước 2: Nhập
```sh
g++ main.cpp -o out
```
3. Bước 3: Nhập
```sh
./out < dothi.txt > dothitomau.dot
```
4. Mở file `dothitomau.dot` và xem preview trên VSCode


