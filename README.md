# Blynkprojectwithalarm

This is my arduino project with Blynk!


![ezgif-2-652381db83](https://user-images.githubusercontent.com/99627401/160848793-5c4abe10-04b5-4c75-8053-cc61d5c43fb8.gif)
![Screenshot_1](https://user-images.githubusercontent.com/99627401/160846752-8657fe61-de0e-4449-90c9-efc8db58b47a.png)

De opbouw is vrij simpel, een led verbonden aan een Digital Output, een buzzer en een led verbonden aan een andere Digital Output en als laatste een Oled scherm verbonden met I2C

--------------------------------------------------------------------------------------------------------------------------------------------------------------
Eerst het definen van de info gekregen van Blynk zelf
![image](https://user-images.githubusercontent.com/99627401/160847973-ebb487d8-b0d9-4074-b9a3-6315573e886e.png)

Daarna kunnen we alle libraries toevoegen (Je kunt ze ofwel vinden in libraryzoekbalk van arduino of op github)
![image](https://user-images.githubusercontent.com/99627401/160849046-6aaea553-8803-47b0-badc-ee2cf006df0b.png)

De scherm initialiseren
![image](https://user-images.githubusercontent.com/99627401/160849151-be92609a-0dbd-448f-b4db-9c4660defce6.png)

Wifi en auth declareren

![image](https://user-images.githubusercontent.com/99627401/160849338-e4601cb5-9a52-4b7b-b5a4-f8cd23a551ea.png)

Ik heb hier pinnen gedefined voor mijn sensor en mijn actuators

![image](https://user-images.githubusercontent.com/99627401/160849481-349792eb-021b-42c0-820d-1257dd03c73c.png)

Variabelen aanmaken om met waardes te kunnen spelen

![image](https://user-images.githubusercontent.com/99627401/160849757-adeacdb7-b3ea-453c-b3ae-2637ed3c6754.png)

Hier beginnen we met een functie die mijn dhtsensor leest en waardes doorstuurt naar mijn gsm (Het stuurt ook de status van mijn led en alarm)

![image](https://user-images.githubusercontent.com/99627401/160850008-b5b3d495-ff67-4401-8aab-5a130cdcdd6e.png)

Hier zijn mijn 2 functies die de waarde van mijn gsm lezen zowal de terminal als een String en mijn knop als een Integer

![image](https://user-images.githubusercontent.com/99627401/160850301-65d61b14-3c7e-4f31-bb4a-b5c5c3396950.png)


Ik heb hier ook een timer toegevoegd die de tijd aanduid dat is verlopen sinds dat met programma begonnen is

![image](https://user-images.githubusercontent.com/99627401/160850566-d59ebda6-ef64-4916-9ec3-c8b399993a4e.png)

Alles laten beginnen en testen als mijn Oled juist aangesloten is

![image](https://user-images.githubusercontent.com/99627401/160850713-2369597b-41f0-4c62-8b54-14f7c2fbf9c8.png)

Mijn functies laten runnen met een tijdsinterval (mag niet lager dan 10ms)

![image](https://user-images.githubusercontent.com/99627401/160850858-e4c218d6-f1a1-49b6-8841-c1939018e26b.png)

Mijn temp, hum en de gelezen String printen op mijn oledscherm

![image](https://user-images.githubusercontent.com/99627401/160851012-9a028429-cbed-46f3-a5e5-02d0aad0ea28.png)

Als het bericht dat ik heb verstuurd gelijk is aan O gaat mijn geel led aan en bij N gaat ze uit

![image](https://user-images.githubusercontent.com/99627401/160851170-80d25f92-9d33-403a-924f-a63d087acdc2.png)

Als mijn temp hoger of gelijk is aan 28 gaat de buzzer en de led aan behalve als ik de stop schakelaar aanzet vanuit mijn gsm

![image](https://user-images.githubusercontent.com/99627401/160851451-c4f72f4d-fa09-4d4d-aaf7-b806cfc5b356.png)

Als de temp lager is dan 27 gaat de buzzer uit en natuurlijk nog de display.display om de scherm te laten werken

![image](https://user-images.githubusercontent.com/99627401/160851478-d6469f8f-5810-48b5-8688-5050f69ab704.png)









