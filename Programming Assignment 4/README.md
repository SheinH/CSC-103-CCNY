#My Ship Sails


My Ship Sails is a great kids card game. Read this to understand the rule to play. The mission of the game is to collect 7 cards of the "same suit" you choose. You can sail out your ship if you have 7 cards of the same suit.The card numbers are unrelated in this game.

You need to pass one unnecessary card to your neighboring player, like a clockwise turn agreed by all players. So, others do in the same way at the same time.

In this assignment, you are going to play with other 4 family members and you are to pass out your unnecessary card to player 1, and then player 1 passes one card to player 2, and so on. That means that you are player 0 and you will be passed the 7th card from player 4. 

You can see all of your 7 card set. You are given a choice to pick one card among 7 to pass out player 1. The players 1 through 4 will do the same thing with some intellectual ability in that each of them will choose the most unlikely card (i.e., the minimum number of occurrences of suit) to pass to the next player. My son played with my implementation for one hour to finally give up... Can you win?

The implementation needs to show which card is passed among the players (as a hint). Also typing '?' will show all the players' cards (as a cheating). The game ends if any of 5 players won by collecting the seven cards of the same suits. Your implementation must show the hands of other players in the game end.

Implementing this game is not hard if this is done properly in our learned object-oriented way: note that a card is a structure of number and suit, a player has a vector of card, and the game has a vector of cards as well as a vector of players. See the next example game session. For instance, SJ means "Jack of Spades." My implementation having a full set of comments is less than 150 lines. Good luck.
```
   (a) H5   (b) DK   (c) S2   (d) C3   (e) HA   (f) S5   (g) C2

Which one to replace? a

Hint: player 0 passed H5 to player 1
Hint: player 1 passed S6 to player 2
Hint: player 2 passed H7 to player 3
Hint: player 3 passed S10 to player 4
Hint: player 4 passed D9 to player 0

   (a) C2   (b) DK   (c) S2   (d) C3   (e) HA   (f) S5   (g) D9

Which one to replace? e

Hint: player 0 passed HA to player 1
Hint: player 1 passed C10 to player 2
Hint: player 2 passed SK to player 3
Hint: player 3 passed CA to player 4
Hint: player 4 passed C5 to player 0

   (a) C2   (b) DK   (c) S2   (d) C3   (e) D9   (f) S5   (g) C5

Which one to replace? ?
Player 1   (a) HQ   (b) H5   (c) D6   (d) H2   (e) HK   (f) D2   (g) HA
Player 2   (a) S6   (b) D10   (c) D4   (d) DA   (e) S3   (f) DQ   (g) C10
Player 3   (a) H7   (b) DJ   (c) H9   (d) H6   (e) D5   (f) CK   (g) SK
Player 4   (a) H8   (b) S10   (c) C8   (d) H3   (e) S9   (f) S4   (g) CA
Which one to replace? c

Hint: player 0 passed S2 to player 1
Hint: player 1 passed D6 to player 2
Hint: player 2 passed C10 to player 3
Hint: player 3 passed SK to player 4
Hint: player 4 passed C8 to player 0

   (a) C2   (b) DK   (c) C5   (d) C3   (e) D9   (f) S5   (g) C8

Which one to replace? f
Hint: player 0 passed S5 to player 1
Hint: player 1 passed S2 to player 2
Hint: player 2 passed S6 to player 3
Hint: player 3 passed CK to player 4
Hint: player 4 passed CA to player 0

   (a) C2   (b) DK   (c) C5   (d) C3   (e) D9   (f) C8   (g) CA
Which one to replace? b

Hint: player 0 passed DK to player 1
Hint: player 1 passed S5 to player 2
Hint: player 2 passed S3 to player 3
Hint: player 3 passed S6 to player 4
Hint: player 4 passed CK to player 0

   (a) C2   (b) CA   (c) C5   (d) C3   (e) D9   (f) C8   (g) CK

Which one to replace? x
Wrong input! Which one to replace? e

Hint: player 0 passed D9 to player 1
Hint: player 1 passed D2 to player 2
Hint: player 2 passed S2 to player 3
Hint: player 3 passed S3 to player 4
Hint: player 4 passed H8 to player 0

   (a) C2   (b) CA   (c) C5   (d) C3   (e) CK   (f) C8   (g) H8

Which one to replace? e

Hint: player 0 passed CK to player 1
Hint: player 1 passed DK to player 2
Hint: player 2 passed S5 to player 3
Hint: player 3 passed S2 to player 4
Hint: player 4 passed H3 to player 0

My Ship Sails! --- Player 2 Won...
My Ship Sails! --- Player 4 Won...

[ Final card distributions  ]
Player 0   (a) C2   (b) CA   (c) C5   (d) C3   (e) H8   (f) C8   (g) H3
Player 1   (a) HQ   (b) H5   (c) HA   (d) H2   (e) HK   (f) D9   (g) CK
Player 2   (a) D6   (b) D10   (c) D4   (d) DA   (e) D2   (f) DQ   (g) DK
Player 3   (a) H7   (b) DJ   (c) H9   (d) H6   (e) D5   (f) C10   (g) S5
Player 4   (a) S6   (b) S10   (c) SK   (d) S3   (e) S9   (f) S4   (g) S2
```
