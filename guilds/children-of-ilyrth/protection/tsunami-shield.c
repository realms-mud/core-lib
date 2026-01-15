//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Tsunami Shield");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the tsunami shield spell. The caster summons the "
        "unstoppable power of a tsunami to form an overwhelming protective "
        "barrier.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 37 ]));

    addPrerequisite("/guilds/children-of-ilyrth/protection/divine-bulwark.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 175);
    addSpecification("stamina point cost", 110);

    addSpecification("bonus defense", 12);
    addSpecification("bonus soak", 15);
    addSpecification("apply damage reflection", 20);
    addSpecification("bonus resist physical", 15);
    addSpecification("bonus resist magical", 10);

    addSpecification("modifiers", ({ 
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/ilryths-sanctuary.c",
            "name": "Ilyryth's Sanctuary",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.30
        ]),
        ([
            "type": "research",
            "research item": "/guilds/children-of-ilyrth/protection/avatar-of-protection.c",
            "name": "Avatar of Protection",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.35
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
            "rate": 1.18
        ])
    }));

    addSpecification("cooldown", 180);
    addSpecification("event handler", "tsunamiShieldEvent");
    addSpecification("command template", "tsunami shield");
    addSpecification("use ability activate message", "A massive wall of "
        "water rises around ##InitiatorName##, forming an unstoppable "
        "tsunami shield.");
    addSpecification("use ability deactivate message", "The tsunami shield "
        "around ##InitiatorName## crashes down and dissipates.");
}
