//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Disrupting Knee", "A close knee attack drains stamina "
        "instead of hit points; it does not stun.", 10, "open-hand-guard",
        "unarmed", "damage stamina points", 10, 3, 6, 12, "knee-leverage");
}
