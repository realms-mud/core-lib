//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Dareth");
    short("Dareth, provisions seller at the southern quay");
    description("Dareth keeps travel provisions ready for crews "
        "and residents who work around the southern harbor.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 5);
    addConversation(
        "/areas/eledhel/southern-city/characters/dock-merchantConversation.c");
}
