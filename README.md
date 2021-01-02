# Evil_Bear
Evil Bear est un jeu vidéo où le BEAR doit décplacer toutes les recettes vers les flammes, le but étant de faire cuire toutes les recettes présentes sur les marmites pour gagner.

Le jeu commence par afficher un menu avec deux choix:

-> 1 Jouer: avec le carte déja prête dans le fichiers "Levels".

-> 2 Modifier les niveaux( grace à la classe Editor): qui permet au joueur de modifier la carte comme il veut:
    
   * La position initiale du "Bear" (Attention! Si vous rajoutez plusieurs "Bear", c'est le dernière rajout qui sera pris en charge après le sauvgarde(avec la fonction saveLevel(map));
          
   * Les marmites: vous pouvez rajouter les marmites dans l'emplacement du clic (Conseil: Equilibrer le nombre des marmites avec celui des flames);
          
   * Les flames: vous pouvez rajouter les flames dans l'emplacement du clic (Attention! Il faut que le nombre de flammes présntes sur la carte <= nombre des marmites pour pouvoir gagner);
          
   * Les murs: vous pouvez rajouter les murs dans l'emplacement du clic (Attention! Il faut laisser au joueur assez d'espace pour pouvoir déplacer toutes les marmites);
   
Comment effectuer ces changements de niveaus?

Pour changer une case quelconque(Bear, flame,...), avec:
  - Le vide: 0 + cliquer autant des fois que vous voulez sur les cases que vous voulez modifier;
  
