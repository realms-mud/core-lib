//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Arbiter's Ward");
    addSpecification("source", "Hand of Bilanx");
    addSpecification("description", "This research provides the user with the "
        "knowledge of the arbiter's ward. The arbiter wraps themselves "
        "in a thin shell of equilibrium energy that deflects blows.");

    addPrerequisite("level",
        (["type": "level",
          "guild": "Hand of Bilanx",
          "value": 1 ]));

    addPrerequisite("guild rank",
        (["type": "guild rank",
          "guild": "Hand of Bilanx",
          "value": "arbiter" ]));

    addPrerequisite("/guilds/hand-of-bilanx/hand-of-the-scales/scales-attunement.c",
        (["type": "research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 18);

    addSpecification("bonus defense", 2);
    addSpecification("bonus armor class", 1);

    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "magical essence",
            "formula": "logarithmic",
            "rate": 1.12
        ]),
        ([
            "type": "skill",
            "name": "spellcraft",
            "formula": "logarithmic",
            "rate": 1.10
        ]),
        ([
            "type": "skill",
            "name": "insight",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
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

    addSpecification("cooldown", 20);
    addSpecification("event handler", "arbitersWardEvent");
    addSpecification("command template", "arbiters ward");
    addSpecification("use ability activate message", "A faint corona of "
        "balanced energy settles over ##InitiatorName##.");
    addSpecification("use ability deactivate message", "##InitiatorName## "
        "##Infinitive::release## the arbiter's ward.");
}
