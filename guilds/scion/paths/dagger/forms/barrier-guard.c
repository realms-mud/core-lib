//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Barrier Guard");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of a defensive maneuver where the dominant foot is "
            "forward, the pommel held near the chest with the tip "
            "pointed at the foe's face.");
        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 5 ]));

        addPrerequisite("lib/guilds/scion/paths/dagger/forms/the-plough.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus defense", 2);
        addSpecification("bonus parry", 1);
    }
}
