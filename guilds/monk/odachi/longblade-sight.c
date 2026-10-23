//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Sight", "Align the point without "
        "overcorrecting the heavy blade: +1 dexterity.", 20, 2,
        "longblade-distance", "odachi");
    addSpecification("bonus dexterity", 1);
}
