

//System Libraries
#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <array>
#include <cstdlib>


using namespace std;






enum CrdCard {
    VISA, MASTER, AMERICAN_EXPRESS, DISCOVER, ALL

} crdCards;



void genCC(CrdCard card, char * cardNum) {

    int crdLength;



    if (card == VISA) {

        cardNum[0] = '4';
        crdLength = 16;

    } else if (card == MASTER) {

        cardNum[0] = '5';
        crdLength = 16;

    } else if (card == DISCOVER) {

        cardNum[0] = '6';
        crdLength = 16;

    } else if (card == AMERICAN_EXPRESS) {

        cardNum[0] = '3';
        crdLength = 15;

    } else if (card == ALL) {

        crdLength = 16;

    }


    int i;

    for (i = 1; i < crdLength; i++) {



        int number = rand() % 10;

        cardNum[i] = number + '0';

    }

    cardNum[i] = '\0';

}



void printCard(char * cardNum) {

    int i = 0;

    while (cardNum[i] != '\0') {

        cout << cardNum[i] << "";

        i++;
    }

}



bool validCC(char * cardIn, CrdCard card)
 {

    int crdLength;

    if (card == VISA || card == MASTER || card == DISCOVER || card == ALL) {
        crdLength = 16;
    } else if (card == AMERICAN_EXPRESS) {
        crdLength = 15;
    }

    int nSum = 0, isSecond = false;

    for (int i = crdLength - 1; i >= 0; i--) {

        int d = cardIn[i] - 'a';

        if (isSecond == true)

            d = d * 2;

        nSum += d / 10;
        nSum += d % 10;
        isSecond = !isSecond;

    }

    return (nSum % 10 == 0);

}



void flipDig(char * cardNum) {
    int num1 = rand() % 15;
    int num2 = rand() % 10;

    cardNum[num1] = num2 + '0';
}

int main()
 {

    srand(time(NULL));

    char card[20];

    CrdCard cardType = AMERICAN_EXPRESS;

    genCC(cardType, card);

    while (!validCC(card, cardType)) {
        genCC(cardType, card);
    }

    cout << "Credit card number: ";

    printCard(card);

    cout << endl;
    cout << "Card is : ";

    if (validCC(card, cardType)) {
        cout << "Valid Card\n";
    } else {
        cout << "Invalid Card\n";
    }

    int numberOfValid = 0;
    int numberOfInvalid = 0;

    cout << "\n\nTest: Flip a random digit and execute 10,000 tests\n ------------------------------------------------- \n";

    for (int i = 1; i <= 10000; i++) {
        flipDig(card);
        if (validCC(card, cardType)) {
            numberOfValid++;
        } else {
            numberOfInvalid++;
        }
    }

    cout << "\nValid cards: " << numberOfValid;
    cout << "\nInvalid cards: " << numberOfInvalid;
    cout<<"\n\n\nThank you!";



    return 0;

}
