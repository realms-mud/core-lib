//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Races;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Races = clone_object("/lib/realizations/player");
    Races->Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Races);
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForElf()
{
    ExpectTrue(Races->isValidRace("elf"), "elf is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForDwarf()
{
    ExpectTrue(Races->isValidRace("dwarf"), "dwarf is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHalfling()
{
    ExpectTrue(Races->isValidRace("halfling"), "halfling is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForGnome()
{
    ExpectTrue(Races->isValidRace("gnome"), "gnome is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHalfElf()
{
    ExpectTrue(Races->isValidRace("half elf"), "half elf is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHalfOrc()
{
    ExpectTrue(Races->isValidRace("half orc"), "half orc is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForFaerie()
{
    ExpectTrue(Races->isValidRace("faerie"), "faerie is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHuman()
{
    ExpectTrue(Races->isValidRace("human"), "human is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHalfTroll()
{
    ExpectTrue(Races->isValidRace("half troll"), "half troll is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForHighElf()
{
    ExpectTrue(Races->isValidRace("high elf"), "high elf is a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsFalseForNonRaces()
{
    ExpectFalse(Races->isValidRace("blah"), "blah is not a valid race");
}

/////////////////////////////////////////////////////////////////////////////
void CanSetRaceToAValidRace()
{
    ExpectTrue(Races->Race("elf"), "race is set to elf");
    ExpectEq("elf", Races->Race(), "race returns elf");
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetRaceToAnUnplayableRace()
{
    ExpectFalse(Races->Race("minotaur"), "race is not set to minotaur");
    ExpectEq(0, Races->Race(), "race returns 0");
}

/////////////////////////////////////////////////////////////////////////////
void MonstersCanSetRaceToAnUnplayableRace()
{
    object monster = clone_object("/lib/realizations/monster.c");

    ExpectTrue(monster->Race("fuin-nedesar"), "race is set to fuin-nedesar");
    ExpectEq("fuin-nedesar", monster->Race());

    ExpectEq(2, sizeof(monster->getAttacks()));
    destruct(monster);
}

/////////////////////////////////////////////////////////////////////////////
void CanNotSetRaceToAnInvalidRace()
{
    ExpectFalse(Races->Race("weasel"), "race is not set to weasel");
    ExpectEq(0, Races->Race(), "race returns 0");
}

/////////////////////////////////////////////////////////////////////////////
void RacesExtraAttackReturnsCorrectValue()
{
    object racialDictionary = clone_object("/lib/dictionaries/racialDictionary");

    Races->Race("high elf");
    ExpectEq(racialDictionary->extraAttacks("high elf"), Races->racesExtraAttacks());
}

/////////////////////////////////////////////////////////////////////////////
void RacesResearchTreesReturnsCorrectValue()
{
    object racialDictionary = clone_object("/lib/dictionaries/racialDictionary");

    Races->Race("high elf");
    ExpectEq(racialDictionary->researchTrees("high elf"), Races->racesResearchTrees());
}

/////////////////////////////////////////////////////////////////////////////
void RacesAttributeBonusReturnsCorrectValue()
{
    Races->Race("high elf");
    ExpectEq(1, Races->racesAttributeBonus("strength"));
    ExpectEq(2, Races->racesAttributeBonus("intelligence"));
}

/////////////////////////////////////////////////////////////////////////////
void RacesBonusToReturnsCorrectValue()
{
    Races->Race("high elf");
    ExpectEq(3, Races->racesBonusTo("weapon smithing"));
    ExpectEq(50, Races->racesBonusTo("MaxSpellPoints"));
}

/////////////////////////////////////////////////////////////////////////////
void ApparentRaceCannotBeSetOnPlayer()
{
    Races->Race("high elf");
    ExpectSubStringMatch("high elf", Races->long());
    Races->apparentRace("human");
    ExpectSubStringMatch("high elf", Races->long());
}

/////////////////////////////////////////////////////////////////////////////
void ApparentRaceCanBeSetOnNPC()
{
    object monster = clone_object("/lib/realizations/monster.c");

    monster->Race("high elf");
    ExpectSubStringMatch("high elf", monster->long());
    monster->apparentRace("human");
    ExpectSubStringMatch("human", monster->long());
}
