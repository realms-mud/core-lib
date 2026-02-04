//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Exarch's Resolve");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Having achieved the rank of Exarch, "
        "the disciple's unwavering faith grants enhanced spiritual power.");

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 35
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus spell points", 50);
}
