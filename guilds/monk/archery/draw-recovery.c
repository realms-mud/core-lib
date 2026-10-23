//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Draw Recovery", "Relax safely between releases: "
        "+1 stamina healing rate while wielding a primary bow.",
        15, 1, "archers-guard", "archery");
    addSpecification("bonus heal stamina rate", 1);
}
