//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Returning Rake", "Recover into one committed "
        "claw thrust. This is not an extra attack or a combination.",
        25, "crossing-rake", "claw", "damage hit points",
        26, 3, 16, 22, "rake-return-theory");
}
