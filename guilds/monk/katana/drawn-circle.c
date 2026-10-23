//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Drawn Circle", "A circular cut has a wide damage range "
        "against one opponent; it is not an area attack.", 15,
        "rising-cut", "katana", "damage hit points", 18, 7, 10, 12,
        "circular-mechanics");
}
