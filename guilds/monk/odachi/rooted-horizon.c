//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Rooted Horizon", "Reserve eighteen maximum stamina "
        "for +3 soak at a cost of three attack.", 20, 3,
        "longblade-footing", "odachi");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata rooted horizon");
    addSpecification("bonus soak", 3);
    addSpecification("penalty to attack", 3);
}
