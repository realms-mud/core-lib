//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Vitality", "Endure the risk of close "
        "quarters: +6 maximum hit points.",
        20, 1, "claw-conditioning", "claw");
    addSpecification("bonus hit points", 6);
}
