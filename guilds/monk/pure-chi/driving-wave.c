//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Driving Wave", "Drive a broad front of chi through an "
        "opponent, bruising the body and draining stamina together.",
        15, 3, "/guilds/monk/pure-chi/pulse-cadence.c", ([]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("spell point cost", 12);
    addSpecification("cooldown", 18);
    addSpecification("command template", "chi driving wave at ##Target##");
    addSpecification("use ability message",
        "A driving wave rolls from ##InitiatorName## into ##TargetName##.");
    addSpecification("damage type", "energy");
    addSpecification("damage hit points", ({
        ([ "probability":100, "base damage":18, "range":6 ]) }));
    addSpecification("damage stamina points", ({
        ([ "probability":100, "base damage":4, "range":2 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.12 ]) }));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/pulse-cadence.c":2,
        "/guilds/monk/pure-chi/stillness-between-pulses.c":2 ]));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/channel-economy.c":2 ]));
}
