//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Tiger Stance", "Reserve ten maximum stamina for "
        "+3 damage and -2 defense; landed hits cost two stamina.", 15, 3,
        "driving-elbow", "unarmed");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata tiger stance");
    addSpecification("bonus damage", 3);
    addSpecification("penalty to defense", 2);
    addSpecification("per hit landed cost", ([ "stamina points":2 ]));
}
