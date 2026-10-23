//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Measured Renewal", "Trade eighteen stamina for a "
        "deliberate recovery of twelve to fourteen spell points. This "
        "long cycle replenishes the normal pool, not shield capacity.",
        15, 3, "/guilds/monk/mana-shield/breath-conversion.c", ([
            "research active":({
                "/guilds/monk/mana-shield/mindful-ward.c" }) ]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("stamina point cost", 18);
    addSpecification("cooldown", 60);
    addSpecification("command template", "chi measured renewal");
    addSpecification("use ability message",
        "##InitiatorName## draw##InitiatorReflexive## energy "
        "from a measured renewal of breath.");
    addSpecification("increase spell points", ({
        ([ "probability":100, "base damage":12, "range":2 ]) }));
    addSpecification("stamina point cost modifiers", ([
        "/guilds/monk/mana-shield/economical-refuge.c":2 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/mana-shield/renewing-rhythm.c":6 ]));
}
