//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Footing", "Keep a stable base behind the "
        "kama's short reach: +1 defense.", 10, 1, "hooked-grip", "kama");
    addSpecification("bonus defense", 1);
}
