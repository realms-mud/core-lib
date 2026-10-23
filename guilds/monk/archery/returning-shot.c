//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Returning Shot", "Recover into one demanding "
        "follow-up release. One arrow is consumed, not returned.",
        25, "crosswind-geometry", "archery", "damage hit points",
        30, 3, 20, 26, "return-trajectory");
}
