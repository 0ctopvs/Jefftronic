# Mis proyectos de código para pasar el rato.

¡Saludos! En este repositorio comparto algunos proyectos de código que he creado en mi tiempo libre. Mi intención es que puedan ser útiles para otros entusiastas y desarrolladores. ¡Cualquier feedback es bienvenido!

## Contenido del Repositorio:

### 1. Control IR Personalizado RM-SCEX1 para M5StickC PLUS2 / ESP32
<img src="https://github.com/0ctopvs/Jefftronic/blob/main/IR%20Controller%20RM-SCEX1%20-%20M5StickC%20PLUS2%20ESP3/image.png?raw=true" width="200">
Este proyecto consiste en un control remoto infrarrojo diseñado principalmente para el M5StickC PLUS2, aunque puede adaptarse a otras placas ESP32 que cuenten con una pantalla. La interfaz visual en la pantalla del ESP32 permite explorar las diferentes funciones del control y ejecutar el envío de la señal IR correspondiente.

**¿Por qué este proyecto?** La motivación principal surgió de la dificultad para encontrar y el elevado costo del control remoto original RM-SCEX1 para ciertos equipos de sonido SONY. Esta solución permite utilizar códigos LIRC disponibles en línea para emular sus funciones.

**Instrucciones de Uso:**

* **Navegación:** Los botones laterales te permiten moverte a través de las opciones mostradas en la pantalla.
* **Envío de Señal:** Para enviar la señal IR de la opción seleccionada, simplemente presiona el botón central.
* **Apagar:** Mantén pulsado el botón de apagado durante 4 segundos. Notarás que la pantalla sigue navegando, pero el dispositivo se apagará al completar el ciclo.
* **Encender:** Para encender el dispositivo, mantén presionado el botón de encendido durante 3 segundos.
* **Requisitos de Hardware:** Este proyecto aprovecha el transmisor de infrarrojos integrado en el M5StickC PLUS2, por lo que no necesitas añadir ningún módulo adicional.

¡Espero que lo encuentres útil!

