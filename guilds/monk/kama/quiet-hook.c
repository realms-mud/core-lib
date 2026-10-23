//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Quiet Hook", "Pressure the opponent's concentration "
        "with one kama action, draining spell points without silence.",
        20, "binding-geometry", "kama", "damage spell points",
        20, 3, 16, 24, 0);
}
