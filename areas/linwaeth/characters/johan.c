//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Johan");
    short("Johan the Elder, Linwaeth's blacksmith");
    description("Johan's hands are darkened from years at the forge. "
        "He checks each tool before setting it down, and expects the "
        "same care from anyone who asks for his work.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("blacksmith", 7);
    addConversation("/areas/linwaeth/characters/johanConversation.c");
}
