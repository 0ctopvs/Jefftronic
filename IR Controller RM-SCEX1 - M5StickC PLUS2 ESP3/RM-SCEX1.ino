#include <M5StickCPlus2.h>
#include <IRremote.hpp>

#define IR_TX_PIN 19

const char* opciones[] = {
"Sleep", "Select", "Set", "Display", "Enter", "Play CD", "Tuner/Band", "Tuning mode", "Stereo/Mono", "Memory", "Pause CD", "Stop CD", "- Bass", "+ Bass", "- Trebel", "+ Trebel", "SBack", "SForward", "+ Volume", "- Volume", "Prev", "Next", "Forward", "DSG", "Play mode", "Repeat", "Open/Close", "On/Off", "Function", "Surround"
};

int opcionSeleccionada = 0;

void setup() {
  auto cfg = M5.config();
  StickCP2.begin(cfg);
  M5.Lcd.setRotation(1);
  M5.Lcd.fillScreen(BLACK);
  
  IrSender.setSendPin(IR_TX_PIN);
  
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(0, 0);
  mostrarMenuPrincipal();

  pinMode(37, INPUT_PULLUP); // Botón A
  pinMode(39, INPUT_PULLUP); // Botón B
  pinMode(0, INPUT_PULLUP);  // Botón C
}

void loop() {
  M5.update();
  M5.Lcd.wakeup(); // Despierta la pantalla en cada ciclo

  bool buttonAPressed = (digitalRead(37) == LOW);
  bool buttonBPressed = (digitalRead(35) == LOW);
  bool buttonCPressed = (digitalRead(39) == LOW);

  static unsigned long buttonBPressStartTime = 0;
  static unsigned long buttonCPressStartTime = 0;

  // Menú Principal
  if (buttonBPressed && (millis() - buttonBPressStartTime > 250)) {
    opcionSeleccionada = (opcionSeleccionada + 1) % 30; // Cambiar el número de opciones a 36
    mostrarMenuPrincipal();
    buttonBPressStartTime = millis();
    delay(50);
  }

  if (buttonCPressed && (millis() - buttonCPressStartTime > 250)) {
    opcionSeleccionada = (opcionSeleccionada > 0) ? (opcionSeleccionada - 1) : (29); // Cambiar el número de opciones a 36
    mostrarMenuPrincipal();
    buttonCPressStartTime = millis();
    delay(50);
  }

  if (buttonAPressed) {
    enviarOpcion(opcionSeleccionada);
    delay(300);
  }
}

void mostrarMenuPrincipal() {
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextSize(2);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(10, 10);  // Fija el texto "Jefftron:RM-SCEX1" en la parte superior
  M5.Lcd.printf("Jefftron:RM-SCEX1");

  int numOpciones = sizeof(opciones) / sizeof(opciones[0]);
  int opcionesVisibles = 5; // Mostrar 5 opciones a la vez para un mejor espaciado
  int inicio = opcionSeleccionada - (opcionesVisibles / 2);
  if (inicio < 0) inicio = 0;
  if (inicio > numOpciones - opcionesVisibles) inicio = numOpciones - opcionesVisibles;

  for (int i = 0; i < opcionesVisibles; i++) {
    int indiceOpcion = inicio + i;
    if (indiceOpcion >= 0 && indiceOpcion < numOpciones) {
      if (indiceOpcion == opcionSeleccionada) {
        M5.Lcd.setTextColor(WHITE, BLUE);
      } else {
        M5.Lcd.setTextColor(WHITE);
      }
      M5.Lcd.setCursor(10, 30 + (i * 20)); // Espaciado vertical de 20 píxeles
      M5.Lcd.println(opciones[indiceOpcion]);
    }
  }
}

