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
        addSpecification("name", "Off-setting");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a maneuver wherein a hew or thrust from a sword is "
            "deflected at the same time as a countering cleave is initiated.");
        
        addSpecification("limited by", (["equipment":({
            "axe" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 17 ]));

        addPrerequisite("guilds/scion/paths/axe/forms/cleaving.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/axe/forms/over-hew.c",
            (["type":"research"]));
        addPrerequisite("guilds/scion/paths/axe/forms/dance-of-death.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus dodge", 4);
        addSpecification("bonus attack", 1);
    }
}
