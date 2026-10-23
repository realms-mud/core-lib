//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Sickle Point", "Drive the kama's point into one "
        "opening with a controlled thrust.",
        20, "sickle-readiness", "kama", "damage hit points",
        20, 2, 14, 18, "sickle-point-theory");
    addSpecification("damage type", "thrust");
}
