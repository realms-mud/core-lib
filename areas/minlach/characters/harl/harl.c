//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Harl");
    short("Harl, the quarry foreman");
    description("Harl's thick boots are pale with stone dust. A "
        "measuring cord hangs from his belt beside a battered slate "
        "recording which crew went into which working.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation("/areas/minlach/characters/harl/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}
