//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialTheory("Binding Lines", "Study how a brief bind taxes the "
        "guard: adds three to Blade Bind's stamina drain, not an "
        "immobilization effect.", 15, "blade-bind", "paired-swords",
        "Blade Bind", "bonus", 3);
}
