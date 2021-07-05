//Only movement
// MPU With AD0 High
//Arduino UNO (RIght Side)
#define STATUS_PIN                      13

#define MPU_POWER_REG                   0x6B
#define MPU_POWER_CYCLE                 0b00000000
#define MPU_READ_TIMEOUT                2000
#define MPU_SAMP_FREQ                   250

#define MPU_GYRO_CFG_REG                0x1B
#define MPU_GYRO_READ_REG               0x43
#define MPU_GYRO_READ_REG_SIZE          6
#define MPU_GYRO_CFG_250DEG             0b00000000
#define MPU_GYRO_READINGSCALE_250DEG    131.0
#define MPU_GYRO_CFG_500DEG             0b00001000
#define MPU_GYRO_READINGSCALE_500DEG    65.5
#define MPU_GYRO_CFG_1000DEG            0b00010000
#define MPU_GYRO_READINGSCALE_1000DEG   32.8
#define MPU_GYRO_CFG_2000DEG            0b00011000
#define MPU_GYRO_READINGSCALE_2000DEG   16.4
#define MPU_CALIBRATE_READING_NUM       2000

#define MPU_TEMP_READ_REG               0x41
#define MPU_TEMP_READ_REG_SIZE          2

#define MPU_ACCEL_CFG_REG               0x1C
#define MPU_ACCEL_READ_REG              0x3B
#define MPU_ACCEL_READ_REG_SIZE         6
#define MPU_ACCEL_CFG_2G                0b00000000
#define MPU_ACCEL_READINGSCALE_2G       16384.0
#define MPU_ACCEL_CFG_4G                0b00001000
#define MPU_ACCEL_READINGSCALE_4G       8192.0
#define MPU_ACCEL_CFG_8G                0b00010000
#define MPU_ACCEL_READINGSCALE_8G       4096.0
#define MPU_ACCEL_CFG_16G               0b00011000
#define MPU_ACCEL_READINGSCALE_16G      2048.0

#define MPU2_I2C_ADDRESS                0b1101001
#define shoot 7
#include<Wire.h>
const int mpu2=0x69;
int16_t AccX1,AccY1,AccZ1;
void setup(){
  Serial.begin(115200);
  pinMode(STATUS_PIN,OUTPUT);
  digitalWrite(STATUS_PIN, LOW);
  Wire.begin();
  SetupMPU();
  delay(1000);
  pinMode(shoot,INPUT);
}

void loop(){
  Wire.beginTransmission(mpu2);
  Wire.write(0x3B);
  Wire.endTransmission(false);

  Wire.requestFrom(mpu2,14,true);
  AccX1=Wire.read()<<8|Wire.read();
  AccY1=Wire.read()<<8|Wire.read();
  AccZ1=Wire.read()<<8|Wire.read();
  //Temp1=Wire.read()<<8|Wire.read();
  //GyroX1=Wire.read()<<8|Wire.read();
  //GyroY1=Wire.read()<<8|Wire.read();
  //GyroZ1=Wire.read()<<8|Wire.read();
  
  //Movement part
  if(AccY1>8000)Serial.println("b:");
  else if(AccY1<-7000)Serial.println("f:");

  if(digitalRead(shoot)==HIGH)Serial.println("s:");
  delay(10);

}

void SetupMPU()
{
  Wire.beginTransmission(MPU2_I2C_ADDRESS);
  Wire.write(MPU_POWER_REG);
  Wire.write(MPU_POWER_CYCLE); 
  Wire.endTransmission();
  Wire.beginTransmission(MPU2_I2C_ADDRESS);
  Wire.write(MPU_GYRO_CFG_REG);
  Wire.write(MPU_GYRO_CFG_250DEG); 
  Wire.endTransmission();
  Wire.beginTransmission(MPU2_I2C_ADDRESS);
  Wire.write(MPU_ACCEL_CFG_REG);
  Wire.write(MPU_ACCEL_CFG_2G); 
  Wire.endTransmission();
}
