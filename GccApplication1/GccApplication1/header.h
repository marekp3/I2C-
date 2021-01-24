void I2C_Init();
void I2C_Start();
void I2C_Stop();
void I2C_SetBusSpeed(uint16_t speed);
void I2C_SendAddr(uint8_t address);
uint8_t I2C_ReceiveData_NACK();
uint8_t I2C_ReceiveData_ACK();
void I2C_SendByte(uint8_t byte);