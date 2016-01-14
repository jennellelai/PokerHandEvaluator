//Jennelle Lai
//CS110B
//02/08/2015
//Professor Harden
//a4.cpp
//Poker Hands Assignment

/*
 This program asks the user to enter five numeric cards between two and nine, inclusive.
 After the user enters the five numbers, the cards in their hand is sorted from least to
 greatest. Then, the program will determine the highest power that their hand, the five
 numeric cards that they entered earlier, holds. If the user's hand has four cards of the
 same number, the output will be "Four of a Kind!". If the user's hand has three cards of
 the same number and the other two cards of the same number, the output will be "Full House!".
 If the user's hand has five cards of consecutive order with a difference of one between each
 two adjacent cards, then the output will be "Straight!". If the user's hand has three cards of
 the same number, the output will be "Three of a Kind!". If the user's hand has two pairs of
 cards with each pair being a different number, the output will be "Two Pair!". If the user's
 hand has only one pair of cards of the same number, the output will be "Pair!". And lastly,
 if the user's hand has no special power, it will output "High Card!".
 */

#include <iostream>
using namespace std;

const int NUM_CARDS = 5; //The number of cards that the user will enter
const int LOWEST_CARD = 2;//The lowest card number possible
const int HIGHEST_CARD = 9;//The highest card number possible

void sortCards(int hand[]);
int highestAmountOfSameCard(const int hand[]);
int amountOfPairs (const int hand[]);
bool containsPair(const int hand[]);
bool containsTwoPair(const int hand[]);
bool containsThreeOfaKind(const int hand[]);
bool containsStraight(const int hand[]);
bool containsFullHouse(const int hand[]);
bool containsFourOfaKind(const int hand[]);


int main() {
    int cards[NUM_CARDS];
    
    cout << "Enter five numeric cards, no face cards. Use 2 - 9. " << endl;
    
    for (int i = 0; i < NUM_CARDS; i++) {
        cout << "Card " << i+1 << ": ";
        cin >> cards[i];
    }
    
    sortCards(cards);
    
    if (containsFourOfaKind(cards)) {
        cout << "Four of a Kind!";
    }
    else if (containsFullHouse(cards)) {
        cout << "Full House!";
    }
    else if (containsStraight(cards)) {
        cout << "Straight!";
    }
    else if (containsThreeOfaKind(cards)) {
        cout << "Three of a Kind!";
    }
    else if (containsTwoPair(cards)) {
        cout << "Two Pair!";
    }
    else if (containsPair(cards)) {
        cout << "Pair!";
    }
    else {
        cout << "High Card!";
    }
}



/*
 This function uses the bubble sort to sort the user's hand, the integer array hand[],
 from least to greatest.
 It begins with assigning the first card of hand[] as the lower card A.K.A lowerCard
 and the second card of hand[] as the higher card A.K.A higherCard.
 If lowerCard happens to be higher than higherCard, then the first card
 and the second card of hand[] swaps positions.
 Then the assignment of lowerCard and the higherCard moves up in hand[], so lowerCard
 is then assigned to the second card of hand[] and the higherCard is assigned to the third
 card of hand[] now. Then it repeats the step where if lowerCard happens to be higher
 than higherCard, then the second card swaps positions with the third card of hand[].
 Then the reassignment of lowerCard and higherCard moves up until it reaches the
 last card of hand[].
 Then this whole process will repeat for NUM_CARDS times, which is the 'amount of cards that
 hand[] has' times, so in this particular program, it will repeat for a total of five times
 since there are five cards in the user's hand.
 */

void sortCards(int hand[]) {
    int lowerCard, higherCard; //The lower card and the higher card of the hand
    int times = NUM_CARDS; //The number of times that the bubble sort has to run
    
    while (times != 0) {
        for (int i = 0; i < NUM_CARDS; i++) {
            lowerCard = hand[i];
            higherCard = hand[i+1];
            
            if (lowerCard > higherCard) {
                hand[i] = higherCard;
                hand[i+1] = lowerCard;
            }
        }
        times--;
    }
}



/*
 This function returns the highest amount of the card with the same number
 in the user's hand, the constant integer array hand[].
 First, it checks if the first card's number of hand[] is equal to
 the first,lowest card number of the range possible A.K.A LOWEST_CARD, in this case,
 the range is from two to nine, so it starts with two.
 If they are equal, then the sameCardCount will increment by one. This repeats for
 each card in hand[]
 After it reaches the last card of hand[], if sameCardCount is greater or
 equal to highestAmount, then highestAmount will equal to sameCardCount.
 Then sameCardCount is reset to zero as this 'checking the hand[]'s cards
 against the numbers of the range' process goes back to the first card of the hand[]
 and checks it against the next number of the range, which will be three.
 This whole, entire process repeats until the end of the range A.K.A HIGHEST_CARD,
 which is the number nine.
 Lastly, the function will return highestAmount, the highest amount of cards of the
 same number in hand[].
 */

int highestAmountOfSameCard(const int hand[]) {
    int highestAmount = 0; //Contains the highest amount of cards of the same number
    int sameCardCount = 0; //Keeps track of the amount of cards of the same number
    
    for (int j = LOWEST_CARD; j <= HIGHEST_CARD; j++) {
        for (int i = 0; i < NUM_CARDS; i++){
            if (hand[i] == j) {
                sameCardCount++;
            }
        }
        if (sameCardCount >= highestAmount) {
            highestAmount = sameCardCount;
        }
        sameCardCount = 0;
    }
    return highestAmount;
}



