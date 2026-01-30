//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Holy Blessing");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "This skill provides the user with "
        "Ferianth's holy blessing, granting protection against darkness.");

    addPrerequisite("/guilds/disciple-of-ferianth/sacred-pyre/root.c",
        (["type":"research"]));

    addPrerequisite("level",
        (["type":"level",
            "guild": "Disciple of Ferianth",
            "value": 13
        ]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus resist undead", 3);
    addSpecification("bonus resist evil", 2);
}
