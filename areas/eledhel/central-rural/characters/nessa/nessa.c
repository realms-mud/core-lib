//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Nessa");
    short("Nessa, the granary provisioner");
    description("Nessa wears a clean apron over patched sleeves. "
        "She moves between the counter and the raised storage racks, "
        "checking each sack's label against a carefully ruled ledger.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation("/areas/eledhel/central-rural/characters/"
        "nessa/startingConversation.c");
}
