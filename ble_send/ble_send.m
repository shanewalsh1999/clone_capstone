clc; clear; 

bleAddress = "98B22EEE-F9CA-420E-9F0B-7976E1D0D356";
iot = ble(bleAddress);

muscleToggleServiceUUID = "19B10000-E8F2-537E-4F6C-D104768A1214";
muscleOneToggle = characteristic(iot,muscleToggleServiceUUID,"00A1");
muscleTwoToggle = characteristic(iot,muscleToggleServiceUUID,"00A2");
muscleThreeToggle = characteristic(iot,muscleToggleServiceUUID,"00A3");

muscleVoltageServiceUUID = "19B10000-E8F2-537E-4F6C-D204768A1214";
muscleOneVoltage = characteristic(iot,muscleVoltageServiceUUID,"00B1");
muscleTwoVoltage = characteristic(iot,muscleVoltageServiceUUID,"00B2");
muscleThreeVoltage = characteristic(iot,muscleVoltageServiceUUID,"00B3");

write(muscleOneVoltage, 1);