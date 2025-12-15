//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryths Insight");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "Ilyrth's divine insight. The goddess shares her wisdom directly "
        "with the caster, granting understanding beyond mortal limits.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 29 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/tidal-intuition.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 6);
    addSpecification("bonus wisdom", 2);
    addSpecification("bonus intelligence", 1);
    addSpecification("bonus spell points", 20);
}
