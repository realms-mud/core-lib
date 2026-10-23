//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Guard", "Recover the heavy blade into "
        "a defensive line: +1 parry.", 10, 1, "longblade-footing", "odachi");
    addSpecification("bonus parry", 1);
}
