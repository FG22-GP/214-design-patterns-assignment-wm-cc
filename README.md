[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-24ddc0f5d75046c5622901739e7c5dd533143b0c8e959d652212380cedb1ea36.svg)](https://classroom.github.com/a/XUCedPox)
# marczaku-214-design-patterns-assignment


Design Patterns used:
Major: Observer,Singleton
Minor :iteration , gameloop


# Observer Pattern: 

Why: Observer pattern is good when you have multiple actors that needs to react when a function gets called. The notifier does not need to have direct references to all of these actors that needs to react. 
This decouples the logic from the different areas of your game and you can have seperate scripts to make them single responsibility. For example; a particle system could subscribe to an OnHit event to play an OnHitVFX. We could also subscribe with a health bar UI to display the new health with the same OnHit notify.

How: In our TextHandler, we subscribe to the player health change as an IObserver(interface). When a health change happens, we notify all IObserver actors that are "subscribed" to that function call. The observers themselves put themselves into the notifiers list. Then the notifier sends a "call to action" to all IObservers in that list.

________________________________________________________________________________________________________________________________________________________________________________

Singletons: 

Why: Singletons are useful for gathering data to be used later, we were making a game with no engine so we couldnt rely on gameobjects and [SerializeField] to get data for use
so we decided to play it safe and use singletons to get info in the beginning of the game and use it later through the whole game 

How: Our singleton gets an instance of the player to be later used to damage the player , heal player and detect if the player is still alive in runtime. 
It is also used to detect intersection between the player nad the medkit.

what we learned: Singletons are useful as they run once so , theyre very good for performance but they are also rather unnecessary at times , so they should be used sparingly 
Only to grant access to objects that will be accessed often such as the player that will for exampled be accessed by enemies for detection, pathfinding towards the player,
shooting at player, etc. Our game is simple so we only used one singleton because there wasn't really a need for it otherwise.

________________________________________________________________________________________________________________________________________________________________________________

Minor:

The use of these patterns was inevitable within a game of any type so we had to use these 


Iteration : We iterate through random coordinates everytime we teleport the medkit. We also use iteration to ocasionally deal damage to the player if they dont pick up a medkit

Gameloop: A game by definition must contain a gameloop and ours revolves around picking up medkits and losing health if you dont.


