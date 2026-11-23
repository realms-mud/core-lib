//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Melach");
    addAlias("Lord Justice Melach");
    short("Lord Justice Melach, robed in black");
    description("Melach is an elderly judge with a deep baritone voice. "
        "His black robes are plain, and his attention is steady.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("priest", 20);
    addConversation(
        "/areas/eledhel/southern-city/halls-of-justice/characters/"
        "melachConversation.c");
}
