//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Seamless Recovery", "Reset vigilance without interrupting "
        "restoration. Vigilant Renewal recovers ten seconds sooner and "
        "Shelter of Intent eight seconds sooner.",
        30, 3, "/guilds/monk/mana-shield/renewing-rhythm.c", ([]));
    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Vigilant Renewal":10,
        "Shelter of Intent":8 ]));
}
