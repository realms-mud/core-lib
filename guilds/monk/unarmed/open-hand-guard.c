//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Open Hand Guard", "Deflecting with an open hand grants "
        "+1 parry without wielded equipment.", 5, 1, "measured-palm", "unarmed");
    addSpecification("bonus parry", 1);
}
