//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Forward Draw", "Reserve fourteen maximum stamina "
        "for +3 attack at a cost of two defense.",
        15, 3, "draw-alignment", "archery");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata forward draw");
    addSpecification("bonus attack", 3);
    addSpecification("penalty to defense", 2);
}
