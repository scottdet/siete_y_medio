# siete_y_medio
Spanish card game implementation in C++.
Below I have listed some information and rules about the game.

When a player makes a bet against the dealer. There are 4 possible outcomes:

  1. The player comes closer to 71/2 than the dealer or the dealer busts but the player did not bust. 
    In this case the player wins the round and the player's money increases by the amount that was bet.

  2. The dealer comes closer to 71/2 than the player, or the player busts.
    In this case the player loses the round and the player's money decreases by the amount that was bet.

  3. Both, the player and dealer bust.
    In this case the player loses the round and the player's money decreases by the amount that was bet. 
    This is called house advantage. 

  4. Both the player and the dealer have the same total and  they do not bust.
    In this case a tie is declared and no money is exchanged.
    
Background information:

The traditional Spanish baraja is an old deck that was brought over by the Moors to Spain during the 14th century. The cards are still called naipes after the nā'ib cards found in the Mamluk deck... 

Smaller decks have 40 cards and lack ranks 8, 9 and comodines (jokers). The four suits are bastos (clubs), oros (literally "golds", that is, golden coins), copas (cups) and espadas (swords). The four suits are thought to represent the four social classes of the Middle Ages. The suit of coins represents the merchants, the clubs represents the peasants, the cups represent the church and the swords represent the military.

The three face cards of each suit have pictures similar to the jack, queen, and king in the French deck, and rank identically. They are the sota, which is similar to the jack/knave and generally depicts a page or squire, the caballo (knight, literally "horse"), and the rey (king) respectively.

At each round of play the player places a bet. After that, the player and the dealer each draw one card from the deck.The player is then repeatedly asked if another card is wanted. The player can continue to draw cards while the total is less than 71/2. After the player's turn is over, the dealer's cards are shown. The dealer's play is always the same: the dealer continues to draw cards only if the total is less than 51/2.
