//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Golden Plumage");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This skill deepens your connection to "
        "the griffin spirit, causing your plumage to thicken and harden, "
        "granting greater resilience while transformed.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/griffin/griffin-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 17
        ]));

    addPrerequisite("/guilds/therianthrope/griffin/griffin-root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus resist air", 2);
}
