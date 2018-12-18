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
        addSpecification("name", "Icy Edge");
        addSpecification("source", "Scion of Dhuras Guild");
        addSpecification("description", "This skill provides the user with the "
            "knowledge of the icy edge technique. This form enhances "
            "the scion's frostblade.");

        addPrerequisite("level",
            (["type":"level",
                "guild" : "Scion of Dhuras",
                "value" : 15]));
        addPrerequisite("lib/guilds/scion/paths/dagger/ice/chill-blade.c",
            (["type":"research"]));

        addSpecification("limited by", (["equipment":({
            "dagger", "short sword" })]));

        addSpecification("research type", "points");
        addSpecification("research cost", 1);
        addSpecification("affected research", (["Frost Blade":2]));
    }
}
