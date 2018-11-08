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
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/sweeping-freeze.c");

    addChild("lib/guilds/scion/paths/sword/ice/sweeping-freeze.c",
        "lib/guilds/scion/paths/sword/ice/frostblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/ice-brand.c");

    addChild("lib/guilds/scion/paths/sword/ice/ice-brand.c",
        "lib/guilds/scion/paths/sword/ice/sweeping-freeze.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/chill-blade.c");

    addChild("lib/guilds/scion/paths/sword/ice/chill-blade.c",
        "lib/guilds/scion/paths/sword/ice/ice-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/icy-edge.c");

    addChild("lib/guilds/scion/paths/sword/ice/icy-edge.c",
        "lib/guilds/scion/paths/sword/ice/chill-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/ice/glaciers-pommel.c");

    addChild("lib/guilds/scion/paths/sword/ice/glaciers-pommel.c",
        "lib/guilds/scion/paths/sword/ice/icy-edge.c");
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
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
