// Inclusión de las bibliotecas necesarias

//Importaciones Importantes NO BORRAR
#include "wifi_manager.h"
#include "update_manager.h"

//Modifica la version por 1.0 o 1.1, siempre que sea diferente a la versión anterior
#define FIRMWARE_VERSION 1.0
#define UPDATE_URL "https://cloudidespacetechnologies.github.io/C/esp32_c_2.json"

extern const double firmwareVersion = FIRMWARE_VERSION;
extern const char* updateUrl = UPDATE_URL;

// Variable para manejar la tarea que hace parpadear el LED
TaskHandle_t task0;
// Variable para rastrear si la tarea de parpadeo está en ejecución
bool isBlinkingTaskRunning = false;

//Define los pines a Utilizar
// #define LED_PIN 21
#define LED_PIN 18

//Setup Se utiliza para realizar la configuración inicial de pines, periféricos y otros componentes.
void setup()
{ 
  //No cambiar la salida de monitor speed
  Serial.begin(115200);

  //Aqui puedes Iniciar los pines y establecer algunos otros parámetros
  pinMode(19, OUTPUT);
  digitalWrite(19, LOW);
  
  // Configura el GPIO para la versión actual
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);
  
  connectWifi();
  xTaskCreatePinnedToCore(NameTask, "separateTasks", 10000, NULL, 1, &task0, 0);
}

//No Agregar código en el Loop para un mejor manejo del código esta la función NameTask 
void loop()
{
  // Verificar si hay actualizaciones disponibles
  checkUpdate();
  delay(30000); // Espera 30 SEGUNDOS antes de volver a verificar
}

//Escribe la lógica deseada dentro de esta función dentro del while 
void NameTask(void *pvParameters)
{
  Serial.println("Blinking task started."); // Mensaje al inicio de la tarea
  isBlinkingTaskRunning = true;

  while (1)
  {
    //Lugar para Escribir la Lógica
    digitalWrite(LED_PIN, HIGH);
    delay(500);
    digitalWrite(LED_PIN, LOW);
    delay(500);
  }

  // En teoría, el código nunca debería llegar a este punto debido al bucle infinito anterior.
  Serial.println("Blinking task ended."); // Mensaje al final de la tarea (aunque nunca debería llegar aquí)
  isBlinkingTaskRunning = false;
}
