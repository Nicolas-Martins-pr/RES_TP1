# TP1 RESEAU





## How to launch

* Download the code from github or go to code -> open with visual studio.
* Unzip the files in a folder if you didn't open with VS.
* Open the folder where all the files are with visual studio.
* Generate the solution.
* Use the executables of the server and the client.

## Question 

Pour le chat d'un jeu vidéo, il est plus censé d'utiliser le protocole TCP.
L'UDP ne possède aucune vérification de l'intégrité ou de l'ordre dans lequel les paquets arrivent.
Ainsi, dans un chat, on aurait des messages pouvant arriver dans des ordres différents et même tronqués ou modifiés.
En utilisant TCP, on évite ces problèmes et on peux aussi savoir si les paquets ont bien été envoyés.
Le TCP est donc plus fiable et plus stable dans le cadre d'un chat, alors qu'au contraire, dans un jeu il sera probablement plus utile d'utiliser l'UDP.
