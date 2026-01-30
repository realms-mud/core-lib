//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sacred Understanding");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "enhanced understanding of sacred fire magic.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/liturgical-knowledge.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 16
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus theology", 2);
    addSpecification("bonus magical essence", 2);
}
