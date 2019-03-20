//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/passiveResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        passiveResearchItem::reset(arg);
        addSpecification("name", "Smite");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of how to more effectively smite with the head "
            "of a staff.");
        addSpecification("limited by", (["equipment":({ "staff" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 5 ]));

        addPrerequisite("lib/guilds/scion/paths/staff/forms/mauling.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus staff", 1);
        addSpecification("bonus damage", 2);
    }
}
