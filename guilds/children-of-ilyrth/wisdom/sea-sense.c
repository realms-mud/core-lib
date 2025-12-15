//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Sea Sense");
    addSpecification("source", "Children of Ilyrth");
    addSpecification("description", "This skill provides the user with the "
        "innate sense of a sea creature. The caster becomes attuned to the "
        "movements and vibrations around them, sensing danger before it "
        "arrives.");

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Children of Ilyrth",
          "value": 5 ]));

    addPrerequisite("/guilds/children-of-ilyrth/wisdom/waters-clarity.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus perception", 3);
    addSpecification("bonus senses", 2);
    addSpecification("bonus dodge", 1);
}
