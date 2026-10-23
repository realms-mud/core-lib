//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Replenishing Stillness", "Let unused tension drain away "
        "between actions, adding one to natural spell-point healing.",
        15, 2, "/guilds/monk/pure-chi/circulation-theory.c", ([]));
    addSpecification("bonus heal spell points", 1);
}
