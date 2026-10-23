//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Grip", "Support the odachi throughout a "
        "committed stroke: +1 two-handed sword.", 10, 1, "root", "odachi");
    addSpecification("bonus two-handed sword", 1);
}
