//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Rilwen");
    short("Rilwen, keeper of Tirwen's orchard");
    description("Rilwen's sleeves smell faintly of pressed apples. "
        "A pruning knife hangs at her belt, kept sheathed while she "
        "works near the farmhouse.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 3);
    addConversation("/areas/eledhel/tirwen/characters/rilwen/"
        "startingConversation.c");
}
