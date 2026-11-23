//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aldoran");
    short("Prince Aldoran, Domestic of the Stables");
    description("Prince Aldoran checks the palace horses and "
        "the stable staff's preparations with a practiced eye.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 16);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/"
        "aldoranConversation.c");
}
