//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Iron Body", "Conditioned muscles grant +1 fortified "
        "while fighting without wielded equipment.", 25, 3,
        "centered-vitality", "unarmed");
    addSpecification("bonus fortified", 1);
}
