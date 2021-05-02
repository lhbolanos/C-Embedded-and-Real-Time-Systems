#include <cstdlib> 
#include <iostream>
#include <utility>
#include <bits/stdc++.h>
#include <vector>
#include <list>
#include <iterator>
#include <map>
#include <random>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <time.h>
#include <string>


using namespace std;

void showlist(list <string>);
bool checkList(list <string>, list <string>, string);
void showstack(stack <string>);
int randomfunc(int);
list <string> checkHand(list <string> &);
list <string> checkHand2(list <string> &);
list <string> fillHand(list <string> &);
bool emptyDeck();
void winner(int, int);
void showq(queue<string>);
string ai(list <string>);
void printSet(set<int, greater<int> > );

const int suits = 4;
int p1_score;
int p2_score;
bool check2 = false;
const int hand_sz = 7;

stack <string> deckCards;
queue<string> pOrder;

//set
set<int, greater<int> > s1;


//typedef map<int, pair<string, string> > Maptype;

int main(int argc, char** argv) {

    srand((unsigned) time(0));

    string choice;
    int type;



    cout << "        GGGGGGGGGGGGG                      FFFFFFFFFFFFFFFFFFFFFF  iiii                   hhhhhhh             " << endl;
    cout << "     GGG::::::::::::G                      F::::::::::::::::::::F i::::i                  h:::::h             " << endl;
    cout << "   GG:::::::::::::::G                      F::::::::::::::::::::F  iiii                   h:::::h             " << endl;
    cout << "  G:::::GGGGGGGG::::G                      FF::::::FFFFFFFFF::::F                         h:::::h             " << endl;
    cout << " G:::::G       GGGGGG   ooooooooooo          F:::::F       FFFFFFiiiiiii     ssssssssss    h::::h hhhhh       " << endl;
    cout << "G:::::G               oo:::::::::::oo        F:::::F             i:::::i   ss::::::::::s   h::::hh:::::hhh    " << endl;
    cout << "G:::::G              o:::::::::::::::o       F::::::FFFFFFFFFF    i::::i ss:::::::::::::s  h::::::::::::::hh  " << endl;
    cout << "G:::::G    GGGGGGGGGGo:::::ooooo:::::o       F:::::::::::::::F    i::::i s::::::ssss:::::s h:::::::hhh::::::h " << endl;
    cout << "G:::::G    G::::::::Go::::o     o::::o       F:::::::::::::::F    i::::i  s:::::s  ssssss  h::::::h   h::::::h" << endl;
    cout << "G:::::G    GGGGG::::Go::::o     o::::o       F::::::FFFFFFFFFF    i::::i    s::::::s       h:::::h     h:::::h" << endl;
    cout << "G:::::G        G::::Go::::o     o::::o       F:::::F              i::::i       s::::::s    h:::::h     h:::::h" << endl;
    cout << " G:::::G       G::::Go::::o     o::::o       F:::::F              i::::i ssssss   s:::::s  h:::::h     h:::::h" << endl;
    cout << "  G:::::GGGGGGGG::::Go:::::ooooo:::::o     FF:::::::FF           i::::::is:::::ssss::::::s h:::::h     h:::::h" << endl;
    cout << "   GG:::::::::::::::Go:::::::::::::::o     F::::::::FF           i::::::is::::::::::::::s  h:::::h     h:::::h" << endl;
    cout << "     GGG::::::GGG:::G oo:::::::::::oo      F::::::::FF           i::::::i s:::::::::::ss   h:::::h     h:::::h" << endl;
    cout << "        GGGGGG   GGGG   ooooooooooo        FFFFFFFFFFF           iiiiiiii  sssssssssss     hhhhhhh     hhhhhhh" << endl;


    cout << "\nGo Fish is a fun card game that uses a standard 52 card deck. It can be played with 2 people or" << endl;
    cout << "more" << endl;

    cout << "\nGame Rules" << endl;

    cout << "\nStarting The Game" << endl;

    cout << "\nThe first thing we do is deal cards to the players. For 2 players you deal each player 7 cards." << endl;
    cout << "If there are more than three players, deal 5 each. The rest is then spreead out in the" << endl;
    cout << "middle of the players face down. This can be called the pool or deck of cards." << endl;


    cout << "\nTaking a Turn" << endl;

    cout << "\nEach player gets a turn in clockwise orders (to the player's left)." << endl;

    cout << "\nDuring a turn the player asks another player if they have a particular rank of card. For example, the" << endl;
    cout << "player may ask Kathy if she has any nines. If Kathy has any nines, then she must give all of her nines" << endl;
    cout << "to the player. If Kathy doesn't any nines, then she says Go Fish." << endl;

    cout << "\nWhen you Go Fish you can take any card from the pool." << endl;

    cout << "\nIf the player gets the cards they asked for, either from the pool or from Kathy, then the player gets" << endl;
    cout << "another turn." << endl;


    cout << "\nIf the player gets all four suits of the same rank, then they can put the cards face up in front of them." << endl;
    cout << "For example, if you already had a nine of hearts, clubs, and spades; then you picked up the nine of " << endl;
    cout << "diamonds from the pool, you then get to place the set of nine cards down in front of you and you get " << endl;
    cout << "another turn." << endl;


    cout << "\nWinning the Game" << endl;

    cout << "\nGo Fish is over when one player runs out of cards or there are no more cards in the pool. The winner" << endl;
    cout << "is then determined by who has the most piles or suits of cards in front of them. " << endl;





    unsigned seed = 0;


    //deck
    map<int, string> deck;
    map<int, string>::iterator itr;




    //deck.insert({1, "Blank"});
    deck.insert({1, "Two"});
    deck.insert({2, "Three"});
    deck.insert({3, "Four"});
    deck.insert({4, "Five"});
    deck.insert({5, "Six"});
    deck.insert({6, "Seven"});
    deck.insert({7, "Eight"});
    deck.insert({8, "Nine"});
    deck.insert({9, "Ten"});
    deck.insert({10, "Jack"});
    deck.insert({11, "Queen"});
    deck.insert({12, "King"});
    deck.insert({13, "Ace"});

    /*  itr = deck.find(1);
      if (itr != deck.end())
          deck.erase(itr);

     */



    list <string> hand;
    list <string> hand2;



    for (int i = 0; i < 5; i++) {
        hand.push_front(deck.find((rand() % 13) + 1)->second);

        hand2.push_front(deck.find((rand() % 13) + 1)->second);
    }






    vector <string> deck2;

    for (int i = 0; i < suits; i++) {
        for (int j = 1; j < 14; j++) {
            deck2.push_back(deck.find(j)->second);
        }
    }
    cout << endl;


    random_shuffle(deck2.begin(), deck2.end());

    cout << endl;



    //This is where the vectors contents are put into the stack

    cout << "\nBeginning Deck of Cards... \n" << endl;

    int ct = 0;

    for (auto j = deck2.begin(); j != deck2.end(); ++j) {
        deckCards.push(deck2.at(ct));
        ct++;

    }


    //showstack(deckCards);
    cout << deckCards.size() << " Cards Total\n " << endl;

    //this is where stack contents put into lists, drawing from top of deck.

    list <string> hand_1;
    list <string> hand_2;

    fillHand(hand_1);
    fillHand(hand_2);

    cout << "Building player hands...\n" << endl;
    cout << deckCards.size() << " Cards Left " << endl;

    cout << "\nDealing hands to both players...\n";



    cout << "\nPlayer 1: " << endl;
    showlist(hand_1);

    cout << "Player 2: " << endl;
    showlist(hand_2);

    cout << endl;
    //showstack(deckCards);


    cout << "AI chose: " << ai(hand_2) << endl;

    cout << "Choose game type\n"
            << "Enter 1 to play against yourself and see both hands\n"
            << "Enter 2 to player against the computer\n";

    cin>>type;

    if (type == 1) {

        while (deckCards.size() != 0) {
            // Next step is checking for pairs and adding to a pile. If stack has == 0 cards, then game is over and whoever has most pairs wins. 

            cout << "Checking player hands for pairs....\n" << endl;

            cout << "Player 1: " << endl;
            checkHand(hand_1);
            cout << '\n';

            cout << "Player 2:\n";
            checkHand2(hand_2);
            cout << '\n';

            cout << "Done checking for pairs, showing current hands.....\n" << endl;
            showlist(hand_1);
            showlist(hand_2);

            cout << '\n' << deckCards.size() << " Cards Left " << endl;

            //cout << p1_score << "+" << p2_score << endl;


            // check hand for card, if present remove it. 
            cout << "Player 1: Name a card to remove from hand: " << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p1_score++;
                pOrder.push("Player 1 Pair");
            }

            cout << "\nPlayer 1: " << endl;
            showlist(hand_1);

            cout << "Player 2: " << endl;
            showlist(hand_2);


            cout << hand_1.size() << endl;

            //this checks the size of the hand and fills it aslong as it is less than 7 and the deck of Cards is greater than 0



            checkHand(hand_1);
            checkHand2(hand_2);


            showlist(hand_1);
            showlist(hand_2);
            cout << deckCards.size() << endl;
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;


            //Player 2s turn

            if (deckCards.size() == 0) {
                cout << "DECK EMPTY" << endl;
                break;
            }

            cout << "Player 2: Name a card to remove from hand: " << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p2_score++;
                pOrder.push("Player 2 Pair");
            }

            cout << "\nPlayer 1: " << endl;
            showlist(hand_1);

            cout << "Player 2: " << endl;
            showlist(hand_2);


            cout << hand_2.size() << endl;

            //this checks the size of the hand and fills it aslong as it is less than 7 and the deck of Cards is greater than 0


            cout << deckCards.size() << endl;
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;
        }

        //check the list for duplicate values. if node 1 doesnt match any other node, then proceed to node 2 and no need to check node 1 again. 1-2-3-4-5 :: node 1 = 1, no other node is 1. move to node 2 = 2, no need to check node 1 because we verified that node 2 != node 1, so only need to check forwards

        cout << "No cards in deck left!" << endl;



        while (hand_1.size() != 0 && hand_2.size() != 0) {
            cout << "Player 1: Name a card to remove from hand: " << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p1_score++;
                pOrder.push("Player 1 Pair");
            }

            showlist(hand_1);
            showlist(hand_2);
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;

            cout << "Player 2: Name a card to remove from hand: " << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p2_score++;
                pOrder.push("Player 2 Pair");
            }

            showlist(hand_1);
            showlist(hand_2);

            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;

        }
    }
    else if (type == 2) {

        cout << "You've chosen to play against the AI!\n";

        while (deckCards.size() != 0) {
            // Next step is checking for pairs and adding to a pile. If stack has == 0 cards, then game is over and whoever has most pairs wins. 

            cout << "Checking player hands for pairs....\n" << endl;

            cout << "Player 1: " << endl;
            checkHand(hand_1);
            cout << '\n';

            cout << "Player 2:\n";
            checkHand2(hand_2);
            cout << '\n';

            cout << "Done checking for pairs, showing current hand.....\n" << endl;
            showlist(hand_1);
            //showlist(hand_2);

            cout << '\n' << deckCards.size() << " Cards Left In Deck\n " << endl;

            //cout << p1_score << "+" << p2_score << endl;


            // check hand for card, if present remove it. 
            cout << "Player 1 turn: Got any....." << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p1_score++;
                pOrder.push("Player 1 Pair");
            }

            //cout << "\nPlayer 1: " << endl;
            //showlist(hand_1);

            //cout << "Player 2: " << endl;
            //showlist(hand_2);


            //cout << hand_1.size() << endl;

            //this checks the size of the hand and fills it aslong as it is less than 7 and the deck of Cards is greater than 0


            cout << "Making sure both players have full hands....\n";
            cout << "\nPlayer 1 -- ";
            checkHand(hand_1);
            cout << "\nAI(Player 2) -- ";
            checkHand2(hand_2);

            cout << "Showing current hand....\n";
            showlist(hand_1);
            //showlist(hand_2);
            //cout << deckCards.size() << endl;
            cout << '\n' << deckCards.size() << " Cards Left In Deck\n " << endl;
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;


            //Player 2s turn

            if (deckCards.size() == 0) {
                cout << "DECK EMPTY" << endl;
                break;
            }

            cout << "\nAI (Player 2) Turn: Got any...... ";
            //cin>>choice;
            choice = ai(hand_2);
            cout << choice << "'s?" << endl;




            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p2_score++;
                pOrder.push("Player 2 Pair");
            }

            //cout << "\nPlayer 1: " << endl;
            //showlist(hand_1);

            //cout << "Player 2: " << endl;
            //showlist(hand_2);


            //cout << hand_2.size() << endl;

            //this checks the size of the hand and fills it aslong as it is less than 7 and the deck of Cards is greater than 0


            //cout << deckCards.size() << endl;
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;
        }

        //check the list for duplicate values. if node 1 doesnt match any other node, then proceed to node 2 and no need to check node 1 again. 1-2-3-4-5 :: node 1 = 1, no other node is 1. move to node 2 = 2, no need to check node 1 because we verified that node 2 != node 1, so only need to check forwards

        cout << "No cards in deck left!" << endl;



        while (hand_1.size() != 0 && hand_2.size() != 0) {
            cout << "Player 1: Name a card to remove from hand: " << endl;
            cin>>choice;


            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p1_score++;
                pOrder.push("Player 1 Pair");
            }

            showlist(hand_1);
            showlist(hand_2);
            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;

            cout << "\nAI (Player 2) Turn: Got any...... ";
            //cin>>choice;
            choice = ai(hand_2);
            cout << choice << "'s?" << endl;




            //hand = checkList(hand, hand2, choice);

            if (checkList(hand_1, hand_2, choice)) {
                hand_1.remove(choice);
                hand_2.remove(choice);
                p2_score++;
                pOrder.push("Player 2 Pair");
            }

            showlist(hand_1);
            //showlist(hand_2);

            cout << "Player 1 pairs: " << p1_score << endl;
            cout << "Player 2 pairs: " << p2_score << endl;

        }

    }
    winner(p1_score, p2_score);
    cout << "\nQueue containing the order in which pairs were drawn/guessed by which player: " << endl;
    showq(pOrder);

    printSet(s1);

    return 0;
}

