/*! \file */

#ifndef STRUCTS_H
#define STRUCTS_H

struct CardConstInfo {
    unsigned char kind;
    unsigned char kindOfs;
    unsigned char lvAttr;
    unsigned char deckCost;
    unsigned short effectId;
    unsigned short xaxId;
    /*! A bitset containing the default AP and some flags.
     *  apWithFlags & 0x1FFF is the default AP.
     *  apWithFlags & 0x2000 is if the card has an image in DATA/PICPACK.MRG.
     *  apWithFlags & 0x4000 is if the card's password will work.
     *  apWIthFlags & 0x8000 is if the card can be received from reincarnation.
     */
    unsigned short apWithFlags;
    /*! A bitset containing the default DP and some flags.
     *  dpWithFlags & 0x1FFF is the default DP.
     *  dpWithFlags & 0x2000 is if the card appears in slots normally.
     *  dpWithFlags & 0x4000 is if the card is a slot rare, with the exception
     *  of Brain Control. This is ignored for the special slot rares.
     *  dpWIthFlags & 0x8000 is not understood.
     */
    unsigned short dpWithFlags;
    unsigned char password[8];
};

/*! Represents a deck, either a player's three decks or the AI decks. */
struct DataDeck {
    unsigned short cards[40];
    unsigned short leader;
    unsigned short deckCost;
};

/*! This struct represents a monster or magic effect. See Monster Effects and
 *  Magic Effects for a list of effects in the game. */
struct Effect {
    /*! The top three bytes is the ID for the effect type. The bottom byte has
     *  unknown meaning. */
    unsigned int typeAndUnk;
    unsigned int data;
};

/*! This struct represents possible leader abilities. An ability is not present
 *  if the corresponding value is 0xFFFF. The order of the abilities does not
 *  match the values of the LeaderAbility enum. The order (and meaning of the
 *  values) are as follows:
 *
 *  0 - Hidden Card: ability is present if the value is nonzero
 *
 *  1 - Extra Slots: ability is present if the value is nonzero
 *
 *  2 - Destiny Draw: required rank is upper byte
 *
 *  3 - Unknown Ability: required rank is upper byte, extra data is lower byte
 *
 *  4 - LP Recovery: required rank is upper byte
 *
 *  5 - Increased Movement: required rank is upper byte
 *
 *  6 - Terrain Change: required rank is lower byte, extra data is upper byte
 *
 *  7 - Direct Damage Halved: required rank is upper byte
 *
 *  8 - Extended Support Range: required rank is upper byte
 *
 *  9 - Level Cost Reduction For Summoning Same Type: required rank is lower
 *  byte, extra data is upper byte
 *
 *  10 - Improved Resistance For Same Type Friendlies: required rank is upper
 *  byte
 *
 *  11 - Increased Strength For Same Type Friendlies: required rank is lower
 *  byte, extra data is upper byte
 *
 *  12 - Open Opponent's Card: required rank is upper byte
 *
 *  13 - Movement Boost For Same Type Friendlies: required rank is upper byte
 *
 *  14 - Spellbind Specific Enemy Type: required rank is upper byte
 *
 *  15 - Weaken Specific Enemy Type: required rank is lower byte, extra data is
 *  upper byte
 *
 *  16 - unused
 *
 *  17 - Destroy Specific Enemy Type: required rank is upper byte
 *
 *  18 - unused
 *
 *  19 - unused
 */
struct LeaderAbilities {
    unsigned short leaderAbilities[20];
}

/*! This union represents the effects of a unit. effects is for a card's normal
 *  effects, leaderAbilities are used for leaders. */
union CardEffects {
    /*! The five effects for a card, in the order of:
     *
     *  0 - Attack
     *
     *  1 - Movement
     *
     *  2 - Nature Effect
     *
     *  3 - Flip
     *
     *  4 - Destruction
     */
    Effect effects[5];
    /*! The leader abilities for a deck leader. */
    LeaderAbilities leaderAbilities;
};

