//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aura of Law");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the aura of law. The priest radiates an aura of "
        "structured order that bolsters allies with improved accuracy and "
        "stability.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 8 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/ward-of-structure.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);

    addSpecification("bonus attack", 4);
    addSpecification("bonus defense", 4);
    addSpecification("bonus soak", 2);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "philosophy",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.05
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.05
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "base value": 1,
            "rate": 1.04
        ])
    }));

    addSpecification("cooldown", 20);
    addSpecification("event handler", "auraOfLawEvent");
    addSpecification("command template", "aura of law");
    addSpecification("use ability activate message", "##InitiatorName## "
        "breathes slowly and a field of ordered structure expands outward, "
        "bolstering all nearby allies.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the aura of law.");
}
