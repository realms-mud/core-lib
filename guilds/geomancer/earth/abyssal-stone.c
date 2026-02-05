//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Abyssal Stone");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the abyssal stone spell. The geomancer conjures stone "
        "from the deepest depths of the earth, crushing a target with "
        "immense force while draining their very essence.");

    addPrerequisite("/guilds/geomancer/earth/entombing-embrace.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 51
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 300);

    addSpecification("siphon hit points", ({ ([
            "probability": 100,
            "base damage": 175,
            "range": 300
        ]),
    }));
    addSpecification("siphon spell points", ({ ([
            "probability": 100,
            "base damage": 85,
            "range": 150
        ]),
    }));
    addSpecification("siphon stamina points", ({ ([
            "probability": 100,
            "base damage": 85,
            "range": 150
        ]),
    }));
    addSpecification("damage type", "earth");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earthen-might.c",
            "name": "Earthen Might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/crushing-weight.c",
            "name": "Crushing Weight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/granite-veil.c",
            "name": "Granite Veil",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "weapon damage",
            "name": "staff",
            "types": ({ "staff" }),
            "formula": "additive",
            "rate": 1.0
        ]),
        ([
            "type": "skill",
            "name": "elemental earth",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]),
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "abyssalStoneEvent");
    addSpecification("command template", "abyssal stone [at ##Target##]");
    addSpecification("use ability message", "Stone from the deepest depths "
        "erupts at ##InitiatorPossessive::Name## command, crushing "
        "##TargetName## with immense force and draining ##TargetPossessive## "
        "very essence.");
}