void enviarOpcion(int opcion) {
  M5.Lcd.setBrightness(255); // Asegúrate de que el brillo esté al máximo
  M5.Lcd.fillScreen(BLACK);
  M5.Lcd.setTextColor(WHITE);
  M5.Lcd.setCursor(10, 30);
  M5.Lcd.printf("Enviando opcion: %s", opciones[opcion]);

  // Deshabilitar las interrupciones temporalmente
  noInterrupts();

  // Asegúrate de que la pantalla esté activa antes de enviar el IR
  M5.Lcd.wakeup();  // Reactivamos la pantalla antes de enviar la señal IR
  delay(50);  // Tiempo de estabilización de la pantalla antes de enviar la señal

  // Enviar la señal IR
  // Enviar la señal IR
  switch (opcion) {
    case 0: { 
    const static uint16_t data[] = {2452, 550, 617, 577, 618, 573, 624, 573, 619, 574, 620, 575, 1217, 572, 1219, 572, 619, 574, 617, 573, 640, 554, 622, 572, 1217};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // sleep

  case 1: { 
    const static uint16_t data[] = {2458, 547, 622, 571, 1217, 573, 637, 556, 620, 574, 619, 574, 1217, 574, 1220, 573, 645, 547, 621, 574, 619, 573, 620, 574, 1217};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // select

  case 2: { 
    const static uint16_t data[] = {2456, 552, 1238, 551, 645, 549, 1241, 549, 670, 523, 671, 522, 1242, 549, 1246, 545, 645, 548, 644, 549, 645, 548, 644, 550, 1262};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // set

  case 3: { 
    const static uint16_t data[] = {2432, 573, 1242, 547, 1219, 572, 618, 577, 1217, 574, 643, 548, 621, 573, 1217, 573, 620, 574, 618, 574, 619, 574, 620, 574, 1214};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // display

  case 4: { 
    const static uint16_t data[] = {2496, 465, 676, 501, 655, 514, 1259, 503, 1259, 507, 658, 511, 646, 523, 649, 516, 649, 519, 1255, 508, 655, 515, 1253, 514, 1257, 504, 1257, 503, 655, 513, 653, 517, 1257, 510, 1254, 511, 1254, 504, 656, 517, 649};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Enter(On/Off)

  case 5: { 
    const static uint16_t data[] = {2493, 456, 665, 504, 1259, 499, 658, 513, 649, 515, 1258, 500, 1262, 501, 659, 508, 1258, 502, 659, 513, 658, 511, 652, 513, 1255};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // CD

  case 6: { 
    const static uint16_t data[] = {2496, 460, 1271, 498, 1263, 499, 1258, 506, 1259, 505, 650, 517, 654, 515, 652, 520, 1254, 508, 654, 514, 1255, 514, 1253, 506, 658};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Tuner/Band

  case 7: { 
    const static uint16_t data[] = {2432, 575, 1217, 572, 1217, 573, 1218, 573, 644, 549, 1217, 573, 619, 578, 617, 573, 1241, 550, 645, 548, 1216, 573, 1218, 572, 620};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // mode

  case 8: { 
    const static uint16_t data[] = {2429, 577, 1216, 573, 620, 574, 620, 573, 644, 549, 620, 573, 1218, 573, 645, 549, 1215, 573, 645, 550, 1241, 548, 1216, 574, 619};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // stereo/mono

  case 9: { 
    const static uint16_t data[] = {2455, 549, 644, 549, 1242, 548, 1254, 535, 1241, 549, 645, 548, 644, 549, 646, 547, 1242, 549, 645, 548, 1266, 525, 1264, 525, 670};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // memory

  case 10: { 
    const static uint16_t data[] = {2406, 570, 1217, 575, 645, 548, 623, 570, 1216, 572, 1217, 575, 1215, 575, 619, 572, 623, 570, 1217, 576, 622, 570, 1217, 573, 1216, 574, 1216, 573, 619, 575, 619, 572, 1244, 548, 1218, 571, 1221, 569, 620, 573, 619};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // cd_pause

  case 11: { 
    const static uint16_t data[] = {2457, 550, 645, 549, 665, 528, 644, 549, 1238, 551, 1241, 549, 1242, 549, 644, 548, 646, 548, 1241, 549, 644, 551, 1239, 550, 1241, 548, 1268, 522, 645, 549, 646, 547, 1241, 550, 1240, 550, 1242, 548, 645, 548, 662};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // cd_stop

  case 12: { 
    const static uint16_t data[] = {2434, 574, 1216, 573, 1217, 573, 1216, 574, 646, 548, 1216, 573, 1216, 576, 618, 574, 620, 573, 620, 574, 1216, 574, 1217, 573, 619};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // bass-

  case 13: { 
    const static uint16_t data[] = {2429, 573, 621, 572, 1217, 574, 1216, 573, 639, 555, 1214, 574, 1242, 548, 621, 573, 620, 573, 645, 549, 1216, 573, 1241, 550, 618};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // bass+

  case 14: { 
    const static uint16_t data[] = {2457, 550, 1239, 548, 646, 547, 1269, 523, 642, 553, 1240, 547, 1270, 523, 643, 548, 670, 523, 645, 551, 1241, 547, 1267, 525, 645};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // treble-

  case 15: { 
    const static uint16_t data[] = {2431, 575, 645, 548, 620, 573, 1217, 573, 621, 574, 1215, 574, 1216, 576, 618, 573, 618, 575, 621, 573, 1217, 573, 1215, 574, 621};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // treble+

  case 16: { 
    const static uint16_t data[] = {2407, 574, 1217, 573, 1216, 574, 619, 574, 620, 574, 1215, 574, 1216, 574, 619, 574, 620, 573, 1240, 550, 619, 574, 1241, 549, 1218, 572, 1216, 574, 619, 574, 621, 571, 1218, 573, 1217, 574, 1215, 574, 620, 574, 620};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // seek_back

  case 17: { 
    const static uint16_t data[] = {2481, 525, 670, 523, 644, 549, 1242, 548, 671, 523, 1241, 548, 1242, 548, 645, 549, 645, 548, 1266, 524, 645, 548, 1270, 538, 1229, 618, 1222, 526, 620, 610, 630, 494, 1258, 794, 991, 600, 1274, 511, 600, 593, 599};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // seek_forward

  case 18: { 
    const static uint16_t data[] = {2454, 550, 643, 550, 1216, 572, 647, 548, 620, 573, 1217, 573, 647, 546, 646, 548, 620, 573, 620, 574, 619, 577, 620, 571, 1216};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // vol+

   case 19: { 
    const static uint16_t data[] = {2492, 478, 1271, 510, 1268, 506, 672, 517, 668, 514, 1272, 510, 672, 519, 667, 514, 672, 515, 668, 519, 671, 516, 672, 516, 1268};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // vol-

 case 20: { 
    const static uint16_t data[] = {2432, 548, 648, 548, 643, 550, 644, 549, 645, 549, 1265, 524, 1267, 523, 645, 549, 645, 550, 1265, 524, 668, 524, 1264, 526, 1242, 548, 1241, 549, 668, 526, 644, 549, 1241, 550, 1240, 550, 1265, 525, 645, 548, 645};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // previous

case 21: { 
    const static uint16_t data[] = {2453, 550, 1215, 575, 619, 574, 645, 548, 621, 573, 1216, 572, 1218, 574, 619, 574, 620, 574, 1216, 574, 619, 574, 1217, 573, 1217, 575, 1239, 549, 620, 573, 620, 574, 1216, 574, 1217, 573, 1216, 572, 621, 574, 620};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // next


case 22: { 
    const static uint16_t data[] = {2504, 454, 681, 495, 667, 503, 1265, 499, 663, 506, 1263, 500, 1266, 501, 665, 508, 658, 504, 1259, 502, 659, 506, 1258, 505, 1268, 496, 1269, 496, 669, 498, 657, 516, 1258, 502, 1264, 499, 1268, 497, 664, 504, 661};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Forward

case 23: { 
    const static uint16_t data[] = {2431, 575, 1215, 575, 619, 574, 619, 574, 619, 575, 1216, 574, 1216, 575, 618, 574, 619, 575, 619, 574, 1216, 575, 1241, 548, 619};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // DSG

case 24: { 
    const static uint16_t data[] = {2432, 549, 646, 547, 644, 550, 1241, 549, 1247, 541, 670, 525, 1242, 550, 1242, 546, 1242, 549, 643, 550, 643, 550, 645, 549, 1239};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Playmode

case 25: { 
    const static uint16_t data[] = {2432, 574, 620, 573, 620, 573, 1221, 569, 1241, 549, 645, 548, 1216, 574, 620, 573, 1216, 573, 647, 548, 620, 573, 620, 574, 1217};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Repeat

case 26: { 
    const static uint16_t data[] = {2492, 459, 669, 501, 1265, 501, 1261, 499, 663, 502, 1263, 503, 652, 518, 653, 513, 1258, 501, 662, 507, 655, 505, 657, 517, 1254};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Open/Close

case 27: { 
    const static uint16_t data[] = {2493, 459, 1274, 497, 664, 503, 1258, 507, 662, 502, 1260, 504, 659, 511, 657, 514, 652, 520, 645, 522, 653, 514, 650, 520, 1254};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // PowerOn/Off


case 28: { 
    const static uint16_t data[] = {2375, 624, 1148, 632, 551, 628, 551, 631, 1147, 634, 548, 631, 1149, 632, 1150, 632, 550, 629, 551, 631, 1149, 631, 1148, 611, 551};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Fuction


case 29: { 
    const static uint16_t data[] = {2527, 445, 1298, 472, 1298, 471, 1296, 474, 1294, 477, 1294, 471, 1296, 472, 696, 483, 680, 488, 682, 486, 1290, 476, 1292, 478, 693};
    IrSender.sendRaw(data, sizeof(data) / sizeof(data[0]), 38); 
    break; 
  } // Surround

   }
  // Rehabilitamos las interrupciones después del envío de la señal IR
  interrupts();
  mostrarMenuPrincipal();


}















