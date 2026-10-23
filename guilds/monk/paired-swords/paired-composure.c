//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Composure", "Distinguish a real opening from "
        "a feint between the blades: +1 wisdom.", 25, 3,
        "paired-guard", "paired-swords");
    addSpecification("bonus wisdom", 1);
}
