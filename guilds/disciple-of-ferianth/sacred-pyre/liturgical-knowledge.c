//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Liturgical Knowledge");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "deeper understanding of Ferianth's sacred liturgies.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 9
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus theology", 2);
    addSpecification("bonus spellcraft", 1);
}
