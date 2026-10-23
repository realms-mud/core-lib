//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Restorative Chi Breath", "Turn spell-point chi inward to "
        "close minor wounds. Wisdom guides the breath into injured tissue.",
        10, 2, "/guilds/monk/pure-chi/chi-anatomy.c", ([]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("spell point cost", 8);
    addSpecification("cooldown", 24);
    addSpecification("command template", "chi restorative breath");
    addSpecification("use ability message",
        "##InitiatorName## breathe##InitiatorReflexive## warmth into wounds.");
    addSpecification("increase hit points", ({
        ([ "probability":100, "base damage":14, "range":4 ]) }));
    addSpecification("modifiers", ({
        ([ "type":"attribute", "name":"wisdom",
            "formula":"additive", "rate":0.2 ]),
        ([ "type":"skill", "name":"magical essence",
            "formula":"additive", "rate":0.1 ]) }));
    addSpecification("spell point cost modifiers", ([
        "/guilds/monk/pure-chi/measured-expenditure.c":1 ]));
    addSpecification("cooldown modifiers", ([
        "/guilds/monk/pure-chi/quiet-intervals.c":4 ]));
}
