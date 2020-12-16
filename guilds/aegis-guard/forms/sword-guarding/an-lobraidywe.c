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
        addSpecification("name", "An Lobraidywe");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a basic defensive maneuver where the blade is "
            "held to the side of the head, tip pointed up.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

         addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 3 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-guarding/celon-ai-esgal.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 1);
        addSpecification("bonus parry", 2);
        addSpecification("equivalence", "the unicorn");
    }
}
