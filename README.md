# TripleX
## A Simple C++ game (to be played on console).

### Game Story :

> You've stumbled upon an old box that's been locked for ages.

> You need to enter 3 correct codes to Continue.

> You will receive everything that's inside the box!

#### Variables:

| Game Variable        | Values |
| -------------------- |:------:|
| Starting Difficulty  | 1      |
| Maximum Difficulty   | 5      |
| Total Attempts       | 3      |

* Random Numbers are generated using : 
```CPP
srand(time(NULL));
rand() % DifficultyLevel + DifficultyLevel;
```

* Screenshots:

Title                                                                                            |  Level Failed
:------------------------------------------------------------------------------------------------:|:-----------------------------------------------------------:
![Title](https://raw.githubusercontent.com/keiclicks/TripleX/main/preview/Level1.png "Level-1")  |  ![LevelFailed](https://raw.githubusercontent.com/keiclicks/TripleX/main/preview/LevelFailed.png "Level-Failed")

