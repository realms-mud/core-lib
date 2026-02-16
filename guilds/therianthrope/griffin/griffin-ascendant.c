//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Griffin Ascendant");
    addSpecification("source", "therianthrope");
    addSpecification("description", "You have ascended beyond mere "
        "therianthropic transformation. Your griffin form is a force of "
        "primal nature itself, soaring with impossible speed and striking "
        "with the fury of the heavens.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 61
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/eternal-griffin.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus hit points", 175);
    addSpecification("bonus attack", 4);
    addSpecification("bonus damage", 4);
    addSpecification("bonus dodge", 6);
    addSpecification("bonus defense", 6);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 30,
        "Diving Strike": 30,
        "Shrieking Gale": 30,
        "Sky Hammer": 30,
        "Tempest": 30
    ]));
}
