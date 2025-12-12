//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Drowning Grasp");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the drowning grasp spell. The aquamancer wraps tendrils "
        "of water around the target's face, forcing liquid into their airways. "
        "The victim struggles to breathe as the water continuously reforms, "
        "causing ongoing damage and panic.");

    addPrerequisite("/guilds/aquamancer/water/splash.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 7
        ]));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 35);

    addSpecification("damage hit points", ({ ([
            "probability": 90,
            "base damage": 5,
            "range": 10
        ]),
        ([
            "probability": 10,
            "base damage": 10,
            "range": 15
        ])
    }));
    addSpecification("damage type", "water");
    addSpecification("duration", 30);

    addSpecification("modifiers", ({
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/water-blast.c",
            "name": "Water Blast",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/toxic-waters.c",
            "name": "Toxic Waters",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/suffocating-depths.c",
            "name": "Suffocating Depths",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "research",
            "research item": "/guilds/aquamancer/water/drowning-embrace.c",
            "name": "Drowning Embrace",
            "formula": "multiplicative",
            "base value": 1,
            "rate": 1.25
        ]),
        ([
            "type": "skill",
            "name": "elemental water",
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
            "type": "skill",
            "name": "magical essence",
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

    addSpecification("cooldown", 45);
    addSpecification("event handler", "drowningGraspEvent");
    addSpecification("command template", "drowning grasp [at ##Target##]");
    addSpecification("use ability message", "Tendrils of water wrap around "
        "##TargetPossessive::Name## face as ##InitiatorName## "
        "##Infinitive::clench## ##InitiatorPossessive## fist, forcing liquid "
        "into ##TargetPossessive## airways.");
}
