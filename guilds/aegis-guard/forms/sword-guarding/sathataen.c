//*****************************************************************************
// Copyright (c) 2020 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Sathataen");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of an offensive maneuver feigning a defensive stance "
            "where the blade is held to the side of the head, tip pointed at "
            "the foe's face.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 8 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/an-foph.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 1);
        addSpecification("bonus attack", 1);
        addSpecification("equivalence", "langort");
    }
}
