//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Prone Strike");
    addSpecification("source", "fighter");

    addSpecification("description", "This skill provides the user with the "
        "knowledge knowledge of how to use their shield offensively to knock "
        "an opponent offbalance and reducing their ability to dodge, parry, "
        "and otherwise defend themself.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "fighter",
          "value": 5 ]));

    addSpecification("limited by", (["equipment":({ "shield" })]));

    addPrerequisite("/guilds/fighter/shields/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
         ([
            "type":"skill",
            "name" : "shield",
            "formula" : "additive",
            "rate" : 0.25
        ]),
        ([
            "type": "skill",
            "name": "anatomy and physiology",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "skill",
            "name": "physics",
            "formula": "additive",
            "rate": 0.10
        ]),
        ([
            "type": "attribute",
            "name": "strength",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "dexterity",
            "formula": "additive",
            "rate": 0.25
        ]),
        ([
            "type": "attribute",
            "name": "wisdom",
            "formula": "additive",
            "rate": 0.25
        ]),
    }));

    addSpecification("scope", "targeted");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 20);

    addSpecification("stamina point cost", 25);

    addSpecification("penalty to dodge", 25);
    addSpecification("penalty to parry", 25);
    addSpecification("penalty to defense", 25);

    addSpecification("duration", 6);

    addSpecification("event handler", "proneStrikeEvent");
    addSpecification("command template", "prone strike [##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::swipe## ##InitiatorPossessive## "
        "##InitiatorWeapon::Offhand## into ##TargetPossessive::Name## defenses.");
}
