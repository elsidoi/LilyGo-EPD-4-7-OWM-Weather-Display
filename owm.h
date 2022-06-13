#include <Arduino.h>            // In-built
#include "WiFi.h"
#include "forecast_record.h"


class OWM {       // The class
  public:             // Access specifier
    OWM();

    static const int max_readings  = 24; // Limited to 3-days here, but could go to 5-days = 40


    Forecast_record_type  WxConditions[1];
    Forecast_record_type  WxForecast[max_readings];

    
    bool getWeatherData();

private:
    WiFiClient wifi_client;   // wifi client object

    bool obtainWeatherData(const String & RequestType);
    bool DecodeWeather(WiFiClient& json, String Type);
    void Convert_Readings_to_Imperial();
    void Convert_Pressure_to_mm();
};