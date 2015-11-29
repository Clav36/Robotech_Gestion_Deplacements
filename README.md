# Robotech_Gestion_Deplacements
> Application Qt - Gestion des déplacements du robot principal

> Calendrier: **en cours**

> Documentation: **en cours**

#1. L'application
##1.1) Le cahier des charges

> Le but de cette application est de gérer les déplacements du robot principal sur la table de la CdF.

Les actions que doit gérer l'application sont:

- donner les déplacements [avance, reculer, rotation...] à éffectuer 
- donner les différents mouvements des bras pour attraper, stocker [cubes, cônes, cylindre, 'coquillages'] et construire les figures demandées.
- donner la liste des capteurs à activer ou à désactiver en foncion de la position du robot
- pourvoir charger le programme généré sur le robot directement depuis l'application (via Wifi)
- basculer d'un côté ou de l'autre facilement [vert ou violet]
- gestion des différentes tables possibles [une solution pour chaque cas]
- gestion des différents niveau de la table (relatif à l'empilement des objets)

Amélioration du confort utilisateur:

- possibilité de zoomer sur une portion de la table
- différentes catégories (etapes/groupe d'étapes/actions/groupe d'actions)
- possibilité d'ajout, suppression, modification de ces catégories
- gestion des collisions
- sauvegarde et ouverture de fichier


> à compléter

##1.2) Structure de l'interface

![alt tag](https://raw.githubusercontent.com/Clav36/Robotech_Gestion_Deplacements/master/pr%C3%A9sentation.png)

##1.3) Structure de la POO

![alt tag](https://raw.githubusercontent.com/Clav36/Robotech_Gestion_Deplacements/master/POO.png)

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CPoint**    |   |
| CPRond        |   |
| CPRect        |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CLine**     |   |
| CLContinue    |   |
| CLPointillee  |   |

| Classes         | Descriptions   |
| --------------  | ------------- |
| **CObjet**      |   |
| COCube          |   |
| COCone          |   |
| COCylindre      |   |
| COCOCoquillage  |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CEtape**    |   |
| CGroupeEtape  |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| CAction       |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| CRobot        |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| MainFrame     |   |

| Classes       | Descriptions   |
| ------------- | ------------- |
| MainFrame     |   |
#2. Annexes
### 2.1) Utilisation de GitHub

Installer GitHub (sous Linux):

- `apt-get install git`

Lors de la première utilisation, cloné les dossiers grâce à cette ligne de commande:

- `git clone https://github.com/Clav36/Robotech_Gestion_Deplacements.git`
  
Pour modifier les fichiers sur le serveur utiliser les commandes suivantes:

- `git add <fichier>`
- `git commit -m "Commentaires"`
- `git push origin master`
  
### 2.2) Convention d'écriture

> Pour pouvoir travailler ensemble il nous faut adopter une convention d'écriture:

#### Pour les **classes**: 

Commence par un `C`(Maj) et la première lettre du nom de la classe est aussi en Maj. 

Exemple:

<pre><code>class CTest {
/* some code */
}</code></pre>


#### Pour les **variables**:
- Les variables membres statiques:
<pre><code>int m_nNom;
  char m_cNom;
  double m_dNom;
  float m_fNom;
  QString m_sNom;
</code></pre>

- Les variables membres dynamiques (pointeurs):

  `<type>* m_pNom;`

- Les variables non membres:
  
  `idem que les variables membres mais sans le m_`
  
- Les variables globales:

  `idem que les variables membres mais avec g_`




