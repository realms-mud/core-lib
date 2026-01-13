//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Absolution");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ferianth's divine absolution, healing all "
        "allies in the area while removing afflictions.");
    addSpecification("usage summary", "Area heal with complete cleanse");

    addPrerequisite("/guilds/disciple-of-ferianth/purifying-flames/ferianths-embrace.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 51
        ]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 220);
    addSpecification("effect", "beneficial");

    addSpecification("increase hit points", ({ ([
            "probability": 80,
            "base damage": 90,
            "range": 70
        ]),
        ([
            "probability": 20,
            "base damage": 160,
            "range": 70
        ])
    }));

    addSpecification("increase spell points", ({ ([
            "probability": 80,
            "base damage": 40,
            "range": 30
        ]),
        ([
            "probability": 20,
            "base damage": 70,
            "range": 30
        ])
    }));

    addSpecification("remove modifier", ({ "poison", "disease", "slow", 
        "enfeebled", "paralysis" }));

    addSpecification("modifiers", ({ 
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
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/empowered-restoration.c",
            "name": "Empowered Restoration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/disciple-of-ferianth/purifying-flames/divine-restoration.c",
            "name": "Divine Restoration",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "theology",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "skill",
            "name": "healing",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "divineAbsolutionEvent");
    addSpecification("command template", "divine absolution");

    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::invoke## Ferianth's divine absolution! Sacred fire "
        "washes over all allies, healing and purifying them.");
}
