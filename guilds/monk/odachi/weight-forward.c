//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Weight Forward", "Reserve sixteen maximum stamina "
        "for +4 damage at a cost of three defense.", 15, 3,
        "longblade-alignment", "odachi");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 16);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata weight forward");
    addSpecification("bonus damage", 4);
    addSpecification("penalty to defense", 3);
}
