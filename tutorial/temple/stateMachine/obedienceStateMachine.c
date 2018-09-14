//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
void reset(int arg)
{
    if (!arg)
    {
        questItem::reset(arg);
        setName("This needs a name");
        setDescription("This needs a description");
        addState("starting the test", "I found a strange rune on the floor in "
            "a room that appears to have been hewn out of solid amethyst.");

        addState("endurance rune placed", "I was able to decipher a poem on a "
            "wall of runes. Several phrases are missing from it. The rune I "
            "found fit perfectly in one of the gaps.");
        addTransition("starting the test", "endurance rune placed", "enduranceRunePlaced");
        addEntryAction("endurance rune placed", "spawnUhrdalen");
        addExitAction("endurance rune placed", "removeUhrdalen");

        addState("first test", "When I placed the rune, an ethereal being "
            "named 'Uhrdalen' spoke to me and assigned me the task of "
            "completing the poem on the wall of runes.");
        addTransition("endurance rune placed", "first test", "startFirstTest");

        setInitialState("first test");
        startStateMachine();
    }
}

/////////////////////////////////////////////////////////////////////////////
void spawnUhrdalen()
{

}

/////////////////////////////////////////////////////////////////////////////
void removeUhrdalen()
{

}
