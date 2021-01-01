# Function Map

| Address | Function                                                              | File      |
| ------- | --------------------------------------------------------------------- | --------- |
| 199BC0  | void qsort(void *, size_t, size_t, int *(const void *, const void *)) | stdlib.h  |
| 19A5C8  | int rand(void)                                                        | stdlib.h  |
| 1A6BE8  | double pow(double, double)                                            | stdlib.h  |
| 1A82E0  | int SzGame_GetMenuNum(int index)                                      | szgame.h  |
| 1DD130  | Unit * SzDuel_GetCardInfo(int, int)                                   | szduel.h  |
| 1DF540  | Unit * SzDuel_GetUnit(int, int)                                       | szduel.h  |
| 1E0290  | int SzDuel_GetUnitAP(int, int, bool)                                  | szduel.h  |
| 1E02F0  | int SzDuel_GetUnitAP2(Unit *, bool)                                   | szduel.h  |
| 1E0370  | int SzDuel_GetUnitDP(int, int, bool)                                  | szduel.h  |
| 1E03D0  | int SzDuel_GetUnitDP2(Unit *, bool)                                   | szduel.h  |
| 1E0690  | int SzDuel_GetUnitConstKind(int, int)                                 | szduel.h  |
| 1E0700  | int SzDuel_GetUnitKind(int, int)                                      | szduel.h  |
| 1E0830  | int SzDuel_GetUnitAttr(int, int)                                      | szduel.h  |
| 1E08F0  | int SzDuel_GetUnitLevel(int, int, bool)                               | szduel.h  |
| 1E0950  | int SzDuel_GetUnitLevel2(Unit *, bool)                                | szduel.h  |
| 1E0B70  | Effect * SzDuel_GetUnitEffect(int, int, int)                          | szduel.h  |
| 1E0C00  | bool SzDuel_GetUnitLeaderAbility(int, int, LeaderAbility, int *)      | szduel.h  |
| 1E0C70  | bool SzDuel_GetUnitLeaderAbility2(Unit *, LeaderAbility, int *)       | szduel.h  |
| 1E0C80  | bool SzDuel_GetUnitLeaderAbility3(Unit *, LeaderAbility, int *, bool) | szduel.h  |
| 1E1030  | int SzDuel_GetUnitCardNo(int, int)                                    | szduel.h  |
| 1E1090  | int SzDuel_GetUnitLoc(int, int)                                       | szduel.h  |
| 1E13C0  | int SzDuel_GetUnitSummonOrder(int, int)                               | szduel.h  |
| 1E2100  | bool SzDuel_GetUnitStatus(int, int, int)                              | szduel.h  |
| 1E22B0  | int SzDuel_GetField(int, int)                                         | szduel.h  |
| 1F2980  | int SzModel_GetModelType(int)                                         | szmodel.h |
| 215D30  | int SzData_GetRank(int, int)                                          | szdata.h  |
| 2494D0  | int TaEnc_GetRandomElf(void)                                          | taenc.h   |
| 24C780  | int ConvUnitIDtoFlagList(int, int, int)                               | global.h  |
| 24C910  | void TaUtil_GetUnitLst(int, SideComp, unsigned short *)               | tautil.h  |
| 24DD80  | bool Ta_SideMatch(int, int, SideComp)                                 | ta.h      |
| 24DE70  | int Ta_GetCurrentSide(int, int)                                       | ta.h      |
| 250360  | int Ta_IsUnitControl(int, int)                                        | ta.h      |
| 250370  | int Ta_IsUnitControl2(Unit *)                                         | ta.h      |
| 250740  | Effect * Ta_GetUnitEffect(int, int, int)                              | ta.h      |
| 250860  | int GetCap(int, int)                                                  | global.h  |
| 2508D0  | int GetParCap(int)                                                    | global.h  |
| 266C70  | int Ta_SearchUncTypeNaturalEffectUser(int, int)                       | ta.h      |
| 266DF0  | int Ta_SearchUncTypeNaturalEffectUserNum(int)                         | ta.h      |
| 266F70  | int Ta_SearchUncTypeNaturalEffectUserNumWithSide(int, int)            | ta.h      |
| 271740  | bool Ta_IsLDAbl(LeaderAbility, int)                                   | ta.h      |
| 271950  | bool Ta_IsSquareRange(int, int, int, int, int)                        | ta.h      |
| 271A40  | bool Ta_IsLDRange(int, int, int)                                      | ta.h      |
| 271AF0  | int Ta_GetLDParamOfs2(Unit *, int, int)                               | ta.h      |
| 271C90  | bool Ta_IsLD_PDownObj(int, Kind)                                      | ta.h      |
| 271F00  | bool Ta_IsLDRangeAvilityFromLoc(int, int, Kind, LeaderAbility)        | ta.h      |
| 27C670  | int TaLogic_GetUnitCtlLstLen(unsigned short *)                        | talogic.h |
