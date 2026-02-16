//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Lord of the Skies");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your griffin form reaches its ultimate "
        "potential, embodying the primordial lord of the skies. "
        "Your talons can rend steel, your gales can shatter stone, "
        "and your feathers are harder than any known armor.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 67
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/griffin-ascendant.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 200);
    addSpecification("bonus attack", 5);
    addSpecification("bonus damage", 5);
    addSpecification("bonus soak", 5);
    addSpecification("bonus dodge", 5);
    addSpecification("bonus defense", 5);
    addSpecification("bonus talons attack", 30);
    addSpecification("bonus beak attack", 30);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 35,
        "Diving Strike": 35,
        "Shrieking Gale": 35,
        "Sky Hammer": 35,
        "Tempest": 35
    ]));
}
