//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Quieting Shot", "Spend one arrow to drain spell "
        "points through distracting pressure. It applies no silence.",
        20, "draw-pressure-theory", "archery", "damage spell points",
        18, 3, 16, 24, 0);
}