//maybe remove this

void printSet(set<int, greater<int> > s1) {
    set<int, greater<int> >::iterator itr;
    cout << "\nHighest pair count drawn in a single turn: \n";
    for (itr = s1.begin(); itr != s1.end(); itr++) {
        cout << *itr << " ";
    }
}

void winner(int a, int b) {

    if (a > b)
        cout << "Player 1 wins! With " << p1_score << " pairs";
    else
        cout << "Player 2 wins! With " << p2_score << " pairs";
}

bool emptyDeck() {

    bool test;

    if (deckCards.size() == 0) {
        cout << "DECK IS EMPTY" << endl;
        test = true;
        return test;
    } else {
        test = false;
        return test;
    }
}

//fill hand

list <string> fillHand(list <string> &a) {
    list <string> ::iterator it;


    if (deckCards.size() != 0) {

        for (int i = a.size(); i < hand_sz; i++) {
            a.push_front(deckCards.top());
            deckCards.pop();

            if (deckCards.size() == 0) {
                break;
            }
        }

        return a;
    } else
        return a;
}


//Check if pairs in hand

list <string> checkHand(list <string> &g) {



    list <string> ::iterator it;

    bool test = false;

    int ctr = 0;

    while (test == false) {

        for (it = g.begin(); it != g.end(); ++it) {

            string count1;
            count1 = *it;
            fillHand(g);

            if ((count(g.begin(), g.end(), count1)) == 2) {
                g.remove(count1);
                //cout << "Found a match." << endl;
                ctr++;
                //showlist(g);
                fillHand(g);
                //showlist(g);
                it = g.begin();
                //ctr++;
                //return g;
                //p1_score++;
                pOrder.push("Player 1 Pair");
                s1.insert(1);
            }
            if ((count(g.begin(), g.end(), count1)) == 3) {
                g.sort();
                g.unique();
                //g.remove(count1);
                //cout << "Found a match." << endl;
                ctr++;
                //showlist(g);
                fillHand(g);
                //showlist(g);
                it = g.begin();
                //ctr++;
                //return g;
                //p1_score++;
                pOrder.push("Player 1 Pair");
                s1.insert(3);
            }


        }
        test = true;
        p1_score = p1_score + ctr;
        cout << "Pairs found: " << ctr << endl;
    }

    return g;

}

