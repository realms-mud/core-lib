//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Miren");
    short("Miren, a wool sorter");
    description("Miren grades the fleeces brought in from the commons and "
        "keeps the shed's tally for the Linwaeth market.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 4);
    addConversation(
        "/areas/eledhel/southwest-rural-five/characters/"
        "wool-workerConversation.c");
}
