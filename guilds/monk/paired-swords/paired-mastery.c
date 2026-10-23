//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Mastery", "Recover behind either blade "
        "without losing the other's line: +2 parry.", 30, 4,
        "paired-composure", "paired-swords");
    addSpecification("bonus parry", 2);
}
