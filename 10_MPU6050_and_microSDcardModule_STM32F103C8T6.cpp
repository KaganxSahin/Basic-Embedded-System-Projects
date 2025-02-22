//Wiring
/*
- **MPU6050**:
  - Connect the `VCC` pin to the `3.3V` pin of the STM32F103C8T6.
  - Connect the `GND` pin to the `GND` pin of the STM32F103C8T6.
  - Connect the `SCL` pin to the `B6` pin (I2C Clock) of the STM32F103C8T6.
  - Connect the `SDA` pin to the `B7` pin (I2C Data) of the STM32F103C8T6.

- **microSD Card Module**:
  - Connect the `CS` pin to the `PC13` pin of the STM32F103C8T6.
  - Connect the `SCK` pin to the `A5` pin of the STM32F103C8T6.
  - Connect the `MOSI` pin to the `A7` pin of the STM32F103C8T6.
  - Connect the `MISO` pin to the `A6` pin of the STM32F103C8T6.
  - Connect the `VCC` pin to the `5V` pin of the STM32F103C8T6.
  - Connect the `GND` pin to the `GND` pin of the STM32F103C8T6.
*/

// Arduino IDE Code

#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <SD.h>

Adafruit_MPU6050 mpu;

const int chipSelect = PC13; 

File dataFile;

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

  if (!SD.begin(chipSelect)) {
    Serial.println("SD card initialization failed!");
    while (1);
  }

  dataFile = SD.open("datalog.txt", FILE_WRITE);
  if (!dataFile) {
    Serial.println("Failed to open datalog.txt.");
    while (1);
  }
  Serial.println("SD card and file successfully opened.");
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

  if (dataFile) {
    dataFile.print("Accelerometer - X: ");
    dataFile.print(a.acceleration.x);
    dataFile.print(" Y: ");
    dataFile.print(a.acceleration.y);
    dataFile.print(" Z: ");
    dataFile.println(a.acceleration.z);

    dataFile.print("Gyroscope - X: ");
    dataFile.print(g.gyro.x);
    dataFile.print(" Y: ");
    dataFile.print(g.gyro.y);
    dataFile.print(" Z: ");
    dataFile.println(g.gyro.z);

    dataFile.print("Temperature: ");
    dataFile.print(temp.temperature);
    dataFile.println(" *C");
    dataFile.println(); 

    dataFile.flush(); 

    
    dataFile.seek(0); 
    while (dataFile.available()) {
      Serial.write(dataFile.read()); 
    }
  } else {
    Serial.println("Error writing to datalog.txt.");
  }

  delay(1000); 
}
