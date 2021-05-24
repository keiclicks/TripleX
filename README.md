# TripleX
## A Simple C++ game (to be played on console).

### Game Story :

> You've stubled upon an old box that's been locked for ages.

> You need to enter 3 correct codes to Continue.

> You will receive everything that's inside the box!

#### Variables:

| Game Variable        | Values |
| -------------------- |:------:|
| Starting Difficulty  | 1      |
| Maximum Difficulty   | 5      |
| Total Attempts       | 3      |

Random Numbers are generated using : 
```CPP
srand(time(NULL));
rand() % DifficultyLevel + DifficultyLevel;
```
