//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Descending Arc", "Commit the heavy blade downward "
        "for one costly strike, leaving a long recovery.", 20,
        "longblade-alignment", "odachi", "damage hit points",
        34, 3, 22, 26, "longblade-descent-theory");
}
