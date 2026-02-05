//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ember Veil");
    addSpecification("source", "pyromancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the ember veil spell. The pyromancer cloaks themselves "
        "in a shimmering veil of embers that provides ultimate protection.");

    addPrerequisite("/guilds/pyromancer/fire/scorching-tide.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "pyromancer",
            "value": 47
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 120);

    addSpecification("bonus defense", 10);
    addSpecification("bonus soak", 10);
    addSpecification("bonus resist fire", 50);
    addSpecification("duration", 240);

    addSpecification("modifiers", ({ 
        ([
            "type": "skill",
            "name": "elemental fire",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "level",
            "formula": "logarithmic",
            "rate": 1.05
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.25
        ]),
        ([
            "type": "attribute",
            "name": "intelligence",
            "formula": "additive",
            "rate": 0.05
        ]), 
    }));

    addSpecification("cooldown", 360);
    addSpecification("event handler", "emberVeilEvent");
    addSpecification("command template", "ember veil");
    addSpecification("use ability message", "A shimmering veil of glowing "
        "embers cloaks ##InitiatorName##.");
}
