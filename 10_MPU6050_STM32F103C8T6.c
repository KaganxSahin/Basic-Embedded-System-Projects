// Arduino IDE Code

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

Adafruit_MPU6050 mpu;

void setup() {
  Serial.begin(9600);
  Wire.begin();

  if (!mpu.begin()) {
    Serial.println("MPU6050 sensor not found!");
    while (1);
  }

  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
}

void loop() {
  sensors_event_t a, g, temp;
  
  mpu.getAccelerometerSensor()->getEvent(&a);
  mpu.getGyroSensor()->getEvent(&g);
  mpu.getTemperatureSensor()->getEvent(&temp);

  
  Serial.print("Accelerometer - X: ");
  Serial.print(a.acceleration.x);
  Serial.print(" Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(" Z: ");
  Serial.println(a.acceleration.z);

  Serial.print("Gyroscope - X: ");
  Serial.print(g.gyro.x);
  Serial.print(" Y: ");
  Serial.print(g.gyro.y);
  Serial.print(" Z: ");
  Serial.println(g.gyro.z);

  Serial.print("Temperature: ");
  Serial.print(temp.temperature);
  Serial.println(" *C");

  delay(1000); 
}

//Wiring
/*
- **MPU6050**:
  - Connect the `VCC` pin to the `3.3V` pin of the STM32F103C8T6.
  - Connect the `GND` pin to the `GND` pin of the STM32F103C8T6.
  - Connect the `SCL` pin to the `B6` pin (I2C Clock) of the STM32F103C8T6.
  - Connect the `SDA` pin to the `B7` pin (I2C Data) of the STM32F103C8T6.
*/