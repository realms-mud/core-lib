//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Upheaval");
    addSpecification("source", "geomancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the upheaval spell. The geomancer causes the ground to "
        "violently heave upward beneath a target, dealing massive damage.");

    addPrerequisite("/guilds/geomancer/earth/fissure.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "geomancer",
            "value": 21
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 110);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 100
        ]),
        ([
            "probability": 20,
            "base damage": 100,
            "range": 150
        ])
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
            "research item": "/guilds/geomancer/earth/earth-mastery.c",
            "name": "Earth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/earth-channeling.c",
            "name": "Earth Channeling",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/geomancer/earth/telluric-flow.c",
            "name": "Telluric Flow",
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

    addSpecification("cooldown", 50);
    addSpecification("event handler", "upheavalEvent");
    addSpecification("command template", "upheaval [at ##Target##]");
    addSpecification("use ability message", "The ground violently heaves "
        "upward beneath ##TargetName## at ##InitiatorPossessive::Name## "
        "command.");
}
