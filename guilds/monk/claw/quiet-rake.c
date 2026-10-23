//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Quiet Rake", "Disrupt concentration with one "
        "close claw action, draining spell points without silence.",
        20, "grip-geometry", "claw", "damage spell points",
        18, 3, 14, 22, 0);
}
