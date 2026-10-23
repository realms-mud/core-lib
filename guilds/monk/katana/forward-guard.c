//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"
protected void Setup()
{
    martialResearch("Forward Guard", "Reserve ten maximum stamina for "
        "+3 attack and -2 defense.", 15, 3, "quiet-draw", "katana");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata forward guard");
    addSpecification("bonus attack", 3);
    addSpecification("penalty to defense", 2);
}
