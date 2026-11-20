//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tavren");
    short("Tavren, miller of House Aladain");
    description("Tavren checks the wheel's sound between measures "
        "of grain. A slate beside the mill door lists each delivery "
        "and the share returned to its household.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("miller", 4);
    addConversation(
        "/areas/eledhel/estates/aladain/characters/millerConversation.c");
}
