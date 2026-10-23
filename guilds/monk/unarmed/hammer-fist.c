//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialAttack("Hammer Fist", "A committed downward blow offers narrow "
        "damage variance at a high stamina cost.", 15, "grounded-base",
        "unarmed", "damage hit points", 24, 2, 12, 14, "fist-compression");
}
