/*! \file */

#ifndef GLOBAL_H
#define GLOBAL_H

/** @brief Return how a terrain supports a unit.
 *
 *  This function is the same as Do_CheckLandAgreement except if the unit is
 *  invalid it returns 0. Note that this function does not check if unit is NULL
 *  before dereferencing it.
 *
 *  @param field The terrain type
 *  @param unit The unit to check the compatibility of
 *  @return 0 for no affect, 1 for power up, 2 for power down
 */
int CheckLandAgreement(Field field, Unit* unit);

/** @brief Adds a unit to a flaglist.
 *
 *  A flaglist is a way of representing a flag for every unit. The lowest bit
 *  is the Yorkist Leader, going up to Yorkist unit 10, then Lancastrian Leader,
 *  going up to Lancastrian unit 10. This function copies flagList, sets the bit
 *  corresponding to (side, pos), then returns the new flaglist.
 *
 *  @param flagList The flaglist to add the unit to
 *  @param side The side of the unit to add
 *  @param pos The position of the unit to add
 *  @return The modified flaglist
 */
int ConvUnitIDtoFlagList(int flagList, int side, int pos);

/** @brief Return how a terrain supports a unit.
 *
 *  This function goes off unit->kind, except for Toon terrain in which case it
 *  goes off unit->cardNo. For non-Toon terrains, the effects are as follows:
 *
 *  Forest -> Power up Beast, Beast-Warrior, Insect, Plant, Pyro, power down
 *  Fiend
 *
 *  Wasteland -> Power up Dinosaur, Machine, Rock, Zombie, power down Aqua,
 *  Fish, Plant, Sea Serpent
 *
 *  Mountain -> Power up Dragon, Fairy, Thunder, Winged Beast, power down Zombie
 *
 *  Meadow -> Power up Beast-Warrior, Warrior, power down Spellcaster
 *
 *  Sea -> Power up Aqua, Fish, Sea Serpent, Thunder, power down Machine, Pyro
 *
 *  Dark -> Power up Fiend, Spellcaster, Zombie, power down Fairy
 *
 *  Normal -> No effect
 *
 *  Labyrinth -> No effect
 *
 *  Crush -> Power up Immortal
 *
 *  Note this function does not check if Unit is NULL before dereferencing it.
 *
 *  @param field The terrain type
 *  @param unit The unit to check the compatibility of
 *  @return 0 for no affect, 1 for power up, 2 for power down
 */
int Do_CheckLandAgreement(Field field, Unit* unit);

/** @brief Return the effect of using an equip.
 *
 *  If the equip will not work, the function returns 999. One thing to note is
 *  this function does not use the monster's type for determining if Violet
 *  Crystal works, and instead looks up EnchMatch for that like every other
 *  equip.
 *
 *  Otherwise the function returns the equip in the lower 14 bits, some info in
 *  the next 16, and the next bit is 1 if the result is a fusion. For fusions,
 *  the 16 bits of info is the card ID of the resulting monster. For other
 *  equips, the info represents the animation and is as follows:
 *
 *  536 -> normal equip animation
 *
 *  537 -> Riryoku animation
 *
 *  540 -> Crush Card animation
 *
 *  541 -> Paralyzing Potion animation
 *
 *  542 -> Cursebreaker animation
 *
 *  @param cardNo Monster card to apply the equip to
 *  @param equipNo Equip card to apply to the monster
 *  @return An int representing the result
 */
int Do_Chk_Enc(int cardNo, int equipNo);

/** @brief Bounds a value in a way depending on the cap.
 *
 *  If the cap is 6, 7, 500, 1500, or 9999, GetCap returns min(cap, value). If
 *  the cap is 0 or 1, GetCap returns max(cap, value). Otherwise 0 is returned.
 *
 *  @param cap The cap to apply
 *  @param value The value to cap
 *  @return The capped value
 */
int GetCap(int cap, int value);

/** @brief Clamps a stat between 0 and 9999 inclusive.
 *
 *  @param stat The stat to clamp
 *  @return min(max(stat, 0), 9999)
 */
int GetParCap(int stat);

#endif
