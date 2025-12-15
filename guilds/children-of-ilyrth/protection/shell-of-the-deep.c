//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Shell of the Deep");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the shell of the deep spell. The caster encases "
        "themselves in a protective shell reminiscent of the great sea "
        "creatures of the deep ocean.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 9 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/ilryths-protection.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 65);
    addSpecification("stamina point cost", 45);

    addSpecification("bonus defense", 4);
    addSpecification("bonus soak", 8);
    addSpecification("bonus resist physical", 10);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/oceanic-fortitude.c",
            "name": "Oceanic Fortitude",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.20
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/tidal-resilience.c",
            "name": "Tidal Resilience",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/oceanic-immortality.c",
            "name": "Oceanic Immortality",
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
            "rate": 1.10
        ])
    }));

    addSpecification("cooldown", 60);
    addSpecification("event handler", "shellOfTheDeepEvent");
    addSpecification("command template", "shell of the deep");
    addSpecification("use ability activate message", "A massive shell of "
        "hardened water and pearl forms around ##InitiatorName##, encasing "
        "##InitiatorObjective## in the protection of the deep.");
    addSpecification("use ability deactivate message", "The shell of the deep "
        "surrounding ##InitiatorName## dissolves into mist.");
}
