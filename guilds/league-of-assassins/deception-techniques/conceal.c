//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved.
// See the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/instantaneousPersistedActiveResearchItem.c";

protected void Setup()
{
    addSpecification("name", "Conceal");
    addSpecification("source", "League of Assassins");
    addSpecification("description", "This research provides the user with "
        "the ability to rapidly conceal themselves, pressing into "
        "shadows and controlling breathing and heartbeat to "
        "minimize their presence.");
    addPrerequisite("level",
        (["type":"level","guild":"League of Assassins","value":3]));
    addPrerequisite("/guilds/league-of-assassins/deception-techniques/root.c",
        (["type":"research"]));
    addSpecification("scope", "self");
    addSpecification("effect", "beneficial");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("spell point cost", 10);
    addSpecification("cooldown", 12);
    addSpecification("command template", "conceal");
    addSpecification("use ability message",
        "##InitiatorName## ##Infinitive::melt## into the "
        "surrounding shadows.");
    addSpecification("bonus hide", 12);
    addSpecification("bonus move silently", 6);
    addSpecification("duration", 30);
    addSpecification("modifiers", ({
        ([
            "type": "skill",
            "name": "hide",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "skill",
            "name": "move silently",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.15
        ]),
        ([
            "type": "skill",
            "name": "perception",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "level",
            "name": "League of Assassins",
            "formula": "additive",
            "rate": 0.40
        ]),
    }));
}
