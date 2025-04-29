# Đồ án IoT: Hệ thống Đo Âm Thanh và Theo Dõi Tiếng Ồn

## 👥 Thành viên nhóm
- **Châu Khang Duy**  
- **Nguyễn Thị Hồng Nhung**

## 🎯 Mục tiêu của dự án
Xây dựng một hệ thống IoT sử dụng vi điều khiển ESP8266 và cảm biến âm thanh để:
- Đo cường độ âm thanh môi trường xung quanh.
- Gửi dữ liệu đo được về máy chủ thông qua giao thức MQTT.
- Hiển thị và giám sát dữ liệu trên nền tảng giao diện FUXA SCADA (chạy bằng Docker).

Mục tiêu chính:
- Thực hành kết nối thiết bị IoT với mạng MQTT.
- Tìm hiểu và ứng dụng Docker để triển khai nhanh MQTT broker và FUXA.
- Tăng cường hiểu biết về truyền thông trong hệ thống IoT.

---

## 🚀 Hướng dẫn sử dụng

### 1. Yêu cầu
- Thiết bị ESP8266 (NodeMCU hoặc tương đương).
- Cảm biến âm thanh analog.
- Máy tính cài Docker và Docker Compose.
- Kết nối mạng nội bộ giữa ESP8266 và máy tính.

---

### 2. Cài đặt MQTT và FUXA bằng Docker

#### 📁 Bước 1: Tải dockercompose_fuxa về.
#### 📁 Bước 2: Mở cmd, đặt tới vị trí đã tải dockercompose_fuxa.
#### 📁 Bước 3: Chạy lệnh.


```bash
docker-compose up -d
