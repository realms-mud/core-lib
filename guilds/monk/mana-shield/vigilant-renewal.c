//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Vigilant Renewal", "Spend twenty-four stamina to restore "
        "health and a modest spell-point reserve without dropping your "
        "ward. The long recovery prevents constant conversion.",
        30, 4, "/guilds/monk/mana-shield/measured-renewal.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 24);
    addSpecification("cooldown", 90);
    addSpecification("command template", "chi vigilant renewal");
    addSpecification("use ability message",
        "##InitiatorName## renew##InitiatorReflexive## body and "
        "spirit without relaxing the watch.");
    addSpecification("increase spell points", ({
        ([ "probability":100, "base damage":10, "range":2 ]) }));
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":18, "range":4 ]) }));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/seamless-recovery.c":10 ]));
}
