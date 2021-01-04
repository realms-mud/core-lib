//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Tharlegol");
        addSpecification("source", "Aegis Guard");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a maneuver wherein a hew or thrust from below is "
            "countered with an attack from above. This coincides with a step "
            "backward; the higher attack having greater range than the lower.");
        addSpecification("limited by", (["equipment":({ "dagger", "short sword",
            "long sword", "hand and a half sword", "two-handed sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Aegis Guard",
              "value": 16 ]));

        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/nistaros.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
            (["type":"research"]));
        addPrerequisite("guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dodge", 3);
        addSpecification("bonus attack", 2);
        addSpecification("equivalence", "over running");
    }
}
