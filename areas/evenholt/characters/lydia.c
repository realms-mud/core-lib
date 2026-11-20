//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Lydia");
    short("Lydia, the cook and housekeeper");
    description("Lydia keeps a cast-iron pot simmering and the "
        "kitchen in order. Her brisk warmth makes it plain that "
        "a cup of tea and a crust of bread are never a burden.");

    Gender("female");
    Race("human");
}
