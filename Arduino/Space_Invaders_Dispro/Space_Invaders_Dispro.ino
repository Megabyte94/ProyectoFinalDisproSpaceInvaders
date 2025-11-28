/*
 * Space Invaders DISPRO - Versión Arduino TFT
 * Adaptación FIEL de Mockups/main.c
 * 
 * Los sprites Unicode del original se convierten a bitmaps 2x4 píxeles
 * por cada carácter Unicode (cada char braille/block = 2x4 píxeles)
 * 
 * Pantalla: TFT ILI9341 240x320 (Portrait)
 * Hardware: Arduino Mega 2560 + Joystick Shield v1.A
 * 
 * FUENTES CONSULTADAS: Natalia Ospina, Juan Sebastián Arcila, monitorías dispro, ChatGPT, Claude
 */

#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>

// ==================== HARDWARE ====================
#define TFT_CS   40
#define TFT_DC   38
#define TFT_RST  36

#define JOY_X    A0
#define JOY_Y    A1
#define BTN_A    2
#define BTN_C    4
#define BTN_D    5
#define BUZZER   12

Adafruit_ILI9341 tft = Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

// ==================== ESCALA ====================
#define SPRITE_W 16
#define SPRITE_H 20

// ==================== CONFIGURACIÓN JUEGO ====================
#define SCREEN_W 320
#define SCREEN_H 240
#define VISIBLE_W 240
#define VISIBLE_H 320

#define ROWS 3
#define ALIENS_PER_ROW 9
#define TOTAL_ALIENS (ROWS * ALIENS_PER_ROW)

#define MAX_ALIEN_BULLETS 12
#define MAX_PLAYER_BULLETS 20
#define MAX_HEARTS 3

#define COLOR_BG      0x0000
#define COLOR_YELLOW  0xFFE0
#define COLOR_RED     0xF800
#define COLOR_GREEN   0x07E0
#define COLOR_OLIVE   0xC600
#define COLOR_PURPLE  0x8010
#define COLOR_CYAN    0x07FF
#define COLOR_WHITE   0xFFFF
#define COLOR_NEON    0x07E0

// ==================== ESTRUCTURAS ====================
struct Alien {
  int x, y;
  int type;
};

struct AlienBullet {
  int x, y;
  int active;
  int ownerCol;
};

struct PlayerBullet {
  int x, y;
  int active;
};

struct Player {
  int x, y;
};

// ==================== VARIABLES GLOBALES ====================
Alien aliens[TOTAL_ALIENS];
AlienBullet alienBullets[MAX_ALIEN_BULLETS];
PlayerBullet playerBullets[MAX_PLAYER_BULLETS];
Player player;

int playerScore = 0;
int hiScore = 0;
int playerLives = MAX_HEARTS;
int direction = 1;
int frameToggle = 0;

unsigned long lastAlienMove = 0;
unsigned long lastAlienShot = 0;
unsigned long lastPlayerShot = 0;
unsigned long lastInput = 0;

bool gameOver = false;
bool gameStarted = false;

