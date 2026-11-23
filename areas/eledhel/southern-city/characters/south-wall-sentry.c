//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Kethran");
    short("Kethran, a sentry on the south wall");
    description("Kethran watches the road from the wall walk "
        "and listens for the gatehouse signal below.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("city guard", 5);
    addConversation(
        "/areas/eledhel/southern-city/characters/south-wall-sentryConversation.c");
}
