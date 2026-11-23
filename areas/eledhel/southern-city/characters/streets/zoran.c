//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Zoran");
    short("Zoran, a traveler from the inn");
    description("Zoran's sandy-brown hair falls over his green eyes. "
        "He is shy but open-minded about unfamiliar roads.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("innkeeper", 4);
    addTrait("/lib/instances/traits/eyes/green.c");
    addTrait("/lib/instances/traits/hair/sandy-brown.c");
    addTrait("/lib/instances/traits/personality/shy.c");
    addTrait("/lib/instances/traits/personality/openminded.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/streets/"
        "zoranConversation.c");
}
