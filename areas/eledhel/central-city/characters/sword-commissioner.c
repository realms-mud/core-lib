//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Gethen");
    short("Gethen, a courier awaiting a sword commission");
    description("Gethen has placed a careful order with Tirwen and "
        "checks the shop whenever his route brings him back to the ward.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("grocer", 3);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "sword-commissionerConversation.c");
}
