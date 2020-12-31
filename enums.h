/*! \file */

#ifndef ENUMS_H
#define ENUMS_H

/*! Represents a monster attribute. */
enum Attribute {
    LIGHT = 0,
    DARK = 1,
    FIRE = 2,
    EARTH = 3,
    WATER = 4,
    WIND = 5
};

/*! Represents a type of terrain. */
enum Field {
    FOREST = 0,
    WASTELAND = 1,
    MOUNTAIN = 2,
    MEADOW = 3,
    SEA = 4,
    DARK = 5,
    TOON = 6,
    NORMAL = 7,
    LABYRINTH = 8,
    CRUSH = 9
};

/*! Represents a monster 'kind'. */
enum Kind {
    DRAGON = 0,
    SPELLCASTER = 1,
    ZOMBIE = 2,
    WARRIOR = 3,
    BEAST_WARRIOR = 4,
    BEAST = 5,
    WINGED_BEAST = 6,
    FIEND = 7,
    FAIRY = 8,
    INSECT = 9,
    DINOSAUR = 10,
    REPTILE = 11,
    FISH = 12,
    SEA_SERPENT = 13,
    MACHINE = 14,
    THUNDER = 15,
    AQUA = 16,
    PYRO = 17,
    ROCK = 18,
    PLANT = 19,
    IMMORTAL = 20,
    MAGIC = 32,
    POWER_UP = 64,
    TRAP_LIMITED_RANGE = 96,
    TRAP_FULL_RANGE = 128,
    RITUAL = 160
};

/*! Represents a leader ability. 2's purpose is unknown. */
enum LeaderAbility {
    EXTRA_SLOTS = 0,
    HIDDEN_CARD = 1,
    UNKNOWN_ABILITY = 2,
    DESTINY_DRAW = 3,
    INCREASED_MOVEMENT = 4,
    LP_RECOVERY = 5,
    DIRECT_DAMAGE_HALVED = 6,
    TERRAIN_CHANGE = 7,
    LEVEL_COST_REDUCTION_FOR_SUMMONING_SAME_TYPE = 8,
    EXTENDED_SUPPORT_RANGE = 9,
    INCREASED_STRENGTH_FOR_SAME_TYPE_FRENDLIES = 10,
    IMPROVED_RESISTANCE_FOR_SAME_TYPE_FRENDLIES = 11,
    MOVEMENT_BOOST_FOR_SAME_TYPE_FRENDLIES = 12,
    OPEN_OPPONENTS_CARD = 13,
    WEAKEN_SPECIFIC_ENEMY_TYPE = 14,
    SPELLBIND_SPECIFIC_ENEMY_TYPE = 15,
    DESTROY_SPECIFIC_ENEMY_TYPE = 16
};

/*! Represents the possible ranks a monster can have. */
enum LeaderRank {
    NCO = 0,
    SECOND_LT = 1,
    FIRST_LT = 2,
    CPT = 3,
    MAJ = 4,
    LTC = 5,
    COL = 6,
    BG = 7,
    RADM = 8,
    VADM = 9,
    ADM = 10,
    SADM = 11,
    SD = 12
};

/*! Represents a policy to use with matching sides. */
enum SideComp {
    NEVER_MATCH = 0,
    MATCH_IF_EQUAL = 1,
    MATCH_IF_NOT_EQUAL = 2,
    ALWAYS_MATCH = 3
};

#endif
