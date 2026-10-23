//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Descending Cut", "A committed descending strike trades "
        "more stamina and recovery for concentrated damage.", 15,
        "rooted-cut", "katana", "damage hit points", 20, 3, 10, 12,
        "descending-lines");
}
