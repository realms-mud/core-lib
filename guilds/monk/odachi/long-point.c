//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Long Point", "Align the odachi's point for a single "
        "thrust against an opponent in the same room.", 20,
        "longblade-sight", "odachi", "damage hit points",
        26, 2, 18, 22, "longblade-point-theory");
    addSpecification("damage type", "thrust");
}
