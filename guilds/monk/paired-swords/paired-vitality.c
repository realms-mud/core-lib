//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Vitality", "Condition yourself for sustained "
        "paired exchanges: +6 maximum hit points.", 20, 2,
        "paired-recovery", "paired-swords");
    addSpecification("bonus hit points", 6);
}
