//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Maelin");
    short("Maelin, the woodland forester");
    description("Maelin wears a patched green coat and carries a "
        "leather folder of permits. A few pale wood shavings cling "
        "to his cuffs, and his gaze often strays toward the tree line.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation("/areas/minlach/characters/maelin/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}
