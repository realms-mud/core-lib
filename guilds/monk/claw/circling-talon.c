//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Circling Talon", "Reserve fourteen maximum stamina "
        "for +3 defense at a cost of two attack. No extra movement applies.",
        20, 3, "claw-footwork", "claw");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata circling talon");
    addSpecification("bonus defense", 3);
    addSpecification("penalty to attack", 2);
}
