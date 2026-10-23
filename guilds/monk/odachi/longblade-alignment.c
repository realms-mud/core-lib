//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Alignment", "Direct the odachi's weight "
        "through the intended line: +1 attack.", 15, 2,
        "longblade-grip", "odachi");
    addSpecification("bonus attack", 1);
}
