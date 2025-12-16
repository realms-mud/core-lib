//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyrth's Sanctuary");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of invoking Ilyrths sanctuary. The goddess creates a "
        "divine refuge of sacred waters around the caster, providing "
        "extraordinary protection against all forms of harm.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tsunami-shield.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);

    addSpecification("bonus defense", 50);
    addSpecification("bonus soak", 25);
    addSpecification("bonus defense class", 4);

    addSpecification("duration", 120);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/avatar-of-protection.c",
            "name": "Avatar of Protection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/mantle-of-ilyrth.c",
            "name": "Mantle of Ilyrth",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
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
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.30
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
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "ilyrthsSanctuaryEvent");
    addSpecification("command template", "ilyrth's sanctuary");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::call## upon Ilyrth as a shimmering dome of sacred "
        "water rises around ##InitiatorObjective##, creating a divine "
        "sanctuary of protection.");
}