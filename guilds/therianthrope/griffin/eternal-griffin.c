//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Eternal Griffin");
    addSpecification("source", "therianthrope");
    addSpecification("description", "The offensive and defensive paths of the "
        "griffin merge into one unified, eternal form. You are an avatar of "
        "aerial destruction, wielding both crushing dives and howling gales "
        "with unmatched mastery.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 55
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/sky-warden.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus attack", 3);
    addSpecification("bonus damage", 3);
    addSpecification("bonus soak", 2);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 35,
        "Diving Strike": 35,
        "Shrieking Gale": 35,
        "Sky Hammer": 35,
        "Tempest": 35
    ]));
}