// ==================== SPRITES EN BITMAP ====================
const uint8_t alien1A[20][2] PROGMEM = {
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b01111001, 0b10011110},
  {0b01111001, 0b10011110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b00110001, 0b10001100},
  {0b00110001, 0b10001100},
  {0b01100000, 0b00000110},
  {0b01100000, 0b00000110},
  {0b11000110, 0b01100011},
  {0b11000110, 0b01100011},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t alien1B[20][2] PROGMEM = {
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b01111001, 0b10011110},
  {0b01111001, 0b10011110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00011000, 0b00011000},
  {0b00011000, 0b00011000},
  {0b00110011, 0b11001100},
  {0b00110011, 0b11001100},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t alien2A[20][2] PROGMEM = {
  {0b01100000, 0b00000110},
  {0b01100000, 0b00000110},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b01111001, 0b10011110},
  {0b01111001, 0b10011110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11100111, 0b11100111},
  {0b11100111, 0b11100111},
  {0b11000000, 0b00000011},
  {0b11000000, 0b00000011},
  {0b01100000, 0b00000110},
  {0b01100000, 0b00000110},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t alien2B[20][2] PROGMEM = {
  {0b01100000, 0b00000110},
  {0b01100000, 0b00000110},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b01111001, 0b10011110},
  {0b01111001, 0b10011110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11100111, 0b11100111},
  {0b11100111, 0b11100111},
  {0b11110000, 0b00001111},
  {0b11110000, 0b00001111},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t alien3A[20][2] PROGMEM = {
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b11110011, 0b11001111},
  {0b11110011, 0b11001111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b00111100, 0b00111100},
  {0b00111100, 0b00111100},
  {0b01100011, 0b11000110},
  {0b01100011, 0b11000110},
  {0b11000110, 0b01100011},
  {0b11000110, 0b01100011},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t alien3B[20][2] PROGMEM = {
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b11110011, 0b11001111},
  {0b11110011, 0b11001111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00110011, 0b11001100},
  {0b00110011, 0b11001100},
  {0b01100110, 0b01100110},
  {0b01100110, 0b01100110},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t playerSpr[20][2] PROGMEM = {
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b01100111, 0b11100110},
  {0b01100111, 0b11100110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11110111, 0b11101111},
  {0b11110111, 0b11101111},
  {0b00110111, 0b11101100},
  {0b00110111, 0b11101100},
  {0b00110000, 0b00001100},
  {0b00110000, 0b00001100},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t bulletPlayer[20][2] PROGMEM = {
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b01111111, 0b11111110},
  {0b01111111, 0b11111110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b01111111, 0b11111110},
  {0b01111111, 0b11111110},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t bulletAlien[20][2] PROGMEM = {
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b01111111, 0b11111110},
  {0b01111111, 0b11111110},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b01111111, 0b11111110},
  {0b01111111, 0b11111110},
  {0b00111110, 0b01111100},
  {0b00111110, 0b01111100},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t kaboom[20][2] PROGMEM = {
  {0b01100110, 0b01100110},
  {0b01100110, 0b01100110},
  {0b00110000, 0b00001100},
  {0b00110000, 0b00001100},
  {0b01100000, 0b00000110},
  {0b01100000, 0b00000110},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00110000, 0b00001100},
  {0b00110000, 0b00001100},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00110000, 0b00001100},
  {0b00110000, 0b00001100},
  {0b01100110, 0b01100110},
  {0b01100110, 0b01100110},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

const uint8_t heart[20][2] PROGMEM = {
  {0b11110011, 0b11111100},
  {0b11110011, 0b11111100},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b11111111, 0b11111111},
  {0b01111111, 0b11111110},
  {0b01111111, 0b11111110},
  {0b00111111, 0b11111100},
  {0b00111111, 0b11111100},
  {0b00011111, 0b11111000},
  {0b00011111, 0b11111000},
  {0b00001111, 0b11110000},
  {0b00001111, 0b11110000},
  {0b00000111, 0b11100000},
  {0b00000111, 0b11100000},
  {0b00000000, 0b00000000},
  {0b00000000, 0b00000000}
};

// ==================== FUNCIONES DE DIBUJO ====================

void drawSprite(int x, int y, const uint8_t sprite[][2], uint16_t color) {
  for(int row = 0; row < 20; row++) {
    uint8_t b0 = pgm_read_byte(&sprite[row][0]);
    uint8_t b1 = pgm_read_byte(&sprite[row][1]);
    uint16_t bits = (b0 << 8) | b1;
    
    for(int col = 0; col < 16; col++) {
      if(bits & (0x8000 >> col)) {
        tft.drawPixel(x + col, y + row, color);
      }
    }
  }
}

void clearSprite(int x, int y, int w, int h) {
  tft.fillRect(x, y, w, h, COLOR_BG);
}

