//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Dual Aspect");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the dual aspect. The priest draws out both their "
        "physical and magical natures simultaneously, creating a "
        "harmonious state that improves both attributes at once.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 12 ]));

    addPrerequisite("/guilds/hand-of-bilanx/equilibrium-form/twofold-nature.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 16);

    addSpecification("bonus strength", 2);
    addSpecification("bonus intelligence", 2);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus constitution", 2);
    addSpecification("bonus hit points", 20);
    addSpecification("bonus spell points", 20);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.18
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
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
            "name": "constitution",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "Hand of Bilanx",
            "formula": "logarithmic",
            "rate": 1.05
        ])
    }));

    addSpecification("duration", 180);
    addSpecification("cooldown", 14);
    addSpecification("event handler", "dualAspectEvent");
    addSpecification("command template", "dual aspect");
    addSpecification("use ability message", "##InitiatorName## draws "
        "##InitiatorObjective##self into dual aspect - physical and "
        "magical natures aligned in harmony.");
    addSpecification("use ability fail message", "##InitiatorName## cannot "
        "assume dual aspect right now.");
}
