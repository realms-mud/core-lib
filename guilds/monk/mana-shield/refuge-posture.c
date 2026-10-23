//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Refuge Posture", "Reserve eight maximum stamina for "
        "three magical resistance at the expense of one attack. No "
        "additional damage absorption is created.",
        15, 3, "/guilds/monk/mana-shield/refuge-theory.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("stamina point cost", 8);
    addSpecification("cooldown", 8);
    addSpecification("bonus resist magical", 3);
    addSpecification("penalty to attack", 1);
    addSpecification("command template", "chi refuge posture");
    addSpecification("use ability activate message",
        "##InitiatorName## assume##InitiatorReflexive## a refuge posture.");
    addSpecification("use ability deactivate message",
        "##InitiatorName## leave##InitiatorReflexive## the refuge posture.");
}
