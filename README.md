# COMP313 Assignment 1
**Jennifer Ong - 300473698**

# Duck Game

[Link to demo video](https://youtu.be/AfGfKK9r-2I)

### Description
You are a mother duck who has recently laid eggs. You must protect your offspring from wolves, while feeding your ducklings once they have hatched.

### Gameplay
- Control the player with WASD and the mouse.
- Click the left mouse button to quack. Quack near a wolf to scare it away.
- Walk over worm areas to pick up a worm
- Walk to a duckling while holding a worm to feed it.
- Press tab to pause.
- Points are gained when an egg hatches, and a duckling is fed.

---

##### Main action
The main action of the game is running around the nest as a duck to scare away wolves and pickup worms. The goal of the game is to raise as many ducklings as possible. These actions are performed by using the mouse and WASD keys.

##### Hardest part to get working in Unreal
The hardest part of the game was implementing the wolves. There were several reasons for this. The first was getting collisions to work with eggs/ducklings. I had an issue where wolves that were sent to move to a location would not respond collisions as intended. This was due to the wolve's collision component not being the root of the blueprint. Another challenge was changing the animation of a wolf. I found that attempting to simply change the animation asset resulted in the pose of the wolf to freeze. I solved this by using an animation blueprint with states machines. Another difficulty was understanding sound events in Unreal, to allow wolves to respond to nearby sounds. Finally, it was challenging to find balance in the speed of the wolves. I found that if every wolf started hunting at the same time, the game play was less interesting, and sometimes too difficult. For this reason I staggered the start times of the wolves, and slightly randomized their speeds to ensure that they don't all reach the nest at the same time.

##### Most interesting part of the game
I think the most interesting part of the game is the ducklings. Although ducklings and eggs are unmoving and defenseless, they form the objective of the game. As a player it does not feel great to watch a helpless duckling die, so this forms a good incentive to do well in the game. The duckling hunger system also makes the game much more interesting, as it forces players to leave the nest to obtain food. This prevents players from 'camping' at the nest where they can easily scare away the wolves.
