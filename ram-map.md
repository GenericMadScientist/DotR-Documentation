# RAM Map

| Address | Data                                 | Size   | File      |
| ------- | ------------------------------------ | ------ | --------- |
| 28F850  | unsigned long long seed              |      8 | stdlib.h  |
| 2C3338  | LeaderAbilities leaderAbilities[683] |  13660 | szduel.h  |
| 2C9DF0  | Effect monsterEffects[256][5]        |  10240 | szduel.h  |
| 2CC5F0  | Effect magicEffects[171]             |   1368 | szduel.h  |
| 317388  | int menuNums[37]                     |    148 | szgame.h  |
| 318280  | Unit units[3][11]                    |   3036 | szduel.h  |
| 318E60  | MapInfo mapInfo[7][7]                |   1372 | szduel.h  |
| 31ABB0  | Model *models[84]                    |    336 | szmodel.h |
| 32F790  | SaveData saveData[2]                 | 130880 | szdata.h  |
| 34F6D0  | unsigned char roseFlag               |      1 | szdata.h  |
