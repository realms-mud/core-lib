//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Driving Elbow", "A compact elbow strike trades extra "
        "stamina for a stronger physical hit.", 10, "hand-alignment",
        "unarmed", "damage hit points", 16, 0, 8, 10, "elbow-anatomy");
}
