# QtSquid - Gestion de pièces centralisé sur MySQL

*QtSquid* est une application développé en **Qt Widgets** se connectant à une base de données *MySQL* permettant de centralisé la gestion de pièces/équipements informatiques. Le projet est issu d'un stage en laboratoire au service Informatique du [CEGEP de Sept-Îles](https://cegepsi.ca/) afin de compléter les fonctionnalités du logiciel *Octopus ITSM* (notamment dans la gestion de pièces). Il est cependant important de préciser que le logiciel *Octopus ITSM* possède actuellement des facultés en gestion de pièces assez complètes pour rendre ce projet inutile.


## Déploiement

Un manque de temps/motivation sur ce projet le laisse actuellement dans un état incomplet. De ce fait, aucun déploiement utilisateur ne fut actuellement réalisé. Seul la mise en place en tant que développeur fonctionne actuellement.

### Dépendances

Avant de réaliser la mise en place, il est important de prendre en compte les élements suivants:
* Certaines dépendances ne fonctionneront uniquement que sur une verion 64 bits de Windows 7, 8 ou 10.
* La base de données peut être déployé sur n'import quel système.

Voici la liste des dépendances pouvant ou devant être installées pour **développer et éxecuter** l'application:
* Qt 5.12 (msvc2017-64)
* Microsoft Visual Studio 2017/19
* Xampp (Apache + MySQL)
* MySQL Connector C/C++
* MySQL Server

### Mise en place

Afin de réaliser la mise en place complète de l'application en tant que développeur suivez les étapes suivantes:
* Télécharger le code source de l'application [*QtSquid*](../master/application/QtSquid).
* Reconfigurer votre installation **Qt 5.12** sur votre verions de **Microsoft Visual Studio** en **x64**.
* Créer sur le dossier de la solution le dossier **deps** pour y placer les dépendances du **MySQL Connector C/C++** et **MySQL Server**.
* Démarrer **XAMPP Control Panel** puis le serveur *Apache* et *MySQL*.
* Ouvrez *localhost:3306* sur votre navigateur puis ouvrez votre *PhpMyAdmin*.
* Créer votre base de donnée puis éxecuter le fichier [*database.sql*](../master/application/sql/database.sql).

Si tout fonctionne correctement, vous devriez être capable d'éxecuter l'application en mode **Debug (x64)** sans problème.


## Fonctionnement

Le besoin primaire de l'application était de faciliter les sorties et entrées de matériel en utilisant un **scanner de code barre**. Afin de réaliser cela, l'application réalise les fonctionnalités suivantes:
* Recherche facile des pièces disponibles et/ou attribuées
* Ajout, suppression, attributation et retrait des pièces
* Paramétrage des connections et propriétés de l'application

### Base de données

La base de données MySQL est organisée de la manière suivante:

<p align="center">
  <img src="/application/img/MCD.png">
</p>

Voici les équivalences de ces derniers:
* **room**: emplacement physique d'une machine
* **type**: type de machine
* **configuration**: machine physique sur laquelle placer une/des pièce(s)
* **category**: catégorie de la pièce
* **contact**: personne à contacter en cas de rupture de stock
* **item**: informations d'une pièce particulière
* **equipment**: liaison de pièce à une machine, si spécifié, ou en stock dans le cas contraire

### Interface

### Organisation

### Paramêtres


## Problèmes


## Mentions


## Sources
