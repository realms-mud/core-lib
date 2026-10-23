//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Draw Conditioning", "Condition the back for "
        "repeated draws: +6 maximum stamina while wielding a primary bow.",
        15, 1, "archers-footing", "archery");
    addSpecification("bonus stamina points", 6);
}
