//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Zephyr Swiftness");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your griffin form moves with "
        "supernatural speed, your dives becoming a blur of talons and "
        "feathers.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 45
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/griffin-apotheosis.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dexterity", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 2);

    addSpecification("affected research type", "decrease cooldown");
    addSpecification("affected research", ([
        "Talon Rake": 1,
        "Diving Strike": 1,
        "Shrieking Gale": 2,
        "Sky Hammer": 2,
        "Tempest": 3
    ]));
}
