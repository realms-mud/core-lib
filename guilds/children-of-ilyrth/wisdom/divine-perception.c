//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Divine Perception");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with "
        "perception enhanced by divine power. The caster's senses are "
        "blessed by Ilyrth, allowing them to perceive the world with "
        "supernatural clarity.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 19 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/ilryths-vision.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 5);
    addSpecification("bonus divine essence", 4);
    addSpecification("bonus spot", 3);
    addSpecification("bonus listen", 3);
}
