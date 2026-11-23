//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Hethor");
    short("Hethor, a maker of small blades");
    description("Hethor keeps the narrow shop quiet and orderly, with "
        "each dagger balanced and numbered before it leaves the rack.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "old-city-dagger-smithConversation.c");
}
