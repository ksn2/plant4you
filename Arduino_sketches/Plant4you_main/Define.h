//---------color definition--------------------//
#define RED      0
#define GREEN    1
#define BLUE     2
#define YELLOW   3
#define PURPLE   4
#define AQUA     5
#define DIMMING  10

//------CHANNEL definition--------//
#define CHANNEL1 0
#define CHANNEL2 1
#define CHANNEL3 2
#define CHANNEL4 3

//------RGB 1 LED PIN--------//
#define redPin1     11
#define greenPin1   10
#define bluePin1    9

//------RGB 2 LED PIN--------//
#define redPin2     11
#define greenPin2   10
#define bluePin2    9

//------Moisture Sensors PIN--------//
#define moisturePin_channel1  A1
#define moisturePin_channel2  A2
#define moisturePin_channel3  A3
#define moisturePin_channel4  A4

//------Potentiometer PIN--------//
#define pot_channel1  1
#define pot_channel2  2
#define pot_channel3  3
#define pot_channel4  4

//---------Motor PIN--------------------//
#define motorPin_channel1  0
#define motorPin_channel2  0
#define motorPin_channel3  0
#define motorPin_channel4  0

//---------Level sensor PIN--------------------//
#define level_sensorPin    5

//---------photocell PIN--------------------//
#define photocellPin       A0

//---------Control of 3.3V PIN--------------------//
#define voltage_ctrlPin     0

//---------Battery voltage PIN--------------------//
#define batteryVoltagePin     5
//---------Alarms PIN--------------------//
#define PIRPin             6
#define BuzzerPin          0

//-----------Sensors constant parameters----------//
#define max_V               168
#define purple_idx          52
#define Photocell_Value_Min           20
#define Photocell_Value_Max           900
#define Pot_Value_Min               0
#define Pot_Value_Max               500
#define Moisture_Value_Min          0
#define Moisture_Value_Max          500
#define Battery_Voltage_Min          0
#define Battery_Voltage_Max          1023
