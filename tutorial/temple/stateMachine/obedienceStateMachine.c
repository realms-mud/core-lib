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
        setName("The Test of Obedience");
        setType("primary");
        setDescription("In order to retrieve the Orb of Obedience, I have been "
            "tasked with completing something called the 'Test of Obedience'");

        addState("entered room", "I entered a room that appears to have "
            "been hewn out of solid amethyst.");

        addState("starting the test", "I found a strange rune on the floor.");
        addTransition("entered room", "starting the test", "gotRuneFromFloor");

        addState("resistance rune placed", "I was able to decipher a poem on a "
            "wall of runes. Several phrases are missing from it. The rune I "
            "found fit perfectly in one of the gaps.");
        addTransition("starting the test", "resistance rune placed", "resistanceRunePlaced");
        addEntryAction("resistance rune placed", "spawnUhrdalen");

        addState("uhrdalen left", "I pissed off an over-sensitive wraith. "
            "So... that's a thing and apparently I've hopelessly screwed up "
            "this quest. In the future, perhaps I should learn tact. Nah... "
            "piss off wraith. I hope you rot.");
        addTransition("resistance rune placed", "uhrdalen left", "uhrdalenLeft");
        addFinalState("uhrdalen left", "failure");

        addState("first test", "When I placed the rune, an ethereal being "
            "named 'Uhrdalen' spoke to me and assigned me the task of "
            "completing the poem on the wall of runes.");
        addTransition("resistance rune placed", "first test", "startFirstTest");

        setInitialState("entered room");
        startStateMachine();

        registerEventHandler("spawnUhrdalen");
    }
}

/////////////////////////////////////////////////////////////////////////////
void spawnUhrdalen(object player)
{
    notify("spawnUhrdalen", player);
}
