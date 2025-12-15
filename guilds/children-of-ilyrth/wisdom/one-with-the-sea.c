//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "One With the Sea");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "ultimate unity with the sea's wisdom. The caster becomes one with "
        "the eternal ocean, perceiving all things through Ilyrth's infinite "
        "consciousness. Nothing escapes their awareness.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 67 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/divine-enlightenment.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 15);
    addSpecification("bonus divine essence", 12);
    addSpecification("bonus perception", 12);
    addSpecification("bonus wisdom", 4);
    addSpecification("bonus dodge", 8);
    addSpecification("bonus defense", 6);
}
