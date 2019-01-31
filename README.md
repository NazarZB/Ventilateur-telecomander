> # **Ventilateur télécommander**  
 
Ce projet permet de réaliser un ventilateur télécommandé. 
## **Vidéo** : 

[![video](https://img.youtube.com/vi/UroaVnvcMIw/0.jpg)](https://www.youtube.com/watch?v=UroaVnvcMIw)

# Branchements 

![Branchements](https://image.noelshack.com/fichiers/2019/05/4/1548950965-branchements-ventilateur-telecommander.png)

# Matériels utilisés

>- [Arduino Uno](https://store.arduino.cc/arduino-uno-rev3) : 

>![Uno](https://store-cdn.arduino.cc/uni/catalog/product/cache/1/image/520x330/604a3538c15e081937dbfbd20aa60aad/a/0/a000066_featured_1_.jpg)

>- [Moteur à courant continu](https://www.amazon.fr/Gikfun-130-Micro-courant-continu-Arduino/dp/B07BHHP2BT/ref=sr_1_1?s=industrial&ie=UTF8&qid=1548949612&sr=1-1&keywords=Moteur+%C3%A0+courant+continu+arduino)

>![MCC](https://images-na.ssl-images-amazon.com/images/I/71BH53uCHyL._SL1500_.jpg)

>- [Recepteur infrarouge](https://www.amazon.fr/ExcLent-Capteur-Infrarouge-R%C3%A9ception-Ky-022-Noir/dp/B07MVZCW7T/ref=sr_1_17?s=industrial&ie=UTF8&qid=1548949700&sr=1-17&keywords=Recepteur+infrarouge+arduino)

>![Recepteur infrarouge](https://images-na.ssl-images-amazon.com/images/I/41kABgHwuyL.jpg)

> - [L239D](https://www.amazon.fr/meeboo-pilote-Moteur-Arduino-Stepper/dp/B071H86LDF/ref=sr_1_3?s=industrial&ie=UTF8&qid=1548949884&sr=1-3&keywords=L293D+arduino)

![L239D](https://images-na.ssl-images-amazon.com/images/I/61DzGsvJrBL._SL1000_.jpg)

> - [TTélécommande infrarouge](https://www.amazon.fr/Keyes-t%C3%A9l%C3%A9commande-infrarouge-Kt-014-Test-r%C3%A9cepteur/dp/B077K7N2WV/ref=sr_1_3?s=industrial&ie=UTF8&qid=1548950675&sr=1-3&keywords=T%C3%A9l%C3%A9commande+infrarouge+arduino)

![TI](https://images-na.ssl-images-amazon.com/images/I/71NhqN7rpVL._SL1500_.jpg)

# Bibliothèques utilisées 

> - arduino-L293D 
> - Arduino-IRremote


# Code 

On ajoute les bibliothèques dont on aura besoin :

``` c++
//For Ir Remote
#include <boarddefs.h>
#include <IRremote.h>
#include <IRremoteInt.h>
#include <ir_Lego_PF_BitStreamEncoder.h>
//For DC motor
#include <L293D.h>
```

On crée les objets pour chaque modules : 

``` c++
L293D motor(6,5,4);

IRrecv irReceiver(2);
decode_results results;
``` 

On initialise le moteur et le récepteur infrarouge (sans oublier la vitesse de transmission) : 

``` c++
Serial.begin(9600);
irReceiver.enableIRIn();
motor.set(0);
}
```
On récupère le code émis par la télécommande : 

``` c++
if (irReceiver.decode(&results)) {
    // le code infrarouge est dans la variable results.value
    Serial.println(results.value);
    irReceiver.resume();
```  

On attribue chaque code à une action sur le moteur en ajoutant une condition : 

``` c++
if (results.value == 16724175)
  {
  motor.set(150);
  }
if (results.value == 16718055)
  {motor.set(200);
  }
if (results.value == 16743045)
  {motor.set(250);
  }
if (results.value == 16753245)
  {motor.set(0);
  }
```

