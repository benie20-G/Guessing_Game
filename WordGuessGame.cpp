
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <cctype>

using namespace std;

const int ARRAY_SIZE = 6; // Define the size of the arrays

// Function to get a word from the given array based on user input
const char *getWord(const char array[][20], int size)
{
    srand(static_cast<unsigned>(time(nullptr)));
    int index = rand() % size;
    // Check if the index is valid
    if (index >= 0 && index < size)
    {
        return array[index];
    }
    else
    {
        return "Invalid index";
    }
}

int main()
{

    char animals[ARRAY_SIZE][20] = {"Elephant", "Goat", "Cat", "Lion", "Wolf", "Leopard"};
    char teams[ARRAY_SIZE][20] = {"Football", "Devdynamos", "Real Madrid", "Arsenal", "Amavubi"};
    char districts[ARRAY_SIZE][20] = {"Gasabo", "Nyabihu", "Gatsibo", "Kicukiro", "Burera", "Muhanga"};
    char films[ARRAY_SIZE][20] = {"Blood sisters", "Dangerous", "Avengers", "Spiderman", "Mission", "Barbie"};
    char books[ARRAY_SIZE][20] = {"The Forth", "Romeo and Juliet", "Twin Troubles", "Love story", "Bible Learn"};

    char choice = 'y';
    bool won = false;

    while (choice != 'n')
    {

        cout << "Choose category of word you need?\n"
             << "1. Animals\n"
             << "2. Teams\n"
             << "3. Districts\n"
             << "4. Films\n"
             << "5. Books\n";
        int category;
        const char *word;
        if (cin >> category)
        {

            switch (category)
            {
            case 1:
                word = getWord(animals, ARRAY_SIZE);
                break;
            case 2:
                word = getWord(teams, ARRAY_SIZE);
                break;
            case 3:
                word = getWord(districts, ARRAY_SIZE);
                break;
            case 4:
                word = getWord(films, ARRAY_SIZE);
                break;
            case 5:
                word = getWord(books, ARRAY_SIZE);
                break;
            default:
                cout << "Invalid category\n";
                return false;
                break;
            }
        }
        else
        {
            cout << "you have to enter an integer";
            return false;
        }
        string option;
        int chances = 15;

        char guess[20];

        for (unsigned i = 0; i < strlen(word); i++)
        {
            guess[i] = '_';
        }
        guess[strlen(word)] = '\0'; 

        cout<<"You have "<<chances<<" Chances to guess a letter"<<endl;
        cout<<"To exit, type \"exit\" "<<endl;

        while (chances > 0)
        {

            cout <<chances<<"-> guess the letter: ";
            cin >> option;

            if (option == "exit")
            {
                break;
            }
            else
            {

                for (int i = 0; word[i] != '\0'; i++)
                {

                    if (tolower(word[i]) == option[0])
                    {
                        guess[i] = word[i];
                    }
                    if (word[i] == ' ')
                    {
                        guess[i] = ' ';
                    }
                    if (!guess[i] || guess[i] == '_')
                    {
                        guess[i] = '_';
                    }
                }

                for (unsigned j = 0; j < strlen(guess); j++)
                {
                    if (guess[j] == '_')
                    {
                        cout << "_ ";
                    }
                    else if (guess[j] == ' ')
                    {
                        cout << "  ";
                    }
                    else
                    {
                        cout << guess[j] << ' ';
                    }
                }
                cout << "\n\n";
            
                    bool match = true;
                    for (unsigned i = 0; i < strlen(word); i++)
                    {
                        if (guess[i] != word[i])
                        {
                            match = false;
                            break; // Exit the loop if a mismatch is found
                        }
                    }
                    if (match)
                    {
                        cout << "Congratulations! Your guess is correct.\n\n";
                        won = true;
                        chances = 0;
                    }
                
            }
            chances--;
        }
        if (!won)
        {
            cout << "Out of guesses!!\n\n";
            switch (category)
            {
            case 1:
                 cout<< "The animal was: "<<word<<endl<<"\n";
                break;
            case 2:
                cout<< "The team was:  "<<word<<endl<<"\n";
                break;
            case 3:
              cout<< "The district was:  "<<word<<endl<<"\n";
                break;
            case 4:
                 cout<< "The film was:  "<<word<<endl<<"\n";
                break;
            case 5:
              cout<< "The book was:  "<<word<<endl<<"\n";
                break;
            default:
                return false;
                break;
            }
         
        }

        cout << "Continue? y or n  : ";
        cin >> choice;
    }
    return 0;
}