list <string> checkHand2(list <string> &g) {



    list <string> ::iterator it;

    bool test = false;

    int ctr = 0;

    while (test == false) {

        for (it = g.begin(); it != g.end(); ++it) {

            string count1;
            count1 = *it;
            fillHand(g);

            if ((count(g.begin(), g.end(), count1)) == 2) {
                g.remove(count1);
                //cout << "Found a match." << endl;
                ctr++;
                //showlist(g);
                fillHand(g);
                //showlist(g);
                it = g.begin();
                //ctr++;
                //return g;
                //p1_score++;
                pOrder.push("Player 2 Pair");
                s1.insert(1);
            }
            if ((count(g.begin(), g.end(), count1)) == 3) {
                g.sort();
                g.unique();
                //g.remove(count1);
                //cout << "Found a match." << endl;
                ctr++;
                //showlist(g);
                fillHand(g);
                //showlist(g);
                it = g.begin();
                //ctr++;
                //return g;
                //p1_score++;
                pOrder.push("Player 2 Pair");
                s1.insert(3);
            }

        }
        test = true;
        p2_score = p2_score + ctr;
        cout << "Pairs found: " << ctr << endl;
    }

    return g;

}

//Go through list searching for 2 of first element, if true return true and return value of that element?
// Checks if element is in both lists

