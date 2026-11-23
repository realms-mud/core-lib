//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Mereth");
    short("Mereth, the museum curator");
    description("Mereth checks the display cases and explains the museum's "
        "local collections to the occasional visitor.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/northern-city/characters/museum-curatorConversation.c");
}
