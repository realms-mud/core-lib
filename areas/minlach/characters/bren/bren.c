//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Bren");
    short("Bren, a militia sergeant");
    description("Bren's mail is maintained rather than polished. "
        "She watches recruits with patient attention and keeps a "
        "bundle of practice staves close to the drill-yard wall.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("city guard", 7);
    addConversation("/areas/minlach/characters/bren/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}
