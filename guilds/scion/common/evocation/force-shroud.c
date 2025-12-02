//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Force Shroud");
    addSpecification("source", "Scion of Dhuras");
    SetupResearch();

    addSpecification("description", sprintf("This research provides the "
        "user with the knowledge of the force shroud technique. By "
        "means of this, the Scion is able to emit a constant energy "
        "flow from their %s that encapsulates them in a protective "
        "barrier. Doing so is very taxing and will decrease hit points, "
        "spell points, and stamina.", WeaponType));

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType),
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
                sprintf("/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType),
            "name" : "Mystic Shield",
            "formula" : "additive",
            "base value" : 5,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": 
                sprintf(sprintf("/guilds/scion/paths/%s/evocation/plasma-shield.c", WeaponType), WeaponType),
            "name" : "Plasma Shield",
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
    addSpecification("command template", "force shroud");
    addSpecification("bonus resist energy", 50);
    addSpecification("bonus resist physical", 25);
    addSpecification("apply damage reflection", 1);

    addSpecification("use ability activate message", "A shroud of scintillating "
        "magical energy wraps around ##InitiatorName##.");
    addSpecification("use ability deactivate message", "The shroud of magical "
        "energy around ##InitiatorName## subsides.");
}