void drawAlien(int idx, bool clear) {
  if(aliens[idx].x < 0) return;
  
  int x = aliens[idx].x;
  int y = aliens[idx].y;
  int type = aliens[idx].type;
  
  if(clear) {
    clearSprite(x - 4, y, 24, 28);
    return;
  }
  
  uint16_t color;
  const uint8_t (*sprA)[2];
  const uint8_t (*sprB)[2];
  
  switch(type) {
    case 0: 
      color = COLOR_RED; 
      sprA = alien1A; sprB = alien1B;
      break;
    case 1: 
      color = COLOR_GREEN; 
      sprA = alien2A; sprB = alien2B;
      break;
    default: 
      color = COLOR_OLIVE; 
      sprA = alien3A; sprB = alien3B;
      break;
  }
  
  drawSprite(x, y, frameToggle ? sprB : sprA, color);
}

void drawPlayer(bool clear) {
  if(clear) {
    clearSprite(player.x - 3, player.y, 22, 20);
  } else {
    drawSprite(player.x, player.y, playerSpr, COLOR_PURPLE);
  }
}

void drawPlayerBullet(int idx, bool clear) {
  if(!playerBullets[idx].active) return;
  int x = playerBullets[idx].x;
  int y = playerBullets[idx].y;
  
  if(clear) {
    tft.fillRect(x, y, 16, 26, COLOR_BG);
  } else {
    drawSprite(x, y, bulletPlayer, COLOR_NEON);
  }
}

void drawAlienBullet(int idx, bool clear) {
  if(!alienBullets[idx].active) return;
  int x = alienBullets[idx].x;
  int y = alienBullets[idx].y;
  
  if(clear) {
    tft.fillRect(x, y - 4, 16, 24, COLOR_BG);
  } else {
    drawSprite(x, y, bulletAlien, COLOR_YELLOW);
  }
}

void drawExplosion(int x, int y) {
  drawSprite(x, y, kaboom, COLOR_RED);
}

void drawHeart(int x, int y) {
  drawSprite(x, y, heart, COLOR_RED);
}

// ==================== UI ====================

void drawScore() {
  tft.fillRect(5, 3, 70, 16, COLOR_BG);
  tft.setTextColor(COLOR_WHITE);
  tft.setTextSize(1);
  tft.setCursor(5, 3);
  tft.print("SCORE");
  tft.setTextColor(COLOR_YELLOW);
  tft.setCursor(5, 12);
  tft.print(playerScore);
}

void drawHiScore() {
  tft.fillRect(85, 3, 70, 16, COLOR_BG);
  tft.setTextColor(COLOR_WHITE);
  tft.setTextSize(1);
  tft.setCursor(90, 3);
  tft.print("HI-SCORE");
  tft.setTextColor(COLOR_CYAN);
  tft.setCursor(95, 12);
  tft.print(hiScore);
}

void drawLives() {
  tft.fillRect(VISIBLE_W - 50, 2, 48, 20, COLOR_BG);
  
  for(int i = 0; i < playerLives; i++) {
    int hx = VISIBLE_W - 48 + (i * 15);
    tft.fillCircle(hx + 3, 8, 4, COLOR_RED);
    tft.fillCircle(hx + 9, 8, 4, COLOR_RED);
    tft.fillTriangle(hx, 10, hx + 12, 10, hx + 6, 18, COLOR_RED);
  }
}

void drawFrame() {
  tft.drawRect(0, 25, VISIBLE_W, SCREEN_H - 25, COLOR_WHITE);
}

// ==================== INICIALIZACIÓN ====================

