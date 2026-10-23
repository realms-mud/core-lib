//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Stilling Arc", "Disrupt an opponent's energy through "
        "a demanding blade action. Drains spell points without silence.",
        20, "longblade-pressure-theory", "odachi", "damage spell points",
        20, 3, 18, 24, 0);
}
