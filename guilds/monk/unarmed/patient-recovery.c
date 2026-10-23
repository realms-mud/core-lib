//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Patient Recovery", "Measured pauses improve stamina "
        "healing rate by one while empty-handed.", 15, 2,
        "balanced-recovery", "unarmed");
    addSpecification("bonus heal stamina rate", 1);
}
