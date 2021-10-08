# TP1 RESEAU


## How to launch

* Download the code from github or go to code -> open with visual studio.
* Unzip the files in a folder if you didn't open with VS.
* Open the folder where all the files are with visual studio.
* Generate the solution.
* Use the executables of the server and the client.

## How to try with default configuration

* Launch Server executable and press enter 3 times to use default configuration with TCP exchanges, port 27000 and localhost ip address.
* Launch client(one or multiple) and press enter 3 times to use the same configuration.
* Use the client terminals to enter and send messages (press enter to send the messages) to the server and the others clients.

## Fonctionnalités non terminées

- Gestion des échanges UDP
- Gestion de quelques bugs dans les échanges TCP
- Gestion de certaines déconnexions

## Réponse à la question 

Pour le chat d'un jeu vidéo, il est plus censé d'utiliser le protocole TCP.
L'UDP ne possède aucune vérification de l'intégrité ou de l'ordre dans lequel les paquets arrivent.
Ainsi, dans un chat, on aurait des messages pouvant arriver dans des ordres différents et même tronqués ou modifiés.
En utilisant TCP, on évite ces problèmes et on peux aussi savoir si les paquets ont bien été envoyés ou bien recus.
Le TCP est donc plus fiable et plus stable dans le cadre d'un chat, alors qu'au contraire, dans un jeu il sera probablement plus utile d'utiliser l'UDP.
