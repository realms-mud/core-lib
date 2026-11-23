//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Halen");
    short("Halen, a quay loader");
    description("Halen's copper hair is clipped close, and blue eyes "
        "watch the gangplank. He is brave and strong-willed.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("fisher", 5);
    addTrait("/lib/instances/traits/eyes/blue.c");
    addTrait("/lib/instances/traits/hair/copper.c");
    addTrait("/lib/instances/traits/personality/brave.c");
    addTrait("/lib/instances/traits/personality/strong-willpower.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "halenConversation.c");
}
