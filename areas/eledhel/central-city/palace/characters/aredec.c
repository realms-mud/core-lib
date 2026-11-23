//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Aredec");
    short("Prince Aredec, commander of the Aegis Guard");
    description("Prince Aredec carries himself with formal "
        "discipline and watches the court with measured attention.");
    Gender("male");
    Race("maegenstryd");
    SetUpPersonaOfLevel("city guard", 18);
    addConversation(
        "/areas/eledhel/central-city/palace/characters/"
        "aredecConversation.c");
}
