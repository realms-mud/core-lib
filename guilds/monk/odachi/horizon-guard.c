//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Horizon Guard", "Reserve twelve maximum stamina "
        "for +3 parry at a cost of two attack.", 10, 3,
        "longblade-guard", "odachi");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata horizon guard");
    addSpecification("bonus parry", 3);
    addSpecification("penalty to attack", 2);
}
