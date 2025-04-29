# Đề tài: Hệ thống Đo Âm Thanh và Theo Dõi Tiếng Ồn sử dụng platform FUXA

## 👥 Thành viên nhóm
- **Châu Khang Duy**  
- **Nguyễn Thị Hồng Nhung**

## 🎯 Mục tiêu của dự án
Xây dựng một hệ thống IoT sử dụng vi điều khiển ESP8266 và cảm biến âm thanh để:
- Đo cường độ âm thanh môi trường xung quanh.
- Gửi dữ liệu đo được về máy chủ thông qua giao thức MQTT.
- Hiển thị và giám sát dữ liệu trên nền tảng giao diện FUXA SCADA (chạy bằng Docker).


---

## 🚀 Hướng dẫn sử dụng

### 1. Thông tin 
- Thiết bị ESP8266 (NodeMCU hoặc tương đương).
- Cảm biến âm thanh analog.
- Màn hình LCD liquidcrystal_i2c
- Đèn led RGB
- Máy tính cài Docker và Docker Compose.
- Kết nối mạng nội bộ giữa ESP8266 và máy tính. 

---

### 2. Cài đặt MQTT và FUXA bằng Docker

#### 📁 Bước 1: Tải dockercompose_fuxa về.
#### 📁 Bước 2: Mở cmd, đặt tới vị trí đã tải dockercompose_fuxa.
#### 📁 Bước 3: Chạy lệnh.
  ```
  docker compose -f "docker-compose.yml" up -d --build   
```

### 3. Chạy dự án
- Port của Fuxa là 1881:1881, còn của MQTT là 1883:1883.
- Chạy [localhost:1881](http://localhost:1881/) .
