//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Crushing Embrace", "Brief close pressure drains stamina "
        "but does not immobilize or prevent escape.", 20, "disrupting-knee",
        "unarmed", "damage stamina points", 18, 4, 10, 16,
        "grappling-mechanics");
}
