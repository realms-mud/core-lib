//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Mobile Draw", "Reserve sixteen maximum stamina "
        "for +3 dodge at a cost of two damage. It grants no extra movement.",
        20, 3, "archers-footing", "archery");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata mobile draw");
    addSpecification("bonus dodge", 3);
    addSpecification("penalty to damage", 2);
}
