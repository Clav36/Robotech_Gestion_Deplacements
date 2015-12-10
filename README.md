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


> Voici la description succincte de chaque classe. Pour plus d'info aller voir la doc.

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CPoint**    | **Classe de base**, gestion de l'affichage de chaque point sur la vue  |
| CPRond        | Gestion des points ronds |
| CPRect        | Gestion des points carrés  |

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CLine**     | **Classe de base**, gestion de l'affichage de chaque ligne sur la vue |
| CLContinue    | Gestion des lignes continue  |
| CLPointillee  | Gestion des lignes en pointillée |

| Classes         | Descriptions   |
| --------------  | ------------- |
| **CObjet**      | **Classe de base**, gestion des objets |
| COCube          | Gestion des cubes - affichages / traitements  |
| COCone          | Gestion des cônes - affichages / traitements  |
| COCylindre      | Gestion des cylindres - affichages / traitements  |
| COCOCoquillage  | Gestion des 'coquillages' - affichages / traitements  |

| Classes       | Descriptions   |
| ------------- | ------------- |
| **CEtape**    | **Classe de base**, gestion de chaque etape (distance à parcourir, rotations...) |
| CGroupeEtape  | Regroupement d'étapes pour une meilleure compréhension de l'affichage  |

| Classes       | Descriptions   |
| ------------- | ------------- |
| CAction       |  Gestion des actions des bras |

| Classes       | Descriptions   |
| ------------- | ------------- |
| CRobot        | Prise en compte de la dimension du robot (-> détection des collisions)  |

| Classes       | Descriptions   |
| ------------- | ------------- |
| MainFrame     | **Classe principale**, gestion de la fenetre  |

| Classes       | Descriptions   |
| ------------- | ------------- |
| QViewTable    | Gestion de la vue, hérite de **QGraphicsView**  |


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




