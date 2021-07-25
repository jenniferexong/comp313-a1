# COMP313 Assignment 1
**Jennifer Ong**

# Duck Game

[insert link to video here]

### Description
You are a mother duck who has recently laid eggs. You must protect your offspring from wolves, while feeding your ducklings once they have hatched.

### Gameplay Mechanics
- Control the player with WASD and the mouse.
- Click the left mouse button to quack. Quack near a wolf to scare it away.
- Walk over worm areas to pick up a worm
- Walk to a duckling while holding a worm to feed it.
- Press tab to pause.

---
There are two main actions in the game. One is scaring away wolves, and one is feeding ducklings before they starve.

The hardest part of the game was implementing the wolves. There were several reasons for this. The first was getting collisions to work with eggs/ducklings. I had an issue where wolves that were sent to move to a location would not respond to collisions. This was due to the wolve's collision component not being the root of the blueprint. Another challenge was changing the animation of a wolf. I found that attempting to simply change the animation asset resulted in the pose of the wolf freezing. I solved this by using an animation blueprint with states machines. Another difficulty was understanding sound events in Unreal, to allow wolves to respond to nearby sounds. Finally, it was challenging to find balance in the speed of the wolves. I found that if every wolf started hunting at the same time, the game play was less interesting, and sometimes too difficult. For this reason I staggered the start times of the wolves, and slightly randomized their speeds to ensure that they don't all reach the nest at the same time.

The most interesting part of the game is...
