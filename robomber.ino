#include <EEPROM.h> //incluir libreria

const int FUEGO = 0;
const int HUMO = 1;
int obtenerEstado(int posicion, int tipo){
  int pos = (posicion*2)+ tipo;
  int respuesta = EEPROM.read (pos);
  return respuesta;
}
void definirEstado(int posicion, int tipo, int valor){
  int pos = (posicion*2)+ tipo;
  EEPROM.write (pos, valor);
}
int obtenerHumo (){
  int valorHumo = analogRead(A0);
 float sensor_volt;
  float RS_gas; // Get value of RS in a GAS
  sensor_volt=(float)valorHumo/1024*5.0;
  RS_gas = (5.0-sensor_volt)/sensor_volt;
  RS_gas = RS_gas*100;
return RS_gas;
}

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
}

void loop() {
  
int valorFuego = digitalRead(3);
int valorHumo = obtenerHumo();
 
 definirEstado(0, FUEGO,valorFuego); //estado del cuadrante 0
 definirEstado(0,HUMO,valorHumo);
 Serial.print( "valor de fuego: ");
 Serial.println( obtenerEstado(0, FUEGO));
 Serial.print("valor de Humo: ");
 Serial.println( obtenerEstado(0,HUMO));
 
 
}
