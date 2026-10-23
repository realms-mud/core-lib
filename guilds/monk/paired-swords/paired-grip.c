//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Grip", "Maintain the katana's line while "
        "coordinating the companion blade: +1 hand and a half sword.",
        10, 1, "root", "paired-swords");
    addSpecification("bonus hand and a half sword", 1);
}
