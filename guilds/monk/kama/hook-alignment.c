//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Hook Alignment", "Align the wrist before a "
        "committed kama release: +1 attack.", 15, 1, "hooked-grip", "kama");
    addSpecification("bonus attack", 1);
}
