//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ardent Mastery");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "mastery of the ardent's sacred arts.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/ferianths-insight.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 40
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus theology", 3);
    addSpecification("bonus spellcraft", 3);
}
