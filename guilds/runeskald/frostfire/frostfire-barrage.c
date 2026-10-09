//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Frostfire Barrage");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald launches a rapid barrage "
        "of alternating frost and fire bolts that hammer a single target "
        "with both elemental forces.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 12]));
    addPrerequisite("/guilds/runeskald/frostfire/frostfire-bolt.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/frostfire/frostfire-mastery.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "invoke frostfire barrage ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::hammer## ##TargetName## with a rapid barrage of alternating frost and fire.");

    addSpecification("spell point cost", 40);
    addSpecification("stamina point cost", 16);

    addSpecification("damage hit points", ({
        ([
            "probability": 65,
            "base damage": 80,
            "range": 90
        ]),
        ([
            "probability": 35,
            "base damage": 145,
            "range": 135
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency.c",
            "name": "elemental-potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-reserve.c",
            "name": "elemental-reserve",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-tempo.c",
            "name": "elemental-tempo",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency-ii.c",
            "name": "elemental-potency-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-reserve-ii.c",
            "name": "elemental-reserve-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-tempo-ii.c",
            "name": "elemental-tempo-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/elemental-potency-iii.c",
            "name": "elemental-potency-iii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.11
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "additive",
            "rate": 0.11
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/frostfire/frostfire-mastery.c",
            "name": "Frostfire Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ])
    }));
    addSpecification("consumables", (["ancient power rune": 1]));
}
