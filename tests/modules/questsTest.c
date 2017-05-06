//*****************************************************************************
// Copyright (c) 2017 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/tests/framework/testFixture.c";
#include "/lib/include/inventory.h"

object Quests;

/////////////////////////////////////////////////////////////////////////////
void Setup()
{
    Quests = clone_object("/lib/realizations/player");
    Quests->Name("Bob");
}

/////////////////////////////////////////////////////////////////////////////
void CleanUp()
{
    destruct(Quests);
}

/////////////////////////////////////////////////////////////////////////////
void IsValidRaceReturnsTrueForElf()
{
    ExpectTrue(Quests->isValidRace("elf"), "elf is a valid race");
}