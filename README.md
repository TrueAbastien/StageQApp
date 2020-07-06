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

### Organisation

L'application est organisé de façon le plus modulable et *DRY* possible. En voici un **diragramme de classe super-simplifié**:

<p align="center">
  <img src="/application/img/SimpleClassDiagram.png">
</p>

### Interface

L'interface est divisé en **3 fenêtres/pages** répondant aux fonctionnalités données plus tôt. Certaines fenêtres secondaires viendront compléter ces dernières fonctionnalités.

#### Recherche

<p align="center">
  <img width="60%" src="/application/img/SearchPage.png">
</p>

La page de recherche permet à un utilisateur d'accéder rapidement aux différentes pièces. Les éléments à droite permettent de filtrer la recherche sur différents critères tel que **la disponibilité** ou **l'identifiant du code barre**. Le résultat de la recherche est affiché dans le tableau présent sur la page. Le bouton *Select* exécute la commande et met à jour le tableau.

#### Edition

<p align="center">
  <img width="60%" src="/application/img/EditPage.png">
</p>

La page d'édition permet à l'utilisateur de gérer les transferts de matériel/pièces dans la base de données.
* Le bouton **_Add_** permet d'ajouter de nouvelles pièces dans le matériel disponible.
* Le bouton **_Remove_** réalise l'inverse de la fonctionnalité précédente et supprime une quantité d'une pièce particulière du matériel disponible.
* Le bouton **_Store_** déplace du matériel attribué vers le matériel disponible si la quantité précisée le permet.
* Le bouton **_Take_** enlève une quantité du matériel disponible vers une machine particulière afin de l'attribuer.

Si l'on cherche à ajouter de nouvelle pièces dans la base de données pour un barcode inexistant, une fenêtre de **Création** d'ouvrira.

<p align="center">
  <img width="40%" src="/application/img/CreationPage.png">
</p>

Chacune des informations liées à une pièce particulière pourront être précisé pour la création d'une nouvelle pièce. Il est important de précisé que **le code barre doit absolument être unique**.

#### Connection

<p align="center">
  <img width="60%" src="/application/img/ConnectionPage.png">
</p>

La page de connection permet de paramétrer les propriétés locales de connection à la base de données.
* L'**_Address_** correspond à l'adresse IPv4 de la base de données MySQL sur votre réseau.
* Le **_Port_** correspond au port de l'adresse précédente.
* L'**_Username_** correspond au nom de votre compte de votre base de donnée (et ses permission).
* Le **_Password_** correspond au mot de passe de ce dernier compte.

Il vous est possible d'enregistrer séparément vos informations personnels et celles de la connection (à proprement parler).

### Paramêtres

Chaque élément enregistré localement se trouve dans les *Settings* dans le dossier local au projet. Par exemple, les informations liés à la page de *Connection* se trouve dans le fichier *database.settings*:

<p align="center">
  <img width="30%" src="/application/img/SettingsExample.png">
</p>

L'encryption ressemble à celle du *.yml* mais ne permet pas la génération de structure: un champ a une équivalence se limitant aux chaînes de charactères.

Certains paramêtres, tel que le style de l'application, peuvent se reconfigurer à l'aide de fenêtre de paramétrage.

<p align="center">
  <img width="25%" src="/application/img/StylesheetPage_1.png">
  <img width="25%" src="/application/img/StylesheetPage_2.png">
  <img width="25%" src="/application/img/StylesheetPage_3.png">
</p>


## Problèmes

L'application rencontre actuellement les problèmes suivants:
* manque de sécurité
* aucune gestion des exceptions
* fuites mémoires
* plateforme limitée
* interface non-responsive

Les fonctionnalités manquantes et initialement prévu au projet sont les suivantes:
* fonctionnalités de la barre d'outils
* complétion de la page de permission
* création des éléments particuliers (salles, catégories, ...)
* auto-mailing dés une rupture de stock
* export des résultats au format Excel (.xls)
* mise en place de formulaire exporté au format PDF


## Mentions

Ce projet fut réalisé dans le cadre d'un stage au service Informatique au [**CEGEP de Sept-Îles**](https://cegepsi.ca/) (Canada, QC) sous la direction de **_Mme Jeanne DESBIENS_** en liaison avec le programme en *Informatique Graphique* à l'[**IUT du Puy en Velay**](https://www.iut-clermont.fr/tag/lepuyenvelay/) sous la supervision de **_M Vincent SAUVAGE_**.
