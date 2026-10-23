//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Footing", "Set a stable base beneath the "
        "long blade: +1 defense.", 10, 1, "longblade-grip", "odachi");
    addSpecification("bonus defense", 1);
}
