//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Serene Focus");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of serene focus. By centering themselves at the middle "
        "of all things, the priest achieves a focused state that "
        "improves their accuracy and resilience simultaneously.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 5 ]));

    addPrerequisite("/guilds/hand-of-bilanx/middle-path/pacifying-aura.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 12);

    addSpecification("bonus attack", 3);
    addSpecification("bonus defense", 4);
    addSpecification("bonus perception", 3);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.15
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.08
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.04
        ])
    }));

    addSpecification("duration", 150);
    addSpecification("cooldown", 12);
    addSpecification("event handler", "sereneFocusEvent");
    addSpecification("command template", "serene focus");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::center## ##InitiatorObjective##self and "
        "##Infinitive::achieve## serene focus.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "achieve serene focus right now.");
}