/*! This struct comes up in SzModel_GetModelType. */
struct Model {
    char unk_0x0[408];
    float unk_0x198;
    char unk_0x19C[68];
    char unk_0x1E0;
    char unk_0x1E1[18];
    /*! The model type returned by SzModel_GetModelType. */
    signed char type;
    char unk_0x1F4[27];
};

/*! This struct represents an owned copy of a card. */
struct OwnerCard {
    char unk_0x0[8];
};

/*! This struct represents the data in a SaveData about the owned copies of a
 *  card. */
struct CardInfo {
    OwnerCard copies[9];
    /*! Keeps track of the rank and some flags.
     *  rankWithFlags & 0x3FFF is the card's rank.
     *  rankWithFlags & 0x4000 is unknown.
     *  rankWithFlags & 0x8000 is if the card's password has been used.
     */
    unsigned short rankWithFlags;
    unsigned short exp;
};

/*! The struct represents a side's save file. */
struct SaveData {
    /*! Represents the owned cards. */
    CardInfo cards[854];
    unsigned short newcomers[5];
    char unk_0xFD92[2];
    DataDeck decks[3];
    unsigned char ownedAltArts[16];
    char unk_0xFEA0[252];
    unsigned char flags;
    char unk_0xFF9D[3];
};

/*! The main struct that represents a Deck Leader or card on the field. */
struct Unit {
    /*! The CardConstInfo referring to the original data for a card. */
    CardConstInfo* constInfo;
    void* unk_0x4;
    /*! The effects of unit. This is Effect[5] if the unit is a card, or
     *  unsigned short[20] if the unit is a deck leader. Note these effects can
     *  be changed by cards like Sword of Dragon's Soul and Crush Card. */
    CardEffects cardEffects;
    int unk_0x30;
    short unk_0x34;
    short unk_0x36;
    /*! The total boosts and debuffs being applied to the card's attack. Does
     *  not include terrain or leader effects, or Shapesnatch's effect. */
    short apBoost;
    /*! The total boosts and debuffs being applied to the card's defense. Does
     *  not include terrain or leader effects, or Shapesnatch's effect. */
    short dpBoost;
    /*! The card number of the unit (000 BEWD -> 853 Dark Magic Ritual). */
    unsigned short cardNo;
    /*! The kind of the unit. See Kind enum. */
    unsigned char kind;
    /*! The attribute of the unit. See Attribute enum. */
    unsigned char attr;
    /*! The column the unit is on, from 0 to 6 inclusive. */
    unsigned char locCol;
    /*! The row the unit is on, from 0 to 6 inclusive. */
    unsigned char locRow;
    char unk_0x42;
    char unk_0x43;
    /*! The side that normally controls the unit. */
    unsigned char side;
    /*! SzDuel_GetUnit checks if this is greater than 10. */
    unsigned char slot;
    unsigned char modelId;
    /*! Starts at 0 for the first summoned card, 1 for the next, etc. */
    unsigned char summonOrder;
    unsigned char lvRev;
    unsigned char curseRest;
    unsigned char spellRest;
    unsigned char delayCount;
    char unk_0x4C[4];
    unsigned char ctlGoalC;
    unsigned char ctlGoalM;
    char unk_0x52;
    unsigned char ctlRateM;
    unsigned char openRate;
    char unk_0x55;
    char unk_0x56;
    /*! A series of flags.
     *  status & 0b000001 is set if the unit has moved.
     *  status & 0b000010 is set when the unit is under opposition control, due
     *  to cards like Brain Control.
     *  status & 0b000100 is set if the card is showing as face-up.
     *  status & 0b001000 is set if the card is showing as being in defense
     *  position.
     *  status & 0b010000 is set if the card is actually face-up.
     *  status & 0b100000 is set if the card is actually in defense position.
     */
    unsigned char status;
    short unk_0x58;
    char unk_0x5A[2];
};

/*! The main struct that represents a square on the field. */
struct MapInfo {
    Unit* unit;
    char unk_0x04[16];
    unsigned short fieldRate;
    /*! Stores the terrain type. See Field enum. */
    unsigned char field;
    char unk_0x17[5];
}

#endif
