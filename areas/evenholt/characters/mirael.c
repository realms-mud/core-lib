//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Mirael");
    short("Lady Mirael by the garden stream");
    description("Mirael sits beside the garden stream in a quiet "
        "moment of counsel. Her attention rests on the people around "
        "her, listening for what they cannot quite bring themselves "
        "to say.");

    Gender("female");
    Race("maegenstryd");
}
