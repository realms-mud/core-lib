//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyryth's Sanctuary");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilryth's sanctuary spell. The goddess creates a "
        "divine sanctuary around the caster and all allies, providing "
        "unparalleled protection.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/tsunami-shield.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 250);
    addSpecification("stamina point cost", 150);

    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 12);
    addSpecification("bonus resist physical", 15);
    addSpecification("bonus resist magical", 15);
    addSpecification("apply damage reflection", 20);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/avatar-of-protection.c",
            "name": "Avatar of Protection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/mantle-of-ilyrth.c",
            "name": "Mantle of Ilyrth",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.40
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
            "formula": "additive",
            "rate": 0.20
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.40
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.20
        ])
    }));

    addSpecification("cooldown", 300);
    addSpecification("event handler", "ilrythsSanctuaryEvent");
    addSpecification("command template", "ilryths sanctuary");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::call## upon Ilryth to create a divine sanctuary as "
        "radiant waters rise to shield all nearby allies.");
    addSpecification("use ability deactivate message", "Ilryth's divine "
        "sanctuary fades, leaving only a lingering sense of peace.");
}
