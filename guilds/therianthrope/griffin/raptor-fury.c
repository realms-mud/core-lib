//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Raptor Fury");
    addSpecification("source", "therianthrope");
    addSpecification("description", "Your connection to the griffin spirit "
        "deepens, intensifying the ferocity of your aerial attacks.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 21
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/talon-rake.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus damage", 2);
    addSpecification("bonus attack", 1);

    addSpecification("affected research type", "percentage");
    addSpecification("affected research", ([
        "Talon Rake": 15,
        "Diving Strike": 10,
        "Shrieking Gale": 15,
        "Sky Hammer": 10,
        "Tempest": 10
    ]));
}
