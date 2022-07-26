# war-simulator
Alternative self-directed project I did for chapter 16 to practice structures and enumerations.
As usual, throw all the files into a directory and use "gcc -o game war.c deal.c cards.c" to compile, then run the resulting "game.exe" file.

After working on this on and off for a while, this is what I've done. Just splitting a deck of cards into two piles and keeping track of what wins more.
This isn't amazing and I realize that, but I do have plans to revisit this project and make something more out of it. My initial idea of making a truly full-fledged war game where the cards keep restacking with discard piles was too ambitious for me right now, but I know I can do more later.

Version 1.0 goals for an undecided future date:
-Rework the UI to be more easily readable. Numbers should be large and suits should be small.
-Replace the getchar() filler with a function that can read bash-esque commands like:
  +run X turns for easy testing of large war simluations, returning how many turns were simluated.
  +status on each player's draw and discard piles
  +stats for lifetime game statistics (number of times restacked, total round wins for each player, etc)
-Add tie war mechanics where 1 card is turned over as a bounty of sorts.
