//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "light of the steward");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion channels the full "
        "restorative power of a senior steward, flooding an ally "
        "with sustaining good-aligned light that mends severe wounds.");
    addPrerequisite("/guilds/phaedra/stewardship/good-word.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/stewardship/keeper-of-traditions.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 29]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 45);
    addSpecification("cooldown", 26);
    addSpecification("command template", "light of the steward on ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::pour## the light of a true "
        "steward into ##TargetName##, mending deep wounds.");
    addSpecification("increase hit points", ({
        ([
            "probability": 85,
            "base damage": 38,
            "range": 35
        ]),
        ([
            "probability": 15,
            "base damage": 62,
            "range": 42
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/keeper-of-traditions.c",
            "name": "Keeper of Traditions",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/stewards-resolve.c",
            "name": "Steward's Resolve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/stewardship/restorative-presence.c",
            "name": "Restorative Presence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.35
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.48
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.40
        ])
    }));
}
