//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/blood/soulspike.c");
    addResearchElement("lib/guilds/scion/paths/sword/blood/soulblade.c");

    addChild("lib/guilds/scion/paths/sword/blood/soulspike.c",
        "lib/guilds/scion/paths/sword/blood/root.c");
    addChild("lib/guilds/scion/paths/sword/blood/soulblade.c",
        "lib/guilds/scion/paths/sword/blood/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Blood");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as blood magic.");

        addResearchElement("lib/guilds/scion/paths/sword/blood/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/blood/root.c");

        FirstLevel();
    }
}
