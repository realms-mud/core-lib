//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Reservoir Discipline", "Hold a measured reserve without "
        "tension, adding six to the ordinary spell-point maximum.",
        10, 1, "/guilds/monk/pure-chi/economical-breath.c", ([]));
    addSpecification("bonus spell points", 6);
}
