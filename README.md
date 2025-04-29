# TL_IoT
# Dự án IoT: Đo âm thanh và theo dõi tiếng ồn

## Mục tiêu
Sử dụng ESP8266, cảm biến âm thanh để gửi dữ liệu qua MQTT và hiển thị trên giao diện FUXA.

## Cách sử dụng
1. Dùng `docker-compose up -d` để chạy MQTT và FUXA
2. Nạp code `sound_sensor_mqtt.ino` lên ESP8266
3. ESP sẽ gửi dữ liệu âm thanh đến MQTT topic `sensor/sound`
4. FUXA sẽ đọc dữ liệu và hiển thị

## Cấu hình Wi-Fi và MQTT
Chỉnh sửa các dòng sau trong `sound_sensor_mqtt.ino`:
```cpp
const char* ssid = "Tên WiFi";
const char* password = "Mật khẩu";
const char* mqtt_server = "IP máy chủ";
