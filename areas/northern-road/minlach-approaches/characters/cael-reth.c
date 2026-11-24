//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Cael Reth");
    short("Sergeant Cael Reth of the crown road watch");
    description("Cael is a maegenstryd man in a weather-darkened "
        "watch coat, with close-cropped black hair, amber eyes, "
        "and a fine scar across the bridge of his nose. A slate "
        "and a blunt piece of chalk hang at his belt beside a "
        "plain sword. His voice is firm without being loud.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 6);
    addTrait("/lib/instances/traits/personality/just.c");
    addTrait("/lib/instances/traits/personality/diligent.c");
    addConversation("/areas/northern-road/minlach-approaches/characters/"
        "cael-rethConversation.c");
}
