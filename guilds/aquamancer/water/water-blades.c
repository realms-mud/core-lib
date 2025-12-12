//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Water Blades");
    addSpecification("source", "aquamancer");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the water blades spell. The aquamancer shapes water into "
        "razor-sharp edges that coat their weapons, adding cutting water damage "
        "to every strike. The blades constantly reform, maintaining their edge "
        "through the heat of battle.");

    addPrerequisite("/guilds/aquamancer/water/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "aquamancer",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 20);

    addSpecification("bonus water enchantment", 5);
    addSpecification("bonus damage", 2);

    addSpecification("modifiers", ({ 
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
    }));

    addSpecification("cooldown", 4);
    addSpecification("event handler", "waterBladesEvent");
    addSpecification("command template", "water blades");
    addSpecification("use ability message", "Razor-sharp edges of water "
        "form along ##InitiatorPossessive::Name## weapons, gleaming with "
        "deadly intent.");
}
