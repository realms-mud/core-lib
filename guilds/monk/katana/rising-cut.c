//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Rising Cut", "An ascending single-target cut commits "
        "eight stamina to a broad damage range.", 10, "quiet-draw",
        "katana", "damage hit points", 14, 5, 8, 10, "rising-lines");
}
