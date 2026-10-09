//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "phaedra's judgment");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The full judgment of the White "
        "Rose falls upon the target - a devastating strike combining "
        "radiant power, good-aligned force, and the companion's "
        "absolute conviction.");
    addPrerequisite("/guilds/phaedra/white-rose/phaedras-blessing.c",
        (["type": "research"]));
    addPrerequisite("guild rank",
        (["type": "guild rank", "guild": "Order of Phaedra",
        "value": "white rose"]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 55);
    addSpecification("cooldown", 35);
    addSpecification("command template", "phaedras judgment at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## down the judgment of "
        "Phaedra upon ##TargetName##, blazing light and righteous "
        "force meeting as one.");
    addSpecification("damage type", "radiant");
    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 50,
            "range": 45
        ]),
        ([
            "probability": 30,
            "base damage": 80,
            "range": 60
        ])
    }));
    addSpecification("limited by", (["equipment": ({ "long sword",
        "hand and a half sword", "short sword", "dagger" })]));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/phaedras-light.c",
            "name": "Phaedra's Light",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/white-rose/champions-radiance.c",
            "name": "Champion's Radiance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/courage/radiant-might.c",
            "name": "Radiant Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.16
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.18
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.32
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.30
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.60
        ])
    }));
}
