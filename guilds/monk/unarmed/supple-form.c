//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Supple Form", "Flexible empty-handed transitions grant "
        "+1 dexterity.", 15, 2, "quiet-footwork", "unarmed");
    addSpecification("bonus dexterity", 1);
}
