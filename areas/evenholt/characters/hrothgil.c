//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Hrothgil");
    short("Hrothgil, the stablemaster");
    description("Hrothgil handles the horses with a veteran's calm "
        "and an exacting eye. He has served the household for years "
        "and is usually awake before the first light.");

    Gender("male");
    Race("human");
}
