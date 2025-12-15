//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Ilryths Vision");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with a "
        "glimpse of Ilyrth's divine vision. The caster sees the world as "
        "the goddess does, perceiving the interconnected nature of all things.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 15 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/wave-whispers.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus divination", 5);
    addSpecification("bonus divine essence", 3);
    addSpecification("bonus wisdom", 1);
}
