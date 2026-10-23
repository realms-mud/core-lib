//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";
#include "/guilds/monk/research-support.h"

protected void Setup()
{
    monkResearch("Braced Recovery", "Brace your recovering war hammer "
        "close to the body, granting one soak and one parry only while "
        "a hammer-type war hammer is primary.", 20, 3,
        "/guilds/monk/bludgeon/rooted-anvil.c", ([
        "equipment":([
            "type":"hammer",
            "blueprint":"war hammer",
            "slot":"wielded primary"
        ])
    ]));
    addSpecification("scope", "self");
    addSpecification("bonus soak", 1);
    addSpecification("bonus parry", 1);
}
