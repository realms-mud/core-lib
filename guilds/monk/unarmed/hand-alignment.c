//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Hand Alignment", "Aligning wrist and forearm grants "
        "+2 unarmed skill while both wielded slots are empty.", 10, 2,
        "measured-palm", "unarmed");
    addSpecification("bonus unarmed", 2);
}
