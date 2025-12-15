//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilyrth's Aegis");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of Ilyrth's aegis spell. The goddess herself extends her "
        "divine protection over the caster, creating an nearly impenetrable "
        "shield of sacred waters.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "Children of Ilyrth",
          "value": 19 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/maelstrom-barrier.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);
    addSpecification("stamina point cost", 75);

    addSpecification("bonus defense", 8);
    addSpecification("bonus soak", 10);
    addSpecification("bonus resist physical", 10);
    addSpecification("bonus resist magical", 10);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/abyssal-ward.c",
            "name": "Abyssal Ward",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
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
            "name": "Ilryth's Sanctuary",
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
            "name": "divine essence",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.35
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.15
        ])
    }));

    addSpecification("cooldown", 120);
    addSpecification("event handler", "Ilryth'sAegisEvent");
    addSpecification("command template", "Ilryth's aegis");
    addSpecification("use ability activate message", "##InitiatorName## "
        "##Infinitive::invoke## Ilyrth's name as a radiant aegis of divine "
        "water manifests around ##InitiatorObjective##.");
    addSpecification("use ability deactivate message", "Ilyrth's divine "
        "aegis fades from around ##InitiatorName##.");
}