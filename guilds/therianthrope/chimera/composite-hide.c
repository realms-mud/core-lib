//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Composite Hide");
    addSpecification("source", "therianthrope");
    addSpecification("description", "This skill deepens your connection to "
        "the chimera spirit, causing your hide to thicken with a blend of "
        "scales, fur, and hardened skin.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/therianthrope/chimera/chimera-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "therianthrope",
            "value": 23
        ]));

    addPrerequisite("/guilds/therianthrope/chimera/chimera-root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus soak", 2);
    addSpecification("bonus resist fire", 2);
}
