//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Returning Hook", "Recover the kama into one "
        "powerful return cut, not an automatic second attack.",
        25, "reaping-cut", "kama", "damage hit points",
        28, 3, 18, 24, "hook-return-theory");
}
