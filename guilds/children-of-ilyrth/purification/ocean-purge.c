//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ocean Purge");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the ocean purge spell. The caster unleashes a torrent "
        "of sacred water that cleanses multiple afflictions at once.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 25 ]));

    addPrerequisite("/guilds/children-of-ilyrth/purification/deep-purification.c",
        (["type":"research"]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 100);

    addSpecification("remove modifier", ({ "poison", "disease", "slow", 
        "enfeebled" }));

    addSpecification("decrease intoxication", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 10
        ])
    }));

    addSpecification("decrease druggedness", ({ ([
            "probability": 100,
            "base damage": 15,
            "range": 10
        ])
    }));

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/ilryths-cleansing.c",
            "name": "Ilryths Cleansing",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/purification/divine-purification.c",
            "name": "Divine Purification",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.30
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 90);
    addSpecification("event handler", "oceanPurgeEvent");
    addSpecification("command template", "ocean purge [at ##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::summon## a torrent of Ilryth's sacred water that "
        "crashes through ##TargetName##, purging all corruption from "
        "##TargetPossessive## body.");
}
