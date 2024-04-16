# Nén cây

## Thuật toán
1. Tạo cây gốc 0
2. Tìm bậc cho các đỉnh
    - Lưu và duyệt các đỉnh i có bậc 1 -> dùng set để lưu các đỉnh theo thứ tự tăng dần
    - Với mỗi đỉnh i được duyệt, giảm 1 bậc của parent[i] -> dùng dfs để tìm cha cho mỗi đỉnh
    - Trong quá trình duyệt có thể sinh ra đỉnh bậc 1:
        - if parent[i]>i -> lưu vào set để duyệt sau
        - else tìm tiếp đến khi xuất hiện parent[i]>i
3. Mỗi đỉnh đã duyệt được lưu vào mảng result
4. Độ phức tạp: O(nlogn)

## Cách chạy chương trình
1. Compile program
```sh
g++ 1-prufercode.cpp -o out
```
2. Executable program
```sh
./out < in2.txt
```
