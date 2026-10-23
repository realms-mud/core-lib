//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Descending Shot", "Send one arrow down a steep "
        "line within the current room. This does not attack other rooms.",
        20, "draw-alignment", "archery", "damage hit points",
        26, 3, 18, 24, "falling-trajectory");
}
