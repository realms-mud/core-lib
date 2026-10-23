//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Weight Check", "Make the opponent spend stamina "
        "resisting the long blade. Does not automatically stagger or pin.",
        15, "heavy-leverage", "odachi", "damage stamina points",
        20, 3, 14, 22, "longblade-pressure-theory");
}
