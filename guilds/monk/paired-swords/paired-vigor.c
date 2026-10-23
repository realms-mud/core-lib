//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Vigor", "Sustain the coordination of two "
        "weapons: +5 maximum stamina.", 25, 3, "paired-vitality",
        "paired-swords");
    addSpecification("bonus stamina points", 5);
}
