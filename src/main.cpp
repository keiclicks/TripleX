/*
    * Starting difficulty level          : 1
    * Max difficulty level               : 5
    * Total attempts before self destruct: 3
*/

#include <iostream>
#include <ctime>
#include <string>

// Sets the default difficulty
void SetDefaultDifficulty (int &DifficultyReference) {
    DifficultyReference = 1;
}

void PressAnyKeyToContinue() {
    std:: cin.ignore(1000000000, '\n');
}

// Prompts user whether they're ready for the challenge
void EntryPrompt() {
    char UserSelection {};
    std:: cout << "You've stumbled upon an old box that's been locked for ages.";
    PressAnyKeyToContinue();
    std:: cout << "\nYou need to enter correct codes to Continue.";
    PressAnyKeyToContinue();
    std:: cout << "\nYou will receive everything that's inside the box!";
    PressAnyKeyToContinue();
    std:: cout << "\nAre you ready for the challenge? (Y/N) : ";
    std:: cin >> UserSelection;

    if (UserSelection != 'n' && UserSelection != 'N') {
        std:: cout << "\nGoodluck!\n" << std:: endl;
        PressAnyKeyToContinue();
    }
    else {
        std:: cout << "\nGoodbye.\n" << std:: endl;
        exit(0);
    }
}

void gameInstruction(const int *codeSumPtr, const int *codeProductPtr) {
    std:: cout << "\n>> There are 3 numbers in the code.\n";
    std:: cout << ">> The codes add-up to: " << *codeSumPtr << std:: endl;
    std:: cout << ">> The codes multiply to give: " << *codeProductPtr << std:: endl;
    std:: cout << "\nEnter your codes: ";
}

// Main game code goes here
void LoopGameAtDifficulty(int &DifficultyReference, int &AttemptReference) {
    const int CodeA = rand() % DifficultyReference + DifficultyReference;
    const int CodeB = rand() % DifficultyReference + DifficultyReference;
    const int CodeC = rand() % DifficultyReference + DifficultyReference;
    // std::cout << CodeA << " " << CodeB << " " <<CodeC;

    const int CodeSum     = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;

    gameInstruction(&CodeSum, &CodeProduct);

    // Player guess input
    int GuessA, GuessB, GuessC {};
    std:: cin >> GuessA >> GuessB >> GuessC;
    int GuessSum {GuessA + GuessB + GuessC};
    int GuessProduct {GuessA * GuessB * GuessC};

    // Answer validation
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        DifficultyReference++;
        std:: cout << "\nYour Codes are correct!!\n";
        if (DifficultyReference < 5) {
            std:: cout << "\nIncreasing difficulty level to.. " << DifficultyReference << std:: endl;
            PressAnyKeyToContinue();
        }
    }
    else if (AttemptReference > 1) {
        AttemptReference--;
        std:: cout <<"\nOops! Your codes are incorrect!\n";
        std:: cout <<"\nAttempt remaining : " << AttemptReference << std:: endl;
        PressAnyKeyToContinue();
    }
    else {
        std:: cout << "\nYou failed the challenge!\nThe box remains closed.\n\n";
        std:: cout << "Goodbye.\n";
        exit(0);
    }

}


int main() {

    srand(time(NULL)); // Create new random sequence based on time of day

    int DifficultyLevel {1};
    SetDefaultDifficulty(DifficultyLevel);
    const int MaxDifficulty {5};
    int TotalAttempts {3};
    EntryPrompt();
    std:: cout << "\nPlaying Game at difficulty "<< DifficultyLevel << std:: endl;
    PressAnyKeyToContinue();
    while (DifficultyLevel <= MaxDifficulty && TotalAttempts >= 1) {
        LoopGameAtDifficulty(DifficultyLevel,TotalAttempts);
        std:: cin.clear();   // clears the failbit
        std:: cin.ignore();  // discarding the buffer
    }

    std:: cout << "\n\nCongratulations! You open the box and find....\n";
    PressAnyKeyToContinue();
    std:: cout << "*** NOTHING!!! ***\n\n";
    return 0;
}
