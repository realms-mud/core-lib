//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Breath Conversion", "Spend twelve stamina to recover "
        "six to eight spell points while warded. Recovery is bounded "
        "by the ordinary spell-point maximum.",
        10, 2, "/guilds/monk/mana-shield/recovery-cycle.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 12);
    addSpecification("cooldown", 40);
    addSpecification("command template", "chi breath conversion");
    addSpecification("use ability message",
        "##InitiatorName## turn##InitiatorReflexive## measured "
        "breathing into renewed inner energy.");
    addSpecification("increase spell points", ({
        ([ "probability":100, "base damage":6, "range":2 ]) }));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/defensive-timing.c":4 ]));
}
