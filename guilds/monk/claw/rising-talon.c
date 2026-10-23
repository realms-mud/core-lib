//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Rising Talon", "Drive the claw points upward "
        "through one opening against a single opponent.",
        20, "crossing-talons", "claw", "damage hit points",
        22, 3, 14, 18, "rising-talon-theory");
}
