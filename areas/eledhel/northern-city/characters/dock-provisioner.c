//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Taviel");
    short("Taviel, a dockside provisioner");
    description("Taviel lays out produce and stored provisions for crews "
        "taking on supplies before a voyage.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/northern-city/characters/dock-provisionerConversation.c");
}
