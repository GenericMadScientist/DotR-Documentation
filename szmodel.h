/*! \file */

#ifndef SZMODEL_H
#define SZMODEL_H

#include "structs.h"

/** @brief Address 31ABB0
 *
 *  Models 20 to 24 appear to be Lancastrian monsters, 25 to 29 Yorkist
 *  monsters, 30 Lancastrian Deck Leader, and 31 Yorkist Deck Leader.
 */
extern Model* models[84];

/** @brief Gets the type of the specified model.
 *
 *  If slot is not between 0 and 83 inclusive, or if models[slot] is the NULL
 *  pointer, then this function returns -1 instead.
 *
 *  @param slot The index of the pointer in models
 *  @return models[slot]->type
 */
int SzModel_GetModelType(int slot);

#endif
