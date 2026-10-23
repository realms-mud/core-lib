//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Longblade Recovery", "Release needless tension "
        "between committed strokes: +1 stamina healing rate.", 15, 2,
        "longblade-guard", "odachi");
    addSpecification("bonus heal stamina rate", 1);
}
