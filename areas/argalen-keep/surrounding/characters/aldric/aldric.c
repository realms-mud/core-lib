//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("aldric");
    short("Aldric the innkeeper");
    description("Aldric is a stout, broad-shouldered man in his middle "
        "years with thinning brown hair and a welcoming smile. His "
        "hands are rough from years of hauling kegs and tending the "
        "hearth, and his apron is perpetually stained with ale. He "
        "has an easy laugh and a keen ear for gossip.");

    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("innkeeper", 5);

    addConversation(
        "/areas/argalen-keep/surrounding/characters/aldric/startingConversation.c");
}
