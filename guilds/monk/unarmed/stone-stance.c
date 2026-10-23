//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Stone Stance", "Reserve twelve maximum stamina for "
        "+3 soak and -2 attack; received hits cost one stamina.", 20, 3,
        "grounded-base", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata stone stance");
    addSpecification("bonus soak", 3);
    addSpecification("penalty to attack", 2);
    addSpecification("per hit received cost", ([ "stamina points":1 ]));
}
