//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Twin Edge", "Commit both blade lines to one demanding "
        "finishing action against one opponent.", 30, "paired-mastery",
        "paired-swords", "damage hit points", 30, 3, 20, 24,
        "twin-edge-theory");
}
