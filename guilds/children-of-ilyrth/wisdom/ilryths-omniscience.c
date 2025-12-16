//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryths Omniscience");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with a "
        "fraction of Ilyrth's omniscience. The caster perceives reality "
        "through the goddess's eyes, gaining awareness that approaches "
        "the divine.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 45 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/divine-foresight.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 10);
    addSpecification("bonus magical essence", 7);
    addSpecification("bonus perception", 7);
    addSpecification("bonus wisdom", 2);
}
