#include <WiFi.h>
#include <ArduinoOTA.h>
#define LED_PIN 2  // 보통 ESP32 내장 LED는 GPIO 2
// Wi-Fi 설정
const char* ssid = "Dongah_FE_2.4Ghz";
const char* password = "dongah1!";

void setup() {
  pinMode(LED_PIN, OUTPUT);
  // Serial 시작
  Serial.begin(115200);
  Serial.println();

  // Wi-Fi 연결
  WiFi.begin(ssid, password);
  Serial.print("Connecting to Wi-Fi");
pinMode(LED_PIN, OUTPUT);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to Wi-Fi, IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("OTA Firmware Version: 1.0.12");

  // OTA 초기화
  ArduinoOTA.setHostname("esp32-ota");  // OTA 호스트 이름 설정
  ArduinoOTA.begin();  // OTA 시작
}

void loop() {
  // OTA 처리
  ArduinoOTA.handle();  // OTA 업데이트를 처리

  // 예시: LED blink 코드
  digitalWrite(LED_PIN, HIGH);
  delay(200);
  digitalWrite(LED_PIN, LOW);
  delay(200);
}

