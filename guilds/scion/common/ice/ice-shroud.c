//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/sustainedResearchItem.c";

protected string WeaponType = "ERROR";

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ice Shroud");
    addSpecification("source", "Scion of Dhuras Guild");
    SetupResearch();

    addSpecification("description", sprintf("This research provides the "
        "user with the knowledge of the ice shroud technique. By "
        "means of this, the Scion is able to emit a constant stream "
        "of frost from their %s that encapsulates them in a protective "
        "barrier. Doing so is very taxing and will decrease hit points, "
        "spell points, and stamina.", WeaponType));

    addPrerequisite(sprintf("guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(
        sprintf("guilds/scion/paths/%s/ice/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
        (["type":"level",
            "guild": "Scion of Dhuras",
            "value": 23
        ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": 
                sprintf("guilds/scion/paths/%s/ice/freezing-shield.c", WeaponType),
            "name" : "freezing shield",
            "formula" : "additive",
            "base value" : 5,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": 
                sprintf(sprintf("guilds/scion/paths/%s/ice/ice-shield.c", WeaponType), WeaponType),
            "name" : "ice shield",
            "formula" : "additive",
            "base value" : 5,
            "rate": 1.0
        ]),
    }));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("cooldown", 60);
    addSpecification("hit point cost", 100);
    addSpecification("spell point cost", 100);
    addSpecification("stamina point cost", 100);
    addSpecification("command template", "ice shroud");
    addSpecification("bonus resist cold", 50);
    addSpecification("bonus resist physical", 25);
    addSpecification("apply damage reflection", 1);

    addSpecification("use ability activate message", "A shroud of frosty "
        "mist wraps around ##InitiatorName##.");
    addSpecification("use ability deactivate message", "The shroud of frosty "
        "mist around ##InitiatorName## subsides.");
}
