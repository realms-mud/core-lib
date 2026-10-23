//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Patient Draw", "Reserve ten maximum stamina "
        "for +3 bow at a cost of one attack.",
        10, 3, "archers-guard", "archery");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 10);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata patient draw");
    addSpecification("bonus bow", 3);
    addSpecification("penalty to attack", 1);
}
