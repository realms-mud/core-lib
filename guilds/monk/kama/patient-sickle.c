//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/martial-research.h"

protected void Setup()
{
    martialResearch("Patient Sickle", "Reserve eighteen maximum stamina "
        "for +4 short sword at a cost of two dodge.",
        30, 3, "sickle-mastery", "kama");
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 4);
    addSpecification("command template", "kata patient sickle");
    addSpecification("bonus short sword", 4);
    addSpecification("penalty to dodge", 2);
}
