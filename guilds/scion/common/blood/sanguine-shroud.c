//*****************************************************************************
// Copyright (c) 2023 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addSpecification("name", "Sanguine Shroud");
    addSpecification("source", "Scion of Dhuras Guild");
    SetupResearch();

    addSpecification("description", sprintf("This research provides the "
        "user with the knowledge of the sanguine shroud technique. By "
        "means of this, the Scion is able to emit a constant negative "
        "energy wave from their %s that encapsulates them in a protective "
        "barrier. Doing so is very taxing and will decrease hit points, "
        "spell points, and stamina.", WeaponType));

    addPrerequisite(sprintf("/guilds/scion/paths/%s/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite(
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType),
        (["type":"research"]));
    addPrerequisite("level",
    ([
        "type":"level",
        "guild": "Scion of Dhuras",
        "value": 23
    ]));

    addSpecification("modifiers", ({ 
        ([
            "type":"research",
            "research item": 
                sprintf("/guilds/scion/paths/%s/blood/soul-shield.c", WeaponType),
            "name" : "soul shield",
            "formula" : "additive",
            "base value" : 5,
            "rate": 1.0
        ]),
        ([
            "type":"research",
            "research item": 
                sprintf(sprintf("/guilds/scion/paths/%s/blood/shield-of-corruption.c", WeaponType), WeaponType),
            "name" : "shield of corruption",
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
    addSpecification("command template", "sanguine shroud");
    addSpecification("bonus resist undead", 50);
    addSpecification("bonus resist good", 50);
    addSpecification("bonus resist physical", 25);
    addSpecification("apply damage reflection", 1);

    addSpecification("use ability activate message", "A shroud of lurid "
        "negative energy wraps around ##InitiatorName##.");
    addSpecification("use ability deactivate message", "The shroud of negative "
        "energy around ##InitiatorName## subsides.");
}
