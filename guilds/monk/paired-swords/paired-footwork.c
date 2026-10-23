//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Footwork", "Keep both blades clear during "
        "evasive movement: +1 dodge.", 15, 2, "paired-distance",
        "paired-swords");
    addSpecification("bonus dodge", 1);
}
