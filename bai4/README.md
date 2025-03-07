*Đỗ Việt Long - 14/06/2024*
# Tìm kiếm trên đồ thị lớn

## 1. Thuật toán

### Phần A
0. Tiền xử lý
- Hàm `check()` để kiểm tra 2 từ thỏa mãn điều kiện: khác nhau 1 kí tự
- Ánh xạ từ sang số và lưu vào ma trận kề của đồ thị vô hướng G
1. Đếm số liên thông của đồ thị vô hướng G
- Chạy thuật toán DFS trên đồ thị G
- Thêm biến `cc` để đếm số liên thông
2. Tìm đường đi ngắn nhất từ u -> v 
- Chạy thuật toán BFS trên đò thị G
- Với mỗi đỉnh in ra ánh xạ của nó

### Phần B
0. Tiền xử lý
- Hàm `check()` để kiểm tra một từ u có cung với một từ v thỏa mãn 4 chữ cuối của xuất hiện trong v
- Ánh xạ từ sang số và lưu vào ma trận kề của đồ thị có hướng G
- Tạo đồ thị Gr là đảo của G
1. Đếm số thành phần liên thông mạnh
- Chạy thuật toán DFS trên đồ thị Gr và gắn `post` cho mỗi đỉnh
- Chạy thuật toán DFS trên đồ thị G bắt dầu từ đỉnh có `post` lớn nhất và giảm dần theo `post`
2. Tìm thành phần liên thông mạnh với đỉnh u
- Tạo mảng `numcc` để lưu thứ tự của các thành phần phần liên thông
- Duyệt đồ thị G và in ra ánh xạ của những đỉnh i mà `numcc[i] == numcc[u]`
3. Timd đường đi ngắn nhất từ u -> v
- Chạy thuật toán BFS trên đồ thị G
- Với mỗi đỉnh in ra ánh xạ của nó

## 2. Các bước chạy chương trình

- Sử dụng command line

### Phần A
- Bước 1: `gcc bigDataWordA.c -o out`
- Bước 2: `./out < testA.txt`

### Phần B
- Bước 1: `gcc bigDataWordB.c -o out`
- Bước 2: `./out < testB.txt`