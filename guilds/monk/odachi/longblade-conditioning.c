//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Conditioning", "Condition the body to "
        "carry the odachi through recovery: +6 maximum stamina.",
        15, 2, "longblade-footing", "odachi");
    addSpecification("bonus stamina points", 6);
}
