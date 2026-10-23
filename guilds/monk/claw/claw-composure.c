//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Composure", "Choose deliberate openings "
        "instead of reckless flurries: +1 wisdom.",
        25, 1, "claw-guard", "claw");
    addSpecification("bonus wisdom", 1);
}