void initGame() {
  gameOver = false;
  gameStarted = true;
  playerScore = 0;
  playerLives = MAX_HEARTS;
  direction = 1;
  frameToggle = 0;
  
  tft.fillScreen(COLOR_BG);
  tft.fillRect(0, 0, 320, 320, COLOR_BG);
  delay(50);
  
  drawFrame();
  drawScore();
  drawHiScore();
  drawLives();
  
  int spacing = 8;
  int startX = 16;
  int startY = 35;
  int width = 16;
  int height = 20;
  
  int index = 0;
  for(int r = 0; r < ROWS; r++) {
    for(int i = 0; i < ALIENS_PER_ROW; i++) {
      aliens[index].x = startX + i * (width + spacing);
      aliens[index].y = startY + r * (height + 8);
      aliens[index].type = r;
      drawAlien(index, false);
      index++;
    }
  }
  
  player.x = (VISIBLE_W - 16) / 2;
  player.y = SCREEN_H - 25;
  drawPlayer(false);
  
  for(int i = 0; i < MAX_PLAYER_BULLETS; i++) playerBullets[i].active = 0;
  for(int i = 0; i < MAX_ALIEN_BULLETS; i++) alienBullets[i].active = 0;
  
  lastAlienMove = millis();
  lastAlienShot = millis();
  lastPlayerShot = millis();
}

// ==================== PANTALLAS ====================

void showStartScreen() {
  tft.fillScreen(COLOR_BG);
  tft.fillRect(0, 0, 320, 320, COLOR_BG);
  delay(50);
  
  tft.setTextColor(COLOR_CYAN);
  tft.setTextSize(3);
  tft.setCursor(30, 60);
  tft.print("SPACE");
  tft.setCursor(10, 95);
  tft.print("INVADERS");
  
  tft.setTextColor(COLOR_YELLOW);
  tft.setTextSize(2);
  tft.setCursor(70, 145);
  tft.print("DISPRO");
  
  tft.setTextColor(COLOR_WHITE);
  tft.setTextSize(1);
  tft.setCursor(30, 200);
  tft.print("Joystick: Mover");
  tft.setCursor(30, 220);
  tft.print("Boton UP: Disparar");
  tft.setCursor(30, 250);
  tft.print("Presiona RIGHT para");
  tft.setCursor(30, 265);
  tft.print("iniciar");
}

void showGameOverScreen() {
  tft.fillScreen(COLOR_BG);
  tft.fillRect(0, 0, 320, 320, COLOR_BG);
  delay(50);
  
  tft.setTextColor(COLOR_RED);
  tft.setTextSize(3);
  tft.setCursor(25, 70);
  tft.print("BAD LUCK");
  
  tft.setTextColor(COLOR_WHITE);
  tft.setTextSize(2);
  tft.setCursor(30, 130);
  tft.print("TRY AGAIN");
  
  tft.setTextColor(COLOR_YELLOW);
  tft.setCursor(30, 180);
  tft.print("SCORE: ");
  tft.print(playerScore);
  
  tft.setTextColor(COLOR_WHITE);
  tft.setTextSize(1);
  tft.setCursor(20, 250);
  tft.print("RIGHT: Reiniciar");
  tft.setCursor(20, 270);
  tft.print("LEFT: Menu");
}

// ==================== LÓGICA DEL JUEGO ====================
int prevAlienX[TOTAL_ALIENS];
int prevAlienY[TOTAL_ALIENS];

void updateAliens() {
  unsigned long now = millis();
  if(now - lastAlienMove < 600) return;
  lastAlienMove = now;
  
  for(int i = 0; i < TOTAL_ALIENS; i++) {
    if(aliens[i].x >= 0) {
      tft.fillRect(aliens[i].x, aliens[i].y, 16, 20, COLOR_BG);
    }
  }
  
  bool touchLeft = false;
  bool touchRight = false;
  bool anyAlive = false;
  
  for(int i = 0; i < TOTAL_ALIENS; i++) {
    if(aliens[i].x >= 0) {
      anyAlive = true;
      int nextX = aliens[i].x + (direction * 4);
      if(nextX <= 2) touchLeft = true;
      if(nextX + 16 >= VISIBLE_W - 2) touchRight = true;
    }
  }
  
  if(!anyAlive) {
    gameOver = true;
    gameStarted = false;
    return;
  }
  
  bool shouldBounce = false;
  if(direction == 1 && touchRight) shouldBounce = true;
  if(direction == -1 && touchLeft) shouldBounce = true;
  
  for(int i = 0; i < TOTAL_ALIENS; i++) {
    if(aliens[i].x >= 0) {
      if(shouldBounce) {
        aliens[i].y += 10;
      } else {
        aliens[i].x += direction * 4;
      }
      
      if(aliens[i].y + 20 >= SCREEN_H - 35) {
        gameOver = true;
        gameStarted = false;
      }
    }
  }
  
  if(shouldBounce) {
    direction = -direction;
  }
  
  frameToggle = !frameToggle;
  
  for(int i = 0; i < TOTAL_ALIENS; i++) {
    if(aliens[i].x >= 0) {
      drawAlien(i, false);
    }
  }
}

