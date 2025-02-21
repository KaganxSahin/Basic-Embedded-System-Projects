// Wiring
/*
- **MQ2 Gas Sensor Wiring**:
  - Connect the `VCC` pin to the `5V` pin of the Arduino Nano.
  - Connect the `GND` pin to the `GND` pin of the Arduino Nano.
  - Connect the `DO` (Digital Output) pin to any digital pin (D2).
  - Connect the `AO` (Analog Output) pin to any analog pin (A0).

- **MPU6050 Wiring**:
  - Connect the `VCC` pin to the `3.3V` or `5V` pin of the Arduino Nano (MPU6050 supports 5V).
  - Connect the `GND` pin to the `GND` pin of the Arduino Nano.
  - Connect the `SCL` pin to the `A5` pin of the Arduino Nano.
  - Connect the `SDA` pin to the `A4` pin of the Arduino Nano.
*/

// Arduino IDE Code

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Create an instance of the Adafruit_MPU6050 class
Adafruit_MPU6050 mpu;

// MQ2 Gas Sensor Pin Definition
#define MQ2_ANALOG_PIN A0  // If using digital output connect to a digital pin.

void setup() {
  Serial.begin(115200);
  Wire.begin();
  
  // Initialize MPU6050
  Serial.println("Initializing MPU6050...");
  if (!mpu.begin()) {
    Serial.println("MPU6050 Connection Error!");
    while (1);
  }

  // Set sensor ranges for MPU6050
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);

  Serial.println("MPU6050 Initialized Successfully!");
  delay(1000);
}

void loop() {
  // Get data from MPU6050
  sensors_event_t a, g, temp;
  mpu.getAccelerometerSensor()->getEvent(&a);
  mpu.getGyroSensor()->getEvent(&g);
  mpu.getTemperatureSensor()->getEvent(&temp);
  
  // Get data from MQ2 gas sensor
  int mq2Value = analogRead(MQ2_ANALOG_PIN);  // Read analog value from MQ2 sensor

  // Print MPU6050 Data
  Serial.println("---- MPU6050 Sensor Data ----");
  Serial.print("Acceleration (X,Y,Z) [m/s²]: ");
  Serial.print(a.acceleration.x); Serial.print(", ");
  Serial.print(a.acceleration.y); Serial.print(", ");
  Serial.println(a.acceleration.z);
  
  Serial.print("Gyroscope (X,Y,Z) [°/s]: ");
  Serial.print(g.gyro.x); Serial.print(", ");
  Serial.print(g.gyro.y); Serial.print(", ");
  Serial.println(g.gyro.z);
  
  Serial.print("Temperature [°C]: ");
  Serial.println(temp.temperature);

  // Print MQ2 Gas Sensor Data
  Serial.println("---- MQ2 Gas Sensor Data ----");
  Serial.print("Analog Value: ");
  Serial.println(mq2Value);

  Serial.println("------------------------------");
  delay(500);  // Delay for more stable data retrieval
}
