//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Companion Thrust", "Cover a single thrust with the "
        "other blade. Uses thrust damage rather than an extra attack.",
        20, "paired-footwork", "paired-swords", "damage hit points",
        18, 2, 12, 16, "paired-point-theory");
    addSpecification("damage type", "thrust");
}
