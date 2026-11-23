//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Ilyen");
    short("Ilyen, an acolyte of the Halls of Justice");
    description("Ilyen wears a simple acolyte's robe and tends the "
        "long table where judges and petitioners may share a meal.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("priest", 3);
    addConversation(
        "/areas/eledhel/southern-city/halls-of-justice/characters/"
        "acolyteConversation.c");
}
