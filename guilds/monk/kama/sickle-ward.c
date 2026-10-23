//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Sickle Ward", "Reserve ten maximum stamina "
        "for +3 parry at a cost of one attack.",
        10, 3, "sickle-guard", "kama");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata sickle ward");
    addSpecification("bonus parry", 3);
    addSpecification("penalty to attack", 1);
}
