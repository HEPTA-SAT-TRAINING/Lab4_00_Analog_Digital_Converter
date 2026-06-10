#include "src/HeptaSat.h"

HeptaCdh    cdh;
HeptaEps    eps;
HeptaSensor sensor;

void setup() {
  cdh.begin();
  eps.init();
  sensor.begin();
}

void loop() {
  float v5    = eps.get_5v_voltage();
  float v3v3  = eps.get_3v3_voltage();
  float i_dis = eps.get_current_discharge();
  float i_chg = eps.get_current_charge();
  float v_sap = eps.get_sap_voltage();

  cdh.printf("5V Voltage: %.2f [V]\r\n", v5);
  cdh.printf("3V3 Voltage: %.2f [V]\r\n", v3v3);
  cdh.printf("Discharge Current: %.2f [A]\r\n", i_dis);
  cdh.printf("Charge Current: %.2f [A]\r\n", i_chg);
  cdh.printf("SAP Voltage: %.2f [V]\r\n", v_sap);

  delay(1000);
}
