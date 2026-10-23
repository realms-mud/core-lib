//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Hooked Grip", "Support the kama's curved blade "
        "through recovery: +1 short sword.", 10, 1, "root", "kama");
    addSpecification("bonus short sword", 1);
}
