//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Tinruth");
    short("Tinruth, the wargame instructor");
    description("Tinruth surveys the broken ground with a soldier's "
        "patience. The camp is spare and practical, built for long "
        "exercises among the hills, ravines and streams.");

    Gender("male");
    Race("high elf");
}
