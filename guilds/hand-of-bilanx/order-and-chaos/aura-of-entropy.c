//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Aura of Entropy");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the aura of entropy. The priest bleeds controlled "
        "chaos outward into the environment, making enemies less accurate "
        "and less capable of structured action.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 8 ]));

    addPrerequisite("/guilds/hand-of-bilanx/order-and-chaos/unraveling.c",
        (["type": "research"]));

    addSpecification("scope", "area");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 22);

    addSpecification("penalty to attack", 4);
    addSpecification("penalty to defense", 3);
    addSpecification("apply slow", 1);

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
    addSpecification("event handler", "auraOfEntropyEvent");
    addSpecification("command template", "aura of entropy");
    addSpecification("use ability activate message", "##InitiatorName## "
        "opens the entropic half of the second truth and a field of "
        "dissonance spreads across the area, disrupting all enemies.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::close## the aura of entropy.");
}
