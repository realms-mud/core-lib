//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Derrik");
    short("Derrik, the cooper");
    description("Derrik sorts cask hoops by size beside a low "
        "workbench. A pale shaving clings to one boot, while "
        "freshly bound staves are stacked under a canvas cover "
        "with household marks facing out.");

    Gender("male");
    Race("human");

    addConversation(
        "/areas/eledhel/west-rural/characters/derrik/startingConversation.c");
}
