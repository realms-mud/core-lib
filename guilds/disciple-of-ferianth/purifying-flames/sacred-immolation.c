//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Immolation");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of engulfing an ally in sacred flames that burn away "
        "impurities while providing healing and lasting regeneration.");
    addSpecification("usage summary", "Heal with cleanse and regeneration");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/purgatory-embrace.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 27
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 60,
            "range": 50
        ]),
        ([
            "probability": 20,
            "base damage": 110,
            "range": 50
        ])
    }));

    addSpecification("remove modifier", ({ "poison", "disease" }));

    addSpecification("bonus heal hit points rate", 4);
    addSpecification("duration", 90);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/healing-mastery.c",
            "name": "Healing Mastery",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/purifying-potency.c",
            "name": "Purifying Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.15
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-healing-potency.c",
            "name": "Divine Healing Potency",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/restorative-focus.c",
            "name": "Restorative Focus",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "theology",
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
            "name": "healing",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 70);
    addSpecification("event handler", "sacredImmolationEvent");
    addSpecification("command template", "sacred immolation [on ##Target##]");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::engulf## ##TargetName## in sacred immolation! "
        "The purifying flames burn away impurities while restoring "
        "##TargetPossessive## vitality.");
}
