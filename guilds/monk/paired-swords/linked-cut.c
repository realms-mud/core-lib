//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Linked Cut", "Use the companion blade to support one "
        "deliberate katana strike; this is a single damage action.", 10,
        "paired-grip", "paired-swords", "damage hit points", 12, 0, 10, 12,
        "linked-lines");
}
