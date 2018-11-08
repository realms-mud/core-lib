//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/mysticspike.c");
    addResearchElement("lib/guilds/scion/paths/sword/evocation/energyblade.c");

    addChild("lib/guilds/scion/paths/sword/evocation/mysticspike.c",
        "lib/guilds/scion/paths/sword/evocation/root.c");
    addChild("lib/guilds/scion/paths/sword/evocation/energyblade.c",
        "lib/guilds/scion/paths/sword/evocation/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/sweeping-blast.c");

    addChild("lib/guilds/scion/paths/sword/evocation/sweeping-blast.c",
        "lib/guilds/scion/paths/sword/evocation/energyblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/energy-brand.c");

    addChild("lib/guilds/scion/paths/sword/evocation/energy-brand.c",
        "lib/guilds/scion/paths/sword/evocation/sweeping-blast.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/scintillating-blade.c");

    addChild("lib/guilds/scion/paths/sword/evocation/scintillating-blade.c",
        "lib/guilds/scion/paths/sword/evocation/energy-brand.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/magical-edge.c");

    addChild("lib/guilds/scion/paths/sword/evocation/magical-edge.c",
        "lib/guilds/scion/paths/sword/evocation/scintillating-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/evocation/dhurass-pommel.c");

    addChild("lib/guilds/scion/paths/sword/evocation/dhurass-pommel.c",
        "lib/guilds/scion/paths/sword/evocation/magical-edge.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of Evocation");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the knowledge to "
            "express their raw magical energy as pure magical essence "
            "given form.");

        addResearchElement("lib/guilds/scion/paths/sword/evocation/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/evocation/root.c");

        FirstLevel();
        ThirdLevel();
        SeventhLevel();
        EleventhLevel();
        FifteenthLevel();
        TwentyFirstLevel();
    }
}
