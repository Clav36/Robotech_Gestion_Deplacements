# Robotech_Gestion_Deplacements
> Application Qt - Gestion des déplacements du robot principal

> Calendrier: **en cours**

> Documentation: **en cours**

## 1) Utilisation de GitHub

Installer GitHub (sous Linux):

- `apt-get install git`

Lors de la première utilisation, cloné les dossiers grâce à cette ligne de commande:

- `git clone https://github.com/Clav36/Robotech_Gestion_Deplacements.git`
  
Pour modifier les fichiers sur le serveur utiliser les commandes suivantes:

- `git add <fichier>`
- `git commit -m "Commentaires"`
- `git push origin master`
  
## 2) Convention d'écriture

> Pour pouvoir travailler ensemble il nous faut adopter une convention d'écriture:

### Pour les **classes**: 

Commence par un `C`(Maj) et la première lettre du nom de la classe est aussi en Maj. 

Exemple:

<pre><code>class CTest {
/* some code */
}</code></pre>


### Pour les **variables**:
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

## 3) Avancement

| Classe        | Développeur     | Avancement | Doc  |
| :------------ |:---------------:|:----------:| ----:|
| CPoint        | Martin C.       |       100% |  100%|
| CPRond        | Martin C.       |       100% |  100%|
| CLine         | Martin C.       |       100% |  100%|
| CRobot        | Martin C.       |       100% |  100%|
| QViewTable    | Martin C.       |       100% |  100%|