bool checkList(list <string> b, list <string> a, string chk) {
    list<string>::iterator findIter = find(b.begin(), b.end(), chk);
    list<string>::iterator findIter2 = find(a.begin(), a.end(), chk);

    if (findIter != b.end() && findIter2 != a.end()) {
        std::cout << "Element is present. " << std::endl;
        return checkList;

    } else
        std::cout << "Element is not present. " << std::endl;



    return !checkList;
}

void showlist(list <string> a) {
    list <string> ::iterator it;
    for (it = a.begin(); it != a.end(); ++it)
        cout << '\t' << *it;
    cout << '\n';
}

void showstack(stack <string> s) {
    while (!s.empty()) {
        cout << '\t' << s.top();
        s.pop();
    }
    cout << '\n';
}

int randomfunc(int j) {
    return rand() % j;
}

void showq(queue<string> gq) {
    queue<string> g = gq;
    while (!g.empty()) {
        cout << ", " << g.front();
        g.pop();
    }
    cout << '\n';
}

//Function takes a list<string> and initializes a string to be returned
//Picks a random number within the bounds of the size of the list
//Iterates through the passed list
//If the iterator == the random number chosen then list stops, 
//and the value at that point in the list is returned as an "answer"

string ai(list <string> a) {
    list <string>::iterator it;

    int count;
    int temp = (rand() % a.size()) + 1;
    string temp2 = " ";

    for (it = a.begin(); it != a.end(); ++it) {
        count++;
        if (count == temp) {
            return *it;
        }

    }
    return 0;
}
