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

#endif
