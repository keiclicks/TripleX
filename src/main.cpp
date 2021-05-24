/*
    Starting difficulty level : 1
    Max difficulty level : 5
    Total attempts before self destruct : 3
*/

#include <iostream>
#include <ctime>
#include <string>

//Sets the default difficulty
void SetDefaultDifficulty (int *DifficultyPointer) {
    *DifficultyPointer = 1;
}

void PressAnyKeyToContinue() {
    std::cin.ignore(1000000000, '\n');
}

//Prompts user whether they're ready for the challenge
void EntryPrompt() {
    char UserSelection {};
    std::cout << "You've stubled upon an old box that's been locked for ages.";
    PressAnyKeyToContinue();
    std::cout << "\nYou need to enter correct codes to Continue.";
    PressAnyKeyToContinue();
    std::cout << "\nYou will receive everything that's inside the box!";
    PressAnyKeyToContinue();
    std::cout << "\nAre you ready for the challenge? (Y/N) : ";
    std::cin >> UserSelection;
    if (UserSelection != 'n' && UserSelection != 'N') {
        std::cout << "\nGoodluck!\n" << std::endl;
        PressAnyKeyToContinue();
    }
    else {
        std::cout << "\nGoodbye.\n" << std::endl;
        exit(0);
    }
}

//Main game code goes here
void LoopGameAtDifficulty(int *DifficultyPointer, int *AttemptPointer) {
    const int CodeA = rand() % (*DifficultyPointer) + (*DifficultyPointer);
    const int CodeB = rand() % (*DifficultyPointer) + (*DifficultyPointer);
    const int CodeC = rand() % (*DifficultyPointer) + (*DifficultyPointer);
//    std::cout << CodeA << " " << CodeB << " " <<CodeC;
    
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    
    std::cout << "\n>> There are 3 numbers in the code.\n";
    std::cout << ">> The codes add-up to: " << CodeSum << std::endl;
    std::cout << ">> The codes multiply to give: " << CodeProduct << std::endl;
    std::cout << "\nEnter your codes: ";
    
    //Player guess input
    int GuessA, GuessB, GuessC {};
    std::cin >> GuessA >> GuessB >> GuessC;
    int GuessSum {GuessA + GuessB + GuessC};
    int GuessProduct {GuessA * GuessB * GuessC};
    
    //Answer validation
    if (GuessSum == CodeSum && GuessProduct == CodeProduct) {
        (*DifficultyPointer)++;
        std::cout << "\nYour Codes are correct!!\n";
        if ((*DifficultyPointer) < 5) {
            std::cout << "\nIncreasing difficulty level to.. " << (*DifficultyPointer) << std::endl;
            PressAnyKeyToContinue();
        }
    }
    else if ((*AttemptPointer) > 1) {
        (*AttemptPointer)--;
        std::cout <<"\nOops! Your codes are incorrect!\n";
        std::cout <<"Difficulty has been reset.\n\nAttempt remaining : " << (*AttemptPointer) << std::endl;
        PressAnyKeyToContinue();
    }
    else {
        std::cout << "\nYou failed the challenge!\nThe box remains closed.\n\n";
        std::cout << "Goodbye.\n";
        exit(0);
    }
        
}


int main() {
    
    srand(time(NULL)); // Create new random sequence based on time of day
    
    int DifficultyLevel {1};
    SetDefaultDifficulty(&DifficultyLevel);
    const int MaxDifficulty {5};
    int TotalAttempts {3};
    EntryPrompt();
    std::cout << "\nPlaying Game at difficulty "<< DifficultyLevel << std::endl;
    PressAnyKeyToContinue();
    while (DifficultyLevel <= MaxDifficulty && TotalAttempts >= 1) {
        LoopGameAtDifficulty(&DifficultyLevel,&TotalAttempts);
        std::cin.clear();  //clears the failbit
        std::cin.ignore(); //discarding the buffer
    }
    
    std::cout << "\n\nCongratulations! You open the box and find....\n";
    PressAnyKeyToContinue();
    std::cout << "*** NOTHING!!! ***\n\n";
    return 0;
}