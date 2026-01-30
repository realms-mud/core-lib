//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Wisdom");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "divine wisdom granted by Ferianth.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/sacred-understanding.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 24
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus theology", 2);
    addSpecification("bonus spellcraft", 2);
}
