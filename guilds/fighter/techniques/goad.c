//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/persistedActiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Goad");
    addSpecification("source", "fighter");

    addSpecification("description", "This skill provides the user with the "
        "knowledge knowledge of how best to get under the skin of one's "
        "foes. The angered strike often misses.");

    addPrerequisite("level", 
        (["type": "level", 
          "guild": "fighter",
          "value": 9 ]));

    addSpecification("limited by", (["equipment":({ "long sword",
        "hand and a half sword", "two-handed sword", "axe",
        "dagger", "short sword", "hammer", "mace", "flail",
        "staff", "pole arm" })]));

    addPrerequisite("/guilds/fighter/techniques/root.c",
        (["type":"research"]));

    addSpecification("modifiers", ({ 
        ([
            "type": "weapon damage",
            "name" : "weapons",
            "types" : ({ "long sword", "hand and a half sword", 
                "two-handed sword", "axe", "dagger", "short sword", 
                "hammer", "mace", "flail", "staff", "pole arm" }),
            "formula" : "additive",
            "rate" : 1.5
        ]),
        ([
            "type": "highest skill",
            "name": "weapon skills",
            "skills": ({ "long sword", "hand and a half sword", 
                "two-handed sword", "axe", "dagger", "short sword", 
                "hammer", "mace", "flail", "staff", "pole arm" }),
            "formula" : "logarithmic",
            "rate" : 1.25
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
    addSpecification("cooldown", 10);

    addSpecification("stamina point cost", 25);

    addSpecification("penalty to attack", 25);
    addSpecification("penalty to damage", 15);
    addSpecification("penalty to defense", 25);
    addSpecification("supercede targets", 1);
    addSpecification("duration", 6);

    addSpecification("event handler", "goadEvent");
    addSpecification("command template", "goad [##Target##]");
    addSpecification("use ability message", "##InitiatorName## "
        "##Infinitive::sneer##, `You are terrible at this!' to ##TargetName##.");
}
