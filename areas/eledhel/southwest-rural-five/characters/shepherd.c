//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Calen");
    short("Calen, a sheep farmer");
    description("Calen tends the flock's grazing rotation and watches "
        "for stray animals along the common.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation(
        "/areas/eledhel/southwest-rural-five/characters/"
        "shepherdConversation.c");
}
