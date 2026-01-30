//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ferianth's Insight");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "insight into the deeper mysteries of Ferianth's power.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/divine-wisdom.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 32
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus theology", 3);
    addSpecification("bonus magical essence", 2);
}
