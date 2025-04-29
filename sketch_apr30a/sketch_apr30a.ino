#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <PubSubClient.h>

// Cấu hình WiFi
const char* ssid = "Fablab 2.4G";
const char* password = "Fira@2024";

// Cấu hình MQTT
const char* mqtt_server = "192.168.69.101";
const char* mqtt_topic = "sensor/sound";
const char* mqtt_topic_desc = "sensor/sound_desc";

// Địa chỉ LCD (thường là 0x27 hoặc 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Cảm biến âm thanh
const int soundSensorPin = A0;

// LED RGB (Cathode chung)
const int redPin = D5;
const int greenPin = D6;
const int bluePin = D7;

WiFiClient espClient;
PubSubClient client(espClient);

void setup() {
  Serial.begin(9600);
  
  // LCD khởi động
  lcd.init();
  lcd.backlight();                 // Bật đèn nền
  lcd.setCursor(0, 0);
  lcd.print("Do tieng on:");

  // Đặt LED làm output
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);

  // Kết nối WiFi
  setup_wifi();
  
  // Kết nối MQTT
  client.setServer(mqtt_server, 1883);     // Gán địa chỉ server
  client.setCallback(callback);            // Hàm callback khi nhận dữ liệu (hiện không dùng)
}

// ===== KẾT NỐI WIFI =====
void setup_wifi() {
  delay(10);
  lcd.setCursor(0, 1);
  lcd.print("Connecting WiFi");

  WiFi.begin(ssid, password);       // Bắt đầu kết nối WiFi
  
  // Chờ kết nối thành công
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  // Khi kết nối thành công
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

  lcd.setCursor(0, 1);
  lcd.print("WiFi OK       ");
  delay(1000);
}

// ===== HÀM CALLBACK MQTT (KHÔNG DÙNG) =====
void callback(char* topic, byte* payload, unsigned int length) {
  // Bạn có thể xử lý dữ liệu nhận từ MQTT ở đây nếu cần
}

// ===== TỰ ĐỘNG KẾT NỐI MQTT NẾU MẤT =====
void reconnect() {
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    lcd.setCursor(0, 1);
    lcd.print("MQTT connect...");

    if (client.connect("ESP8266SoundSensor")) {    // ID kết nối MQTT
      Serial.println("connected");
      lcd.setCursor(0, 1);
      lcd.print("MQTT OK       ");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      delay(5000);
    }
  }
}

// ===== VÒNG LẶP CHÍNH =====
void loop() {
  // Kiểm tra kết nối MQTT
  if (!client.connected()) {
    reconnect();
  }
  client.loop();  // Lắng nghe và xử lý các message từ MQTT

  // Đọc giá trị từ cảm biến âm thanh
  int soundValue = analogRead(soundSensorPin);
  Serial.println(soundValue);   // In ra serial để theo dõi

  // Hiển thị giá trị lên LCD
  lcd.setCursor(0, 1);
  lcd.print("Muc: ");
  lcd.print(soundValue);
  lcd.print("    "); // Xóa số cũ nếu giá trị mới ngắn hơn

  // Mô tả mức độ âm thanh
  const char* soundDesc;

  // Phân loại và hiển thị màu LED tương ứng
  if (soundValue <= 75) {
    setColor(0, 255, 0);        // Xanh lá – Yên tĩnh
    soundDesc = "Bình thường";
  } else if (soundValue <= 200) {
    setColor(0, 0, 255);        // Xanh dương – Hơi ồn
    soundDesc = "Hơi ồn";
  } else {
    setColor(255, 0, 0);        // Đỏ – Ồn ào
    soundDesc = "Ồn ào";
  }

  // Gửi dữ liệu qua MQTT
  char msg[50];
  snprintf(msg, 50, "%d", soundValue);
  client.publish(mqtt_topic, msg);         // Gửi giá trị số
  client.publish(mqtt_topic_desc, soundDesc); // Gửi mô tả mức âm thanh

  delay(300);  // Delay giữa các lần đọc/gửi
}

// ===== HÀM ĐIỀU KHIỂN MÀU LED RGB =====
void setColor(int redVal, int greenVal, int blueVal) {
  analogWrite(redPin, redVal);
  analogWrite(greenPin, greenVal);
  analogWrite(bluePin, blueVal);
}