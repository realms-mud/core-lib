//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Claw Shelter", "Reserve eight maximum stamina "
        "for +3 dodge at a cost of one damage.",
        10, 3, "claw-footwork", "claw");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata claw shelter");
    addSpecification("bonus dodge", 3);
    addSpecification("penalty to damage", 1);
}
