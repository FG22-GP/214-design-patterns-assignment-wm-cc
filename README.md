[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment


Design Patterns used: 
			Major: Observer,Singleton
			Minor :iteration , gameloop



Observer: 

Why: We selected this pattern becuase it seems very useful and common in larger project. Innitial inspiration and evidence of it's usefulness was the game Bastion and its
of the observer pattern for the narrator of the game.

How: We used observers to determine player health , damage dealt to the player and damage healed when picking up medkits

What we learned:

________________________________________________________________________________________________________________________________________________________________________________

Singletons: 

Why: Singletons are useful for gathering data to be used later, we were making a game with no engine so we couldnt rely on gameobjects and [SerializeField] to get data for use
so we decided to play it safe and use singletons to get info in the beginning of the game and use it later through the whole game 

How: Our singleton gets an instance of the player to be later used to damage the player , heal player and detect if the player is still alive in runtime. 
It is also used to detect intersection between the player nad the medkit.

what we learned: Singletons are useful as they run once so , theyre very good for performance but they are also rather unnecessary at times , so they should be used sparingly 
Only to grant access to objects that will be accessed often such as the player that will for exampled be accessed by enemies for detection, pathfinding towards the player,
shooting at player, etc. Our game is simple so we only used one singleton because there wasn't really a need for it otherwise.

/////////////////////////////////////////////////////////////////////////////////////////////

Minor:

The use of these patterns was inevitable within a game of any type so we had to use these 


Iteration : We iterate through random coordinates everytime we teleport the medkit. We also use iteration to ocasionally deal damage to the player if they dont pick up a medkit

Gameloop: A game by definition must contain a gameloop and ours revolves around picking up medkits and losing health if you dont.


