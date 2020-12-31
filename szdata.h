/*! \file */

#ifndef SZDATA_H
#define SZDATA_H

#include "structs.h"

/** @brief Address 32F790
 *
 *  Stores the save data for two players.
 */
extern SaveData saveData[2];

/** @brief Address 34F6D0
 *
 *  Stores the allegiance of the player.
 */
extern unsigned char roseFlag;

/** @brief Gets the rank of the specified card number for side.
 *
 *  If side is not 0 or 1, or if cardNo is 671 (Summoned Lord Exodia), or if
 *  cardNo does not lie between 0 and 682 inclusive, the function returns -1.
 *  The function reads from saveData.
 *
 *  @param side The side in question, 0 for Lancastrian, 1 for Yorkist
 *  @param cardNo The card ID for the card to get the rank of
 *  @return The rank of the card
 */
int SzData_GetRank(int side, int cardNo);

#endif
