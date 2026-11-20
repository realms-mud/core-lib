//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Seli");
    short("Seli, the dagger smith");
    description("Seli works at a small bench set apart from the main "
        "forge. Her tools are fine and her hands steady; even the "
        "smallest blade receives her full attention.");

    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 6);

    addConversation(
        "/areas/eledhel/southern-city/characters/seli/startingConversation.c");
}
