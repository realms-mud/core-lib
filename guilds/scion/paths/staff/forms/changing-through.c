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
        addSpecification("name", "Changing Through");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of various techniques of escaping a bind by sliding "
            "the staff's head out from underneath the weapon and then "
            "striking to another opening.");

        addSpecification("limited by", (["equipment":({
            "staff" })]));

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 19 ]));

        addPrerequisite("lib/guilds/scion/paths/staff/forms/dance-of-death.c",
            (["type":"research"]));

        addSpecification("scope", "self");
        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("bonus staff", 1);
        addSpecification("bonus dodge", 1);
        addSpecification("bonus parry", 1);
        addSpecification("bonus attack", 1);
    }
}
