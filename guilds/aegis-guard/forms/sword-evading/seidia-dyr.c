//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    addSpecification("name", "Seidia Dyr");
    addSpecification("source", "Aegis Guard");
    addSpecification("description", "This skill provides the user with the "
        "knowledge of a maneuver wherein a hew or thrust is "
        "deflected at the same time as a counter-stab is initiated.");
    
    addSpecification("limited by", (["equipment":({ "dagger", "short sword",
        "long sword", "hand and a half sword", "two-handed sword" })]));

    addPrerequisite("level", 
        (["type":"level", 
          "guild": "Aegis Guard",
          "value": 17 ]));

    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/eithagos.c",
        (["type":"research"]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-attacks/thar-dravn.c",
        (["type":"research"]));
    addPrerequisite("/guilds/aegis-guard/forms/sword-evading/lilt-an-gurth.c",
        (["type":"research"]));

    addSpecification("scope", "self");
    addSpecification("research type", "points");
    addSpecification("research cost", 1);
    addSpecification("bonus dodge", 4);
    addSpecification("bonus attack", 1);
    addSpecification("equivalence", "off-setting");
}
