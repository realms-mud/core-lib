//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Cleansing Waters");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the cleansing waters spell. The caster calls upon "
        "Ilyrth's sacred water to wash away minor afflictions and reduce "
        "the severity of toxins.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 5 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/root.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 25);

    addSpecification("decrease intoxication", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 5
        ])
    }));

    addSpecification("decrease druggedness", ({ ([
            "probability": 100,
            "base damage": 5,
            "range": 5
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/waters-purity.c",
            "name": "Waters Purity",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/tidal-cleansing.c",
            "name": "Tidal Cleansing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/sacred-cleansing.c",
            "name": "Sacred Cleansing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/ilryths-cleansing.c",
            "name": "Ilryths Cleansing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
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
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("cooldown", 15);
    addSpecification("event handler", "cleansingWatersEvent");
    addSpecification("command template", "cleansing waters [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon Ilyrth's cleansing waters as a gentle "
        "stream of pure water washes over ##TargetName##, easing "
        "##TargetPossessive## afflictions.");
}
