#include "SPI.h"
#include "Adafruit_GFX.h"
#include "Adafruit_ILI9341.h"

// --- 1. CONFIGURACIÓN DE PINES ---

// Pantalla TFT (Pines altos para evitar conflicto con el Shield)
#define TFT_CS   40
#define TFT_DC   38
#define TFT_RST  36
// MOSI -> Pin 51 (Automático por librería)
// SCK  -> Pin 52 (Automático por librería)

// Joystick Shield (Basado en tu imagen Datasheet)
#define JOY_X   A0
#define JOY_Y   A1

// Botones Grandes
#define BTN_A   2  // Derecha (Amarillo)
#define BTN_B   3  // Abajo (Azul)
#define BTN_C   4  // Izquierda (Amarillo)
#define BTN_D   5  // Arriba (Azul)

// Botones Pequeños
#define BTN_E   6  
#define BTN_F   7

// Botón de la Palanca (Click)
#define BTN_K   8

// Buzzer (Zumbador)
#define PIN_BUZZER 12

// Inicializar Pantalla
Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

void setup() {
  Serial.begin(9600);

  // --- CONFIGURACIÓN DE ENTRADAS ---
  // Nota técnica: En estos Shields v1.A, a veces los botones envían HIGH y a veces LOW.
  // Usaremos INPUT_PULLUP por seguridad. Si los botones funcionan al revés 
  // (siempre dicen "pulsado"), cambiaremos esto a INPUT normal.
  
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_B, INPUT_PULLUP);
  pinMode(BTN_C, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);
  pinMode(BTN_E, INPUT_PULLUP);
  pinMode(BTN_F, INPUT_PULLUP);
  pinMode(BTN_K, INPUT_PULLUP); 

  pinMode(PIN_BUZZER, OUTPUT);

  // --- INICIAR PANTALLA ---
  tft.begin();
  tft.setRotation(3); // Horizontal
  tft.fillScreen(ILI9341_BLACK);

  // Título
  tft.setTextColor(ILI9341_WHITE);
  tft.setTextSize(2);
  tft.setCursor(50, 10);
  tft.println("KENNETH HARDWARE");
  tft.setCursor(70, 30);
  tft.setTextSize(1);
  tft.println("Mega 2560 + TFT + Shield v1.A");
  
  // Líneas divisorias
  tft.drawFastHLine(0, 50, 320, ILI9341_WHITE);
  tft.drawFastVLine(160, 50, 190, ILI9341_WHITE);

  // Sonido de bienvenida
  tone(PIN_BUZZER, 1000, 100);
  delay(150);
  tone(PIN_BUZZER, 2000, 100);
}

void loop() {
  // --- 1. LECTURA DE DATOS ---
  
  // Joystick Analógico
  int x = analogRead(JOY_X);
  int y = analogRead(JOY_Y);
  
  // Botones (La lógica !digitalRead invierte el valor porque usamos INPUT_PULLUP)
  // Si al probar no detecta nada, quita el signo de exclamación (!).
  bool bA = !digitalRead(BTN_A);
  bool bB = !digitalRead(BTN_B);
  bool bC = !digitalRead(BTN_C);
  bool bD = !digitalRead(BTN_D);
  bool bE = !digitalRead(BTN_E);
  bool bF = !digitalRead(BTN_F);
  bool bK = !digitalRead(BTN_K);

  // --- 2. MOSTRAR EN PANTALLA (LADO IZQUIERDO: JOYSTICK) ---
  
  // Texto X/Y
  tft.fillRect(10, 70, 140, 40, ILI9341_BLACK); // Limpiar área
  tft.setCursor(10, 70);
  tft.setTextColor(ILI9341_CYAN);
  tft.setTextSize(2);
  tft.print("X: "); tft.println(x);
  tft.setCursor(10, 95);
  tft.print("Y: "); tft.println(y);

  // Dibujar posición (Punto Rojo)
  int mapX = map(x, 0, 1023, 10, 150);
  int mapY = map(y, 0, 1023, 230, 130);
  tft.fillCircle(mapX, mapY, 5, ILI9341_RED);
  delay(20);
  tft.fillCircle(mapX, mapY, 5, ILI9341_BLACK); // Borrar para animar


  // --- 3. MOSTRAR EN PANTALLA (LADO DERECHO: BOTONES) ---
  
  tft.setCursor(170, 60);
  tft.setTextSize(2);
  tft.setTextColor(ILI9341_YELLOW);
  tft.println("BOTONES:");

  // Vamos a listar el estado de cada botón
  tft.setTextSize(1);
  tft.setCursor(170, 90);
  
  // Función auxiliar visual para no repetir código
  imprimirEstadoBoton("BTN A (Pin 2)", bA, 170, 90);
  imprimirEstadoBoton("BTN B (Pin 3)", bB, 170, 110);
  imprimirEstadoBoton("BTN C (Pin 4)", bC, 170, 130);
  imprimirEstadoBoton("BTN D (Pin 5)", bD, 170, 150);
  imprimirEstadoBoton("BTN E (Pin 6)", bE, 170, 170);
  imprimirEstadoBoton("BTN F (Pin 7)", bF, 170, 190);
  imprimirEstadoBoton("BTN K (Stick)", bK, 170, 210);

  // Feedback Sonoro Global (Si cualquiera se presiona)
  if (bA || bB || bC || bD || bE || bF || bK) {
     // Tono muy corto para que no moleste
     tone(PIN_BUZZER, 300, 10); 
  }
}

// Función para imprimir bonito
void imprimirEstadoBoton(String nombre, bool estado, int x, int y) {
  // Borrar estado anterior (un cuadro pequeño a la derecha del texto)
  tft.fillRect(x + 100, y, 40, 10, ILI9341_BLACK); 
  
  tft.setCursor(x, y);
  if (estado) {
    tft.setTextColor(ILI9341_GREEN);
    tft.print(nombre); 
    tft.setCursor(x + 100, y);
    tft.print("ON");
  } else {
    tft.setTextColor(ILI9341_DARKGREY);
    tft.print(nombre);
    tft.setCursor(x + 100, y);
    tft.print("---");
  }
}