//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Hook Recovery", "Relax the drawing arm after "
        "a hook: +1 stamina healing rate.", 15, 1, "sickle-guard", "kama");
    addSpecification("bonus heal stamina rate", 1);
}
