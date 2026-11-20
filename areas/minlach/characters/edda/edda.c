//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Edda");
    short("Edda, the garden herbalist");
    description("Edda's apron carries small cloth packets and a "
        "wooden plant marker. Her hands are stained with garden soil, "
        "but her drying shelves are meticulously clean.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation("/areas/minlach/characters/edda/startingConversation.c");
    registerEvent(load_object("/areas/minlach/quests/resident-events.c"));
}
