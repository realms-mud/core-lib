//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/quests/questItem.c";

private object Uhrdalen;
private string HoldingRoom =
    "/areas/tol-dhurath/temple-interior/uhrdalen-holding.c";
private string UhrdalenShownForState = "";

/////////////////////////////////////////////////////////////////////////////
private void registerEventHandlers()
{
    registerEventHandler("spawnUhrdalen");
    registerEventHandler("placeUhrdalen");
    registerEventHandler("startSecondTest");
    registerEventHandler("startThirdTest");
    registerEventHandler("startFourthTest");
    registerEventHandler("startFifthTest");
    registerEventHandler("startSixthTest");
    registerEventHandler("startSeventhTest");
    registerEventHandler("startFinalPassage");
    registerEventHandler("startEighthTest");
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
    addEntryAction("first test", "hideUhrdalen");

    addState("second test", "I solved a magic square puzzle and found the "
        "rune of negation. Uhrdalen's voice echoed in my mind, urging me "
        "onward.");
    addTransition("first test", "second test", "startSecondTest");
    addEntryAction("second test", "showUhrdalenBetweenTests");

    addState("third test", "I arranged the echoes of Uhrdalen's memories "
        "and found the runes of weakness and strength. They are the same "
        "moment viewed from different sides.");
    addTransition("second test", "third test", "startThirdTest");
    addEntryAction("third test", "showUhrdalenBetweenTests");

    addState("fourth test", "I endured the crucible's flames and frost, "
        "accepting the pain to free both captive spirits. The runes of "
        "flame and frost were my reward.");
    addTransition("third test", "fourth test", "startFourthTest");
    addEntryAction("fourth test", "showUhrdalenBetweenTests");

    addState("fifth test", "I faced my own shadow in a mirror and learned "
        "that some battles are won by refusing to fight. The runes of "
        "fear and doom dissolved from the darkness.");
    addTransition("fourth test", "fifth test", "startFifthTest");
    addEntryAction("fifth test", "showUhrdalenBetweenTests");

    addState("sixth test", "I walked through Uhrdalen's memories and "
        "relived his tragic choices. The runes of wisdom and endurance "
        "came at the cost of understanding his pain.");
    addTransition("fifth test", "sixth test", "startSixthTest");
    addEntryAction("sixth test", "showUhrdalenBetweenTests");

    addState("seventh test", "I survived a gauntlet of spectral attacks, "
        "pushed past endurance, and felt death's loving caress. The "
        "rune of death was my prize for perseverance.");
    addTransition("sixth test", "seventh test", "startSeventhTest");
    addEntryAction("seventh test", "showUhrdalenForFinalTest");

    addState("poem complete", "Uhrdalen spoke with me one final time. "
        "He gave me the rune of envy - his envy of my freedom. The poem "
        "on the wall is now complete. I understand what obedience truly "
        "means: not blind submission, but the wisdom to know when to "
        "yield and when to stand.");
    addTransition("seventh test", "poem complete", "allRunesPlaced");
    addEntryAction("poem complete", "activateFinalPassage");

    addState("quest complete", "After completing the poem on the rune "
        "wall, the pedestals revealed one final passage. Deep within, "
        "I found a sealed chamber with a terrible mechanism - a blade, "
        "a vessel, and a withered heart. When I cut myself upon the "
        "blade, my blood broke the seal and unleashed Seilyndria, the "
        "Goddess of Destruction, from her millennia-long imprisonment. "
        "The Test of Obedience was never about my obedience - it was "
        "her design, crafted to find someone compliant enough to break "
        "her prison. She vanished into the world with promises of ruin, "
        "and I am left with the horror of what my obedience has "
        "wrought.");
    addTransition("poem complete", "quest complete", "questCompleted");
    addEntryAction("quest complete", "onQuestCompleted");
    addFinalState("quest complete", "success");

    setInitialState("entered room");
    startStateMachine();

    registerEventHandlers();
}

private mapping testEvents = ([
    "second test": "startSecondTest",
    "third test": "startThirdTest",
    "fourth test": "startFourthTest",
    "fifth test": "startFifthTest",
    "sixth test": "startSixthTest",
]);

/////////////////////////////////////////////////////////////////////////////
void spawnUhrdalen(object player)
{
    Uhrdalen = clone_object("/areas/tol-dhurath/characters/uhrdalen/uhrdalen.c");
    registerStateActor(Uhrdalen);

    if (objectp(player) && environment(player))
    {
        object room = environment(player);
        Uhrdalen->registerEvent(room);
        move_object(Uhrdalen, room);
        call_out("initiateUhrdalenConversation", 1, player);
    }

    notify("spawnUhrdalen", player);
}

/////////////////////////////////////////////////////////////////////////////
void hideUhrdalen(object player)
{
    if (objectp(Uhrdalen))
    {
        move_object(Uhrdalen, load_object(HoldingRoom));
    }
}

/////////////////////////////////////////////////////////////////////////////
void showUhrdalenBetweenTests(object player)
{
    if (member(testEvents, CurrentState))
    {
        notify(testEvents[CurrentState], player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public void placeUhrdalenForConversation(object player)
{
    if (!objectp(Uhrdalen) || !objectp(player) ||
        UhrdalenShownForState == CurrentState)
    {
        return;
    }

    UhrdalenShownForState = CurrentState;
    Uhrdalen->revealName();

    move_object(Uhrdalen, environment(player));

    player->characterState(Uhrdalen, CurrentState);
    call_out("initiateUhrdalenConversation", 1, player);
}

/////////////////////////////////////////////////////////////////////////////
void showUhrdalenForFinalTest(object player)
{
    notify("startSeventhTest", player);

    if (!objectp(Uhrdalen) || !objectp(player))
    {
        return;
    }

    Uhrdalen->revealName();
    player->characterState(Uhrdalen, "seventh test");
    notify("placeUhrdalen", player);
}

/////////////////////////////////////////////////////////////////////////////
void activateFinalPassage(object player)
{
    notify("startFinalPassage", player);
}

/////////////////////////////////////////////////////////////////////////////
void onQuestCompleted(object player)
{
    notify("startEighthTest", player);
}

/////////////////////////////////////////////////////////////////////////////
public void initiateUhrdalenConversation(object player)
{
    if (objectp(Uhrdalen) && objectp(player))
    {
        command("talk uhrdalen", player);
    }
}

/////////////////////////////////////////////////////////////////////////////
public object getUhrdalen()
{
    return Uhrdalen;
}
