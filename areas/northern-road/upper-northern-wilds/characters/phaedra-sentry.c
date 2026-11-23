//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD. All rights reserved.
//*****************************************************************************
virtual inherit "/lib/realizations/npc.c";

protected void Setup()
{
    Name("Phaedra outpost sentry");
    short("a Phaedra outpost sentry");
    description("The sentry watches the upper road and records travelers "
        "bound for Minlach or the northern passes.");
    Gender("female");
    Race("human");
    SetUpPersonaOfLevel("archer", 7);
}
