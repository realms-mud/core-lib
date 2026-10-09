//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Rune Flurry");
    addSpecification("source", "runeskald");
    addSpecification("description", "The runeskald unleashes a rapid flurry "
        "of rune-guided strikes on a single target.");

    addPrerequisite("level",
        (["type": "level", "guild": "runeskald", "value": 10]));
    addPrerequisite("/guilds/runeskald/rune-warrior/rune-lunge.c",
        (["type": "research"]));
    addPrerequisite("/guilds/runeskald/rune-warrior/paint-rune-of-alacrity.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);
    addSpecification("command template", "rune flurry ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::unleash## a rune-guided flurry of rapid strikes on ##TargetName##.");

    addSpecification("spell point cost", 28);
    addSpecification("stamina point cost", 22);

    addSpecification("damage hit points", ({
        ([
            "probability": 70,
            "base damage": 45,
            "range": 45
        ]),
        ([
            "probability": 30,
            "base damage": 80,
            "range": 80
        ])
    }));

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might.c",
            "name": "warriors-might",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance.c",
            "name": "warriors-endurance",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-tempo.c",
            "name": "warriors-tempo",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-might-ii.c",
            "name": "warriors-might-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-endurance-ii.c",
            "name": "warriors-endurance-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/warriors-tempo-ii.c",
            "name": "warriors-tempo-ii",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "long sword",
            "formula": "additive",
            "rate": 0.09
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "research",
            "research item": "/guilds/runeskald/rune-warrior/paint-rune-of-strength.c",
            "name": "Paint Rune of Strength",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ])
    }));
    addSpecification("consumables", (["elder blade rune": 1]));
}
