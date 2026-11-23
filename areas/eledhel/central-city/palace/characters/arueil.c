//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Arueil");
    short("Queen Arueil of Eledhel");
    description("Queen Arueil stands beside the royal dais, "
        "attentive to the proceedings in the hall.");
    Gender("female");
    Race("maegenstryd");
    addConversation(
        "/areas/eledhel/central-city/palace/characters/"
        "arueilConversation.c");
}
