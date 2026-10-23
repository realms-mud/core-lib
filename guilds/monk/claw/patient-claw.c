//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Patient Claw", "Reserve eighteen maximum stamina "
        "for +4 dagger at a cost of two dodge.",
        30, 3, "claw-mastery", "claw");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata patient claw");
    addSpecification("bonus dagger", 4);
    addSpecification("penalty to dodge", 2);
}
