//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/knowledgeResearchItem.c";

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        knowledgeResearchItem::reset(arg);
        addSpecification("name", "Tortured Pommel");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of the Tortured Pommel technique. This form enhances "
            "the scion's flameblade.");

        addPrerequisite("level", 
            (["type":"level", 
              "guild": "Scion of Dhuras",
              "value": 21 ]));
        addPrerequisite("lib/guilds/scion/paths/dagger/blood/wicked-edge.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Soul Blade":5]));
    }
}
