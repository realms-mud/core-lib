//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Eryth");
    short("Eryth, a cooper");
    description("Eryth's chestnut hair is darkened with pitch, and "
        "brown eyes check each cask hoop. He is pragmatic and patient.");
    Gender("male");
    Race("dwarf");
    SetUpPersonaOfLevel("blacksmith", 4);
    addTrait("/lib/instances/traits/eyes/brown.c");
    addTrait("/lib/instances/traits/hair/chestnut-brown.c");
    addTrait("/lib/instances/traits/personality/pragmatic.c");
    addTrait("/lib/instances/traits/personality/patient.c");
    addConversation(
        "/areas/eledhel/southern-city/characters/docks/"
        "erythConversation.c");
}