void handleInput() {
  int joyX = analogRead(JOY_X);
  bool shoot = !digitalRead(BTN_D);
  
  int oldX = player.x;
  
  if(joyX < 400 && player.x > 5) {
    player.x -= 3;
  } else if(joyX > 600 && player.x < VISIBLE_W - 20) {
    player.x += 3;
  }
  
  if(oldX != player.x) {
    tft.fillRect(oldX, player.y, 16, 20, COLOR_BG);
    drawSprite(player.x, player.y, playerSpr, COLOR_PURPLE);
  }
  
  if(shoot && millis() - lastPlayerShot > 400) {
    for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
      if(!playerBullets[i].active) {
        playerBullets[i].x = player.x + 4;
        playerBullets[i].y = player.y - 20;
        playerBullets[i].active = 1;
        lastPlayerShot = millis();
        tone(BUZZER, 1000, 30);
        break;
      }
    }
  }
}

void updatePlayerBullets() {
  for(int i = 0; i < MAX_PLAYER_BULLETS; i++) {
    if(!playerBullets[i].active) continue;
    
    int oldY = playerBullets[i].y;
    tft.fillRect(playerBullets[i].x + 6, oldY, 4, 20, COLOR_BG);
    
    playerBullets[i].y -= 6;
    
    if(playerBullets[i].y < 30) {
      playerBullets[i].active = 0;
    } else {
      tft.fillRect(playerBullets[i].x + 6, playerBullets[i].y, 4, 12, COLOR_NEON);
    }
  }
}

void updateAlienBullets() {
  for(int i = 0; i < MAX_ALIEN_BULLETS; i++) {
    if(!alienBullets[i].active) continue;
    
    int oldY = alienBullets[i].y;
    tft.fillRect(alienBullets[i].x + 6, oldY, 4, 12, COLOR_BG);
    
    alienBullets[i].y += 4;
    
    if(alienBullets[i].y > SCREEN_H - 5) {
      alienBullets[i].active = 0;
    } else {
      tft.fillRect(alienBullets[i].x + 6, alienBullets[i].y, 4, 8, COLOR_YELLOW);
    }
  }
}

int bottomAlienInCol(int col) {
  for(int r = ROWS - 1; r >= 0; r--) {
    int idx = r * ALIENS_PER_ROW + col;
    if(aliens[idx].x >= 0) return idx;
  }
  return -1;
}

void tryAlienShoot() {
  unsigned long now = millis();
  if(now - lastAlienShot < 1500) return;
  if(random(0, 3) != 0) return;
  
  lastAlienShot = now;
  
  int cols[ALIENS_PER_ROW];
  int count = 0;
  
  for(int c = 0; c < ALIENS_PER_ROW; c++) {
    int idx = bottomAlienInCol(c);
    if(idx == -1) continue;
    
    bool hasActive = false;
    for(int b = 0; b < MAX_ALIEN_BULLETS; b++) {
      if(alienBullets[b].active && alienBullets[b].ownerCol == c) {
        hasActive = true;
        break;
      }
    }
    if(!hasActive) cols[count++] = idx;
  }
  
  if(count == 0) return;
  
  int idx = cols[random(0, count)];
  
  for(int i = 0; i < MAX_ALIEN_BULLETS; i++) {
    if(!alienBullets[i].active) {
      alienBullets[i].x = aliens[idx].x + 4;
      alienBullets[i].y = aliens[idx].y + 20;
      alienBullets[i].active = 1;
      alienBullets[i].ownerCol = idx % ALIENS_PER_ROW;
      tone(BUZZER, 400, 20);
      break;
    }
  }
}

