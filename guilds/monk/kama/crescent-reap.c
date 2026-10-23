//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Crescent Reap", "Commit the kama to one broad "
        "curved cut against a single opponent.",
        20, "reaping-lines", "kama", "damage hit points",
        24, 3, 16, 20, "crescent-geometry");
}
