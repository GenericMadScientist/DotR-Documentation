/*! \file */

#ifndef SZGAME_H
#define SZGAME_H

#include "structs.h"

/** @brief Address 317388
 *
 *  Presumably stores various options.
 *  Entry 28 seems to store whether a side's leader abilities should be disabled
 *  (least significant bit is for Lancastrians, next bit is for Yorkists).
 */
extern int menuNums[37];

/** @brief Gets the specified element of menuNums.
 *
 *  If index is not between 0 and 36 inclusive, -1 is returned instead.
 *
 *  @param slot The index of the menu number to get
 *  @return menuNums[index]
 */
int SzGame_GetMenuNum(int index);

#endif
