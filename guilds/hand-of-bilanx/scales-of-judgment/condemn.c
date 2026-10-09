//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Condemn");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the condemn spell. The priest speaks the formal "
        "condemnation of one who has transgressed severely against the "
        "balance, striking them with the full weight of all their excess.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 11 ]));

    addPrerequisite("/guilds/hand-of-bilanx/scales-of-judgment/weight-of-judgment.c",
        (["type": "research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 50);

    addSpecification("damage hit points", ({ ([
            "probability": 80,
            "base damage": 30,
            "range": 25
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 30
        ])
    }));
    addSpecification("damage type", "neutral");

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/judgment-theory.c",
            "name": "Judgment Theory",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.14
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/true-sight.c",
            "name": "True Sight",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-mastery.c",
            "name": "Fifth Truth Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.12
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-perfected.c",
            "name": "Fifth Truth Perfected",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "research",
            "research item": "/guilds/hand-of-bilanx/scales-of-judgment/fifth-truth-ascendant.c",
            "name": "Fifth Truth Ascendant",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "evocation",
            "formula": "additive",
            "rate": 0.10
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
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 12);
    addSpecification("event handler", "condemnEvent");
    addSpecification("command template", "condemn [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## raises one "
        "hand and ##InitiatorSubjective## ##Infinitive::speak## the word "
        "of condemnation. The full weight of ##TargetPossessive## own "
        "transgression crashes down upon ##TargetName##.");
}
