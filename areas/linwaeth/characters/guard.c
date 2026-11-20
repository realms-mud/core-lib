//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Edris");
    short("Edris, a Linwaeth town guard");
    description("Edris watches the north gate and the road beyond it. "
        "A slate at the post records reports, not accusations.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("city guard", 6);
    addConversation("/areas/linwaeth/characters/guardConversation.c");
}
