//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Paired Flow", "Reserve fourteen maximum stamina "
        "for +3 dodge at a cost of two damage.", 20, 3,
        "paired-footwork", "paired-swords");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 14);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata paired flow");
    addSpecification("bonus dodge", 3);
    addSpecification("penalty to damage", 2);
}
