//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Wilem");
    short("Wilem of House Gundil");
    description("Wilem helps carry messages between the keep and village.");
    Gender("male");
    Race("human");
    SetUpPersonaOfLevel("farmer", 1);
}
