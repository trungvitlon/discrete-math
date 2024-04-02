Họ tên: Đỗ Việt Long
MSSV: 20235769
Nội dung: Bài tập lập trình 1 - Nén cây
Mô tả thuật toán:
  - Tạo cây gốc 0
  - Tìm bậc cho các đỉnh
  - Lưu và duyệt các đỉnh i có bậc 1 -> dùng set để lưu các đỉnh theo thứ tự tăng dần
  - Với mỗi đỉnh i được duyệt, giảm 1 bậc của parent[i] -> dùng dfs để tìm cha cho mỗi đỉnh 
  - Trong quá trình duyệt có thể sinh ra đỉnh bậc 1:
    + if parent[i]>i -> lưu vào set để duyệt sau
    + else tìm tiếp đến khi parent[i]>i
  - Mỗi đỉnh đã duyệt được lưu vào mảng result
Độ phức tạp: O(nlogn)
