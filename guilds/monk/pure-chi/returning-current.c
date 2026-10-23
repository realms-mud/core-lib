//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Returning Current", "Exchange spell-point chi for bodily "
        "stamina, restoring motion rather than wounds.",
        15, 2, "/guilds/monk/pure-chi/circulation-theory.c", ([]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 30);
    addSpecification("command template", "chi returning current");
    addSpecification("use ability message",
        "A returning current steadies ##InitiatorName##'s breathing.");
    addSpecification("increase stamina points", ({
        ([ "probability":100, "base damage":14, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.15 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/measured-expenditure.c":1 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/quiet-intervals.c":4 ]));
}
