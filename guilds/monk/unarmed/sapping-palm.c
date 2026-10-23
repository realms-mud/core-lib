//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Sapping Palm", "A precise pressure strike drains the "
        "opponent's spell points without transferring them.", 15,
        "driving-elbow", "unarmed", "damage spell points", 12, 4, 8, 14,
        "meridian-lore");
}
