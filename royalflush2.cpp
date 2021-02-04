#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <time.h>

using namespace std;
int point[52];
int a[52];

int score(int a, int b, int c, int d, int e)
{
    int R[5];
    int S[5], x[5];

    x[0]=a; x[1]=b; x[2]=c;  x[3]=d;  x[4]=e;

    for (int o=0; o<5; o++)
    {
        R[o] = x[o]%13;
        S[o] = x[o]/13;
    }

    // Sort the R array
    bool swapped = false;
    do
    {
        swapped = false;
        for(int o=0; o<4; o++)
        {
            if(R[o] > R[o+1])
            {
                int temp = R[o];
                R[o] = R[o+1];
                R[o+1] = temp;
                swapped = true;
            }
        }
    }
    while(swapped == true);

    int score= 0;
    // Check for a straight:
    if(R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1)
    {
        cout << "\nYou got a Straight" << endl;
        score=(score+19);
    }
    else
    {
        score=(score+0);
    }

    // Check first 5 cards for any pair
    if(R[0] == R[1] || R[1]==R[2] || R[2]==R[3] || R[3]==R[4])
    {
        // check for twopair
        if(R[0]==R[1]&&R[2]==R[3]||R[1]==R[2]&&R[3]==R[4]||R[0]==R[1]&&R[3]==R[4])
        {
            cout << "\nYou got a Twopair" << endl;
            score=(score+17);
        }
        // check for 3 of a kind
        if(R[0] == R[1] == R[2] || R[1] == R[2] == R[3] || R[2] == R[3] == R[4])
        {
            cout << "\nYou got a 3 of a kind" << endl;
            score=(score+18);
        }
        // Check for 4 of a kind
        if(R[0] == R[1] == R[2] == R[3] || R[1] == R[2] == R[3] == R[4])
        {
            cout << "\nYou got a 4 of a kind" << endl;
            score=(score+22);
        }
        else
        {
            cout << "\nYou got a Pair" << endl;
            score=(score+16);
        }
    }
    else
    {
        score=(score+0);
    }

    // Check for a flush (all the same suit)
    if(S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4])
    {
        cout << "\nYou got a Flush" << endl;
        score=(score+20);
    }
    else
    {
        score=(score+0);
    }

    // Check for straight flush
    if(S[0] == S[1] && S[1]==S[2] && S[2]==S[3] && S[3]==S[4])
    {
        if(R[1]==R[0]+1 && R[2]==R[1]+1 && R[3]==R[2]+1 && R[4]==R[3]+1)
        {
            cout << "\nYou got a Straight Flush" << endl;
            score=(score+23);
        }
        else
        {
            score=(score+0);
        }
    }

    // check for royal flush

    // Check for full house
    if(R[0] == R[1] == R[2] && R[3] == R[4] || R[0] == R[1] && R[2] == R[3] == R[4])
    {
        cout << "\nYou got a Full House" << endl;
        score = (score + 21);
    }
    else
    {
        score=score+0;
    }
 
}
void shuffle(int deck[], int pos)
{ 
	if (52 - pos < 2) return;

    int rnd = pos + 1 + rand() % (52 - pos - 1);
	int temp;
	temp= deck[pos];
	deck[pos]=deck[rnd];
	deck[rnd]=temp;
  shuffle(deck, pos + 1);
}

int main()
{
    srand(time(0));
    int deck[52];
    int i;
    string suitnames[4]={"spades", "hearts", "clubs", "diamonds"};
    string ranknames[13]={"ace", "king", "queen", "jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
	cout<<"\t\t$$$$ LET'S PLAY ROYAL FLUSH/POKER $$$$\n\n";
	cout<<"The shuffled deck is:\n\n";
     // create a unique deck, with cards in order
    for(i=0; i<52; i++)
    {
        deck[i] = i;
    }

    // function to shuffle the deck
	shuffle(deck,0);

    // print all the cards
    for(i=0; i<52; i++)
    {
        int suitnumber = deck[i] / 13;
        int rank = deck[i] % 13;
        cout <<i<<") "<< ranknames[rank] << " of " << suitnames[suitnumber]<< "\n";
    }
    cout << endl;


    for(i=0; i<52; i++)
    {
        int temp = deck[i];
        deck[i]=a[i];
        a[i]=temp;
    }


    int f;
    cout << "your card :"<< endl;
    f=0;
    while(f<26)
    {
        cout << f << ". ";
        int suitnumber = a[f] / 13;
        int rank = a[f] % 13;
        cout << ranknames[rank] << " of " << suitnames[suitnumber]<< "\n";
        f=f+5;
    }

    int n;
    cout << "do you want to replace your card ? [type 1 for yes, 0 for no]" << endl;
    cin >> n;
    switch (n)
    {
        case 1:
        cout << "Which card do you want to replace?[insert the number]: ";
        int o;
        cin >> o;
        int suitnumber = a[o] / 13;
        int rank = a[o] % 13;
        cout << "You want to replace " << ranknames[rank] << " of " << suitnames[suitnumber]<< "\n";
        int temp = a[o];
        a[o] = a[26];
        a[26] = temp;
        cout <<"Your card now: " << endl;
        o=0;
        while(o<26)
        {
            int suitnumber = a[o] / 13;
            int rank = a[o] % 13;
            cout << ranknames[rank] << " of " << suitnames[suitnumber]<< "\n";
            o=o+5;
        }
    }
    cout<<"The results are as follows: \n";

    cout << "Your score : " << score(a[0], a[5], a[10], a[15], a[20]) << endl << endl;

    cout << "Score of P2 :"<< score(a[1], a[6], a[11], a[16], a[21]) << endl << endl;

    cout << "Score of P3 :"<< score(a[2], a[7], a[12], a[17], a[22]) << endl << endl;

    cout << "Score of P4 :"<< score(a[3], a[8], a[13], a[18], a[23]) << endl << endl;

	cout << "Score of P5 :"<< score(a[4], a[9], a[14], a[19], a[24]) << endl << endl;
    return 0;
}
