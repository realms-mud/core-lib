//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Yalwen");
    short("Yalwen, a lamp-oil seller");
    description("Yalwen guards a small crate of stoppered oil flasks "
        "on the busy avenue.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("grocer", 4);
    addConversation(
        "/areas/eledhel/central-city/characters/"
        "lamp-oil-sellerConversation.c");
}
