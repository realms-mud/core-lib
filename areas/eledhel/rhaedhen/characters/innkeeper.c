//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Taleth");
    short("Taleth, keeper of Rhaedhen's road inn");
    description("Taleth serves drovers and travelers, and knows which "
        "country lanes remain passable after rain.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("farmer", 2);
}
