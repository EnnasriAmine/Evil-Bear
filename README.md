# Evil_Bear
Evil Bear est un jeu vidéo où le BEAR doit décplacer toutes les recettes(marmites) vers les flammes, le but étant de faire cuire toutes les recettes présentes sur les marmites pour gagner.


Poura compiler(Windows):
 1. Déposer par exemple le dossier source au répertoire Windows(C:);
 2. Ouvrir l'invite des commandes;
 3. Accéder au répertoire, par exemple pour notre cas Windows(C:), (cd.. et appuyer sur entrer, encore une fois cd.., et ensuite cd src(le dossier qui contient le projet);
 4. En fin appuyer sur make, si aucun message afficher cela veut dire  que tout est bien passé, sinon vous verrez un messgae d'erreur qui explique le problème( soit la commande"make" n'ont reconnue, soit compilateur "gcc" intouvable) donc il faudra essayer d'installer tout ce qui est demandé dans les messages dans le cas où ils sont pas présents sur votre ordinateur;
 5. Si aucun message afficher, vous allez trouvez sur le répétoire du projet un exécutable nommé Evil_Bear.exe, c'est bien le jeu.
 
 

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
  - Le mur : 1 + cliquer autant des fois que vous voulez sur les cases que vous voulez modifier;
  - La marmite : 2 + cliquer autant des fois que vous voulez sur les cases que vous voulez modifier;
  - La flame: 3 + cliquer autant des fois que vous voulez sur les cases que vous voulez modifier;
  - Le "Bear": 4 + cliquer autant des fois que vous voulez sur les cases que vous voulez modifier.
  


Si vous avez effectué un changement et vous êtes sûr de ce changement, appuyer sur S pour sauvegarder le changement.
 


Si vous avez regretté des changements effectué, vous pouvez supprimer les changements effectué après le dernièr sauvegarde avec le boutton C.
  


A la fin de ses changements faudra appuyer sur S pour sauvegarder la nouvelle carte et pouvoir jouer avec la prochaine fois, et sur ESC pour revenir au menu principal.



C'est à vous de jouer maintenant ;)
