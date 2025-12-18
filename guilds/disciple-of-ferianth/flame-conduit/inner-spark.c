//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Inner Spark");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with the "
        "knowledge to kindle Ferianth's divine spark within their soul. "
        "This inner flame enhances the flame conduit form.");

    addSpecification("limited by", ([
        "research active": ({
            "/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c"
        })
    ]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 5
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/flame-conduit/conduit-root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus elemental fire", 1);
    addSpecification("bonus evocation", 3);
	addSpecification("bonus theology", 2);
}
