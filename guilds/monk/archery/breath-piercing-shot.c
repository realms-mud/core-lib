//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialAttack("Breath-Piercing Shot", "Spend one arrow to disrupt an "
        "opponent's concentration by draining spell points. It does not "
        "silence or prevent casting.", 15, "draw-alignment", "archery",
        "damage spell points", 12, 3, 12, 18, "bow-breath-theory");
}
