//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Companion Grip", "Coordinate the offhand wakizashi "
        "without crowding the katana: +1 short sword.", 10, 1,
        "paired-grip", "paired-swords");
    addSpecification("bonus short sword", 1);
}
