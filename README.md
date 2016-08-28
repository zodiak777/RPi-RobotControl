### RPi-RobotControl

In diesem Projekt wird nach und nach eine Kontrollsoftware für den Raspberry Pi in c++ erstellt um damit ein Roboter zu steuern.


### Verwendete Bauteile

Kommen wir erst einmal zu diverse Bauteile die ich für dieses Projekt (bis jetzt) verwende.
 - 1x Zumo Chassis von Pololu (Das ist zwar für einen Arduino ausgelegt, funktioniert aber auch Wunderbar mit einem Raspberry Pi.)
 - 2x 298:1 Micro Metall Getriebemotor von Pololu (Das sind die Motoren die angesteuert werden.)
 - 1x L298N Dual H Bridge (Ein Motor Controller der zwar für Arduino ausgelegt ist, aber problemlos mit einem Raspberry Pi funktioniert.)
 - 1x Raspberry Pi Modell B+


### Vorbereitung

Als OS verwende ich das empfohlene Raspbian, eine Debian Distribution die für den Raspberry Pi angepasst wurde.
Das bietet den Vorteil das dinge wie z.B. g++ und ein Git Client bereits installiert sind. 
Falls gpp und git widererwartend nicht installiert sind kann man das wie folgt installieren.
> sudo apt-get update
> 
> sudo apt-get upgrade
> 
> sudo apt-get install git-core
> 
> sudo apt-get install g++

Also denkbar einfach. 

Benötigt wird darüber hinaus noch die WiringPi API die wie folgt installiert werden kann.
> git clone git://git.drogon.net/wiringPi
> 
> cd WiringPi
> 
> ./build

WiringPi nutzt jedoch eine andere Belegung der GPIO Pins vom Raspberry Pi
Genaue Belegung ist hier: [http://i.imgur.com/x8nJzJh.png](http://i.imgur.com/x8nJzJh.png)


###Installation

Wenn alles nötige installiert ist, kann die build.sh aus diesem Projekt verwendet werden. 
> ./build.sh

Gegebenfalls muss diese Datei noch ausführbar gemacht werden:
> sudo chmod +x build.sh

Sobald dann alles erstellt wurde, muss die Datei "Control" ausführbar gemacht werden.
> sudo chmod +x control

Und am ende Ausgeführt werden.
> sudo ./control

### Handhabung

Wenn alles funktioniert hat, und die Datei ausgeführt wurde sollte ein Menü wie im folgenden Bild erscheinen.
[http://i.imgur.com/ymppeN6.png](http://i.imgur.com/ymppeN6.png)

Hier können nun die Schritte, die der Roboter befolgen soll, eingegeben werden. Es können hier auch mehrere Schritte angegeben werden, die nach und nach ausgeführt werden.
als Beispiel: 1234
Dadurch bewegt sich der Roboter dann einmal vor, dreht sich nach links, dreht sich nach rechts und bewegt sich wieder zurück.
