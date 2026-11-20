//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Nareth");
    short("Nareth, reeve of the Aladain village");
    description("Nareth keeps the village's crop tallies and water "
        "turns in a weather-stained book. The figures are plain, "
        "but each household's mark is entered carefully.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/estates/aladain/characters/reeveConversation.c");
}
