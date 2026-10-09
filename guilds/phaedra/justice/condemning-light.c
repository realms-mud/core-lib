//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "condemning light");
    addSpecification("source", "Order of Phaedra");
    addSpecification("description", "The companion unleashes a "
        "condemning light of pure good-aligned justice, a devastating "
        "strike against those who have violated the Order's code.");
    addPrerequisite("/guilds/phaedra/justice/righteous-verdict.c",
        (["type": "research"]));
    addPrerequisite("/guilds/phaedra/justice/voice-of-the-law.c",
        (["type": "research"]));
    addPrerequisite("level",
        (["type": "level", "guild": "Order of Phaedra", "value": 33]));
    addSpecification("scope", "targeted");
    addSpecification("effect", "combat");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 48);
    addSpecification("cooldown", 28);
    addSpecification("command template", "condemning light at ##Target##");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::call## down a condemning "
        "light upon ##TargetName##, searing them with pure justice.");
    addSpecification("damage type", "good");
    addSpecification("damage hit points", ({
        ([
            "probability": 80,
            "base damage": 35,
            "range": 32
        ]),
        ([
            "probability": 20,
            "base damage": 55,
            "range": 40
        ])
    }));
    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/absolute-authority.c",
            "name": "Absolute Authority",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/voice-of-the-law.c",
            "name": "Voice of the Law",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/phaedra/justice/measured-sentence.c",
            "name": "Measured Sentence",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
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
            "rate": 0.18
        ]),
        ([
            "type": "skill",
            "name": "leadership",
            "formula": "additive",
            "rate": 0.12
        ]),
        ([
            "type": "attribute",
            "name": "charisma",
            "formula": "additive",
            "rate": 0.40
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "level",
            "name": "Order of Phaedra",
            "formula": "additive",
            "rate": 0.50
        ])
    }));
}
