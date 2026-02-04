//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Favor");
    addSpecification("source", "disciple of ferianth");
    addSpecification("description", "Having achieved the rank of Exarch, "
        "Ferianth's divine favor permanently enhances the disciple's "
        "magical abilities.");

    addPrerequisite("level",
        ([ "type": "level",
            "guild" : "Disciple of Ferianth",
            "value" : 35
        ]));

    addPrerequisite("/guilds/disciple-of-ferianth/ferianths-grace/root.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus spell points", 100);
    addSpecification("bonus wisdom", 1);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus heal spell points rate", 2);
}
