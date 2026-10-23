//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Readiness", "Keep the claw hand supple "
        "between thrusts: +1 dexterity.", 20, 1, "claw-distance", "claw");
    addSpecification("bonus dexterity", 1);
}
