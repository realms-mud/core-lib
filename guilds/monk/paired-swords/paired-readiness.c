//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Readiness", "Coordinate the hands and feet "
        "under pressure: +1 dexterity.", 20, 2, "paired-footwork",
        "paired-swords");
    addSpecification("bonus dexterity", 1);
}
