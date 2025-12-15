//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sanctuary of Waves");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the sanctuary of waves spell. The caster creates a "
        "sacred sanctuary of swirling waters that protects all nearby allies.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 23 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/ilryths-aegis.c",
        (["type":"research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 150);
    addSpecification("stamina point cost", 100);

    addSpecification("bonus defense", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus resist physical", 5);
    addSpecification("bonus resist magical", 5);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/divine-bulwark.c",
            "name": "Divine Bulwark",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/tsunami-shield.c",
            "name": "Tsunami Shield",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c",
            "name": "Ilyryth's Sanctuary",
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
            "rate": 1.30
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "sanctuaryOfWavesEvent");
    addSpecification("command template", "sanctuary of waves");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::invoke## a sanctuary of sacred waves that rises "
        "to protect all nearby allies.");
    addSpecification("use ability deactivate message", "The sanctuary of "
        "waves surrounding ##InitiatorName## and nearby allies recedes.");
}