bool checkCollision(int ax, int ay, int aw, int ah, int bx, int by, int bw, int bh) {
  return !(ax + aw < bx || ax > bx + bw || ay + ah < by || ay > by + bh);
}

void checkCollisions() {
  int points[] = {30, 20, 10};
  
  for(int b = 0; b < MAX_PLAYER_BULLETS; b++) {
    if(!playerBullets[b].active) continue;
    
    for(int a = 0; a < TOTAL_ALIENS; a++) {
      if(aliens[a].x < 0) continue;
      
      if(checkCollision(playerBullets[b].x, playerBullets[b].y, 16, 20,
                        aliens[a].x, aliens[a].y, 16, 20)) {
        
        drawPlayerBullet(b, true);
        playerBullets[b].active = 0;
        
        drawAlien(a, true);
        drawExplosion(aliens[a].x, aliens[a].y);
        tone(BUZZER, 200, 80);
        delay(150);
        clearSprite(aliens[a].x, aliens[a].y, 16, 20);
        
        playerScore += points[aliens[a].type];
        if(playerScore > hiScore) {
          hiScore = playerScore;
          drawHiScore();
        }
        drawScore();
        
        aliens[a].x = -100;
        break;
      }
    }
  }
  
  for(int b = 0; b < MAX_ALIEN_BULLETS; b++) {
    if(!alienBullets[b].active) continue;
    
    if(checkCollision(alienBullets[b].x, alienBullets[b].y, 16, 20,
                      player.x, player.y, 16, 20)) {
      
      drawAlienBullet(b, true);
      alienBullets[b].active = 0;
      
      playerLives--;
      drawLives();
      tone(BUZZER, 100, 150);
      
      if(playerLives <= 0) {
        gameOver = true;
        gameStarted = false;
      }
      break;
    }
  }
}

// ==================== SETUP Y LOOP ====================

void setup() {
  Serial.begin(9600);
  
  pinMode(BTN_A, INPUT_PULLUP);
  pinMode(BTN_C, INPUT_PULLUP);
  pinMode(BTN_D, INPUT_PULLUP);
  pinMode(BUZZER, OUTPUT);
  
  tft.begin();
  tft.setRotation(3);
  
  tft.fillScreen(COLOR_BG);
  delay(50);
  tft.fillRect(0, 0, 320, 320, COLOR_BG);
  delay(50);
  tft.fillScreen(COLOR_BG);
  
  showStartScreen();
  
  randomSeed(analogRead(A2));
}

void loop() {
  bool btnRight = !digitalRead(BTN_A);
  bool btnLeft = !digitalRead(BTN_C);
  
  if(!gameStarted && !gameOver) {
    if(btnRight && millis() - lastInput > 300) {
      lastInput = millis();
      initGame();
    }
  } else if(gameOver) {
    static bool shownGameOver = false;
    if(!shownGameOver) {
      showGameOverScreen();
      shownGameOver = true;
    }
    
    if(btnRight && millis() - lastInput > 300) {
      lastInput = millis();
      shownGameOver = false;
      initGame();
    } else if(btnLeft && millis() - lastInput > 300) {
      lastInput = millis();
      shownGameOver = false;
      showStartScreen();
      gameOver = false;
    }
  } else {
    handleInput();
    updateAliens();
    updatePlayerBullets();
    updateAlienBullets();
    tryAlienShoot();
    checkCollisions();
  }
  
  delay(15);
}
