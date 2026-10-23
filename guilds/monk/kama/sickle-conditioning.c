//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Conditioning", "Condition the kama arm "
        "for repeated cuts: +6 maximum stamina.",
        15, 1, "sickle-footing", "kama");
    addSpecification("bonus stamina points", 6);
}
