//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/environment/environment.c";

/////////////////////////////////////////////////////////////////////////////
public void Setup()
{
    setTerrain("/lib/environment/terrain/forest.c");
    addFeature("/lib/environment/features/oakStand.c", "south");

    // First test
    addExit("west", "/lib/tutorial/rooms/onTheTrailPart1.c", "on the trail");
}

/////////////////////////////////////////////////////////////////////////////
public void init()
{
    add_action("resetEverything", "resetEverything");
}

/////////////////////////////////////////////////////////////////////////////
public int resetEverything(string command)
{
    write("Resetting all the things!\n");
    this_player()->resetQuest("lib/tutorial/stateMachines/introStateMachine.c");
    load_object("/lib/tutorial/characters/galadhel/galadhel.c")->resetConversationState();
    load_object("/lib/tutorial/characters/berenar/berenar.c")->resetConversationState();
    load_object("/lib/tutorial/characters/brendan/brendan.c")->resetConversationState();
    load_object("lib/tutorial/stateMachines/introStateMachine.c")->beginIntroduction(this_player());
    return 1;
}
