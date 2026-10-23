//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired High Guard", "Reserve ten maximum stamina "
        "for +3 parry at a cost of one damage while holding the pair.",
        10, 3, "paired-guard", "paired-swords");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata paired high guard");
    addSpecification("bonus parry", 3);
    addSpecification("penalty to damage", 1);
}
