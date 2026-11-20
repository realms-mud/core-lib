//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Pera");
    short("Pera, a roadside produce seller");
    description("Pera tends a small produce stand beside the west road. "
        "Her baskets hold apples, onions, and late-season greens from "
        "nearby farms. She keeps a careful eye on the traffic passing "
        "between the city and the countryside.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);

    addConversation(
        "/areas/eledhel/central-rural/characters/pera/startingConversation.c");
}