/*
 This function returns the amount of pairs that the user has in their hand,
 the constant integer array hand[].
 First, it checks if the first card's number of hand[] is equal to
 the first,lowest card number of the range possible A.K.A LOWEST_CARD, in this case,
 the range is from two to nine, so it starts with two.
 If they are equal, then the sameCardCount will increment by one. This repeats for
 each card in hand[].
 If the sameCardCount is greater than or equal to two, then sameCardCount will divide by two
 and add it to numOfPairs. sameCardCount divides by two because two cards make up a pair.
 After it reaches the last card of the user's hand, sameCardCount is reset to zero as
 this 'checking hand[]'s cards against the numbers of the range' process
 goes back to the first card of hand[] and checks it against the next
 number of the range, which will be three.
 This whole, entire process repeats until the end of the range A.K.A HIGHEST_CARD,
 which is the number nine.
 Lastly, the function will return numOfPairs, the total number of pairs that hand[] has.
 */

int amountOfPairs(const int hand[]) {
    int sameCardCount = 0; //Keeps track of the amount of cards of the same number
    int numOfPairs = 0; //Contains the number of pairs in the hand
    
    for (int j = LOWEST_CARD; j <= HIGHEST_CARD; j++) {
        for (int i = 0; i < NUM_CARDS; i++){
            if (hand[i] == j) {
                sameCardCount++;
            }
        }
        if (sameCardCount >= 2) {
            numOfPairs = numOfPairs + sameCardCount/2;
        }
        sameCardCount = 0;
    }
    return numOfPairs;
}




/*
 This function returns true if the user's hand, the constant integer array hand[],
 has only one pair, otherwise it returns false.
 It calls amountOfPairs(hand) to get the number of pairs that hand[] has.
 If the user has only one pair in hand[], then the function returns true.
 If not, the function returns false.
 */

bool containsPair(const int hand[]) {
    if (amountOfPairs(hand) == 1) {
        return true;
    }
    return false;
}




/*
 This function returns true if the user's hand, the constant integer array hand[],
 has two pairs, otherwise it returns false.
 It calls amountOfPairs(hand) to get the number of pairs that hand[] has.
 If the user has two pairs in their hand, then the function returns true.
 If not, the function returns false.
 */

bool containsTwoPair(const int hand[]) {
    if (amountOfPairs(hand) == 2) {
        return true;
    }
    return false;
}




/*
 This function returns true if the user's hand, the constant integer array hand[],
 has three cards of the same number, otherwise it returns false.
 It calls highestAmountOfSameCard(hand) to get the highest amount of cards that
 have the same number in hand[].
 If the highest amount of cards that have the same number is three in hand[], then
 the function returns true.
 If not, the function returns false.
 */

bool containsThreeOfaKind(const int hand[]) {
    if (highestAmountOfSameCard(hand) == 3) {
        return true;
    }
    return false;
}



/*
 This function returns true if the cards in the user's hand, the constant integer array hand[],
 have a difference of one in between each two adjacent cards, otherwise it returns false.
 It checks if in the event that the first card of hand[] is incremented by one, whether it will equal
 to the second card of the hand[]. It does so for each adjacent card in hand[].
 And if the case that every one of the adjacent cards have a difference of one between them,
 then the function returns true.
 If not, the function returns false.
 */

bool containsStraight(const int hand[]) {
    if (hand[0] + 1 == hand[1] && hand[1] + 1 == hand[2] && hand[2] + 1 == hand[3] && hand[3] + 1 == hand[4]) {
        return true;
    }
    return false;
}



/*
 This function returns true if the user's hand, the constant integer array hand[],
 has three cards of the same number and has two pairs, otherwise it returns false.
 It calls highestAmountOfSameCard(hand) to get the highest amount of cards that
 have the same number in hand[] and it also calls amountOfPairs(hand) to
 get the number of pairs in hand[].
 If the highest amount of cards that have the same number is three in hand[]
 and if the number of pairs is two in hand[], then the function returns true.
 If not, the function returns false.
 */

bool containsFullHouse(const int hand[]) {
    if (highestAmountOfSameCard(hand) == 3) {
        if (amountOfPairs(hand) == 2) {
            return true;
        }
    }
    return false;
}



/*
 This function returns true if the user's hand, the constant integer array hand[],
 has four cards of the same number, otherwise it returns false.
 It calls highestAmountOfSameCard(hand) to get the highest amount of cards that
 have the same number in hand[].
 If the highest amount of cards that have the same number is four in hand[],
 then the function returns true.
 If not, the function returns false.
 */

bool containsFourOfaKind(const int hand[]) {
    if (highestAmountOfSameCard(hand) >= 4) {
        return true;
    }
    return false;
}


/*
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 8
 Card 4: 2
 Card 5: 7
 Two Pair!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 8
 Card 2: 7
 Card 3: 4
 Card 4: 6
 Card 5: 5
 Straight!
 
 Enter five numeric cards, no face cards. Use 2 - 9.
 Card 1: 9
 Card 2: 2
 Card 3: 3
 Card 4: 4
 Card 5: 5
 High Card!
 */