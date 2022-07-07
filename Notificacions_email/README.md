# Notificacions per correu electrònic

Aquest projecte permet enviar dades per correu electrònic des de l'ESP8266.
L'exemple envia una notificació per correu electrònic cada minut.
El projecte requereix un compte d'[IFTTT](https://ifttt.com).

## Creació de l'applet
1. Cliquem a "Create"
2. A l'opció "If this" afegim "WebHooks"
3. Seleccionem l'opció "Receive a web request"
4. Posem un nom a l'esdeveniment (Event Name) que també caldrà introduir al codi
5. A l'opció "Then that" afegim "Email" i l'opció "Send me an email"
6. Personalitzem el títol i el cos del correu electrònic
7. Continuem i finalitzem l'applet
8. A l'opció "Maker webhooks" i "Documentation" trobarem la clau API per enviar les dades

Per comprovar el funcionament de l'applet podem escriure a la barra del navegador: 

[https://maker.ifttt.com/trigger/{Event Name}/with/key/{API KEY}?value1={valor}](https://maker.ifttt.com/trigger/)

## Referències
* [https://randomnerdtutorials.com/door-status-monitor-using-the-esp8266/](https://randomnerdtutorials.com/door-status-monitor-using-the-esp8266/)
