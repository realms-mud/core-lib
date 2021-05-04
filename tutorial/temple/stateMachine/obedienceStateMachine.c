//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

/////////////////////////////////////////////////////////////////////////////
private void registerEventHandlers()
{
    registerEventHandler("spawnUhrdalen");
    registerEventHandler("startFirstTest");
    registerEventHandler("startSecondTest");
    registerEventHandler("startThirdTest");
    registerEventHandler("startFourthTest");
    registerEventHandler("startFifthTest");
    registerEventHandler("startSixthTest");
    registerEventHandler("startSeventhTest");
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    setName("The Test of Obedience");
    setType("primary");
    setDescription("In order to retrieve the Heart of Decay, I have been "
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

    addState("second test", "When I did more stuff, other things happened.");
    addTransition("first test", "second test", "startSecondTest");

    addState("third test", "When I did more stuff, other things happened.");
    addTransition("second test", "third test", "startThirdTest");

    addState("fourth test", "When I did more stuff, other things happened.");
    addTransition("third test", "fourth test", "startFourthTest");

    addState("fifth test", "When I did more stuff, other things happened.");
    addTransition("fourth test", "fifth test", "startFifthTest");

    addState("sixth test", "When I did more stuff, other things happened.");
    addTransition("fifth test", "sixth test", "startSixthTest");

    addState("seventh test", "When I did more stuff, other things happened.");
    addTransition("sixth test", "seventh test", "startSeventhTest");

    setInitialState("entered room");
    startStateMachine();

    registerEventHandlers();
}

/////////////////////////////////////////////////////////////////////////////
void spawnUhrdalen(object player)
{
    notify("spawnUhrdalen", player);
}
