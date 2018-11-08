//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/frost.c");
    addResearchElement("lib/guilds/scion/paths/sword/ice/frostblade.c");

    addChild("lib/guilds/scion/paths/sword/ice/frost.c",
        "lib/guilds/scion/paths/sword/ice/root.c");
    addChild("lib/guilds/scion/paths/sword/ice/frostblade.c",
        "lib/guilds/scion/paths/sword/ice/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Winter");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy in the ice realm.");

        addResearchElement("lib/guilds/scion/paths/sword/ice/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/ice/root.c");

        FirstLevel();
    }
}
