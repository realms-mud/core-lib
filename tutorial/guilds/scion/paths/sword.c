//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void SwordFocus()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/forms/stabbing.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/forms/from-the-roof.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/forms/stabbing.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/forms/from-the-roof.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfBlood()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/blood/soulspike.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/blood/soulblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/blood/soulspike.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/blood/soulblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfTheBolt()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/electricity/sparks.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/electricity/shockblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/electricity/sparks.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/electricity/shockblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfEvocation()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/evocation/mysticspike.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/evocation/energyblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/evocation/mysticspike.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/evocation/energyblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfFlame()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/flame/flames.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/flame/flameblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/flame/flames.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/flame/flameblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfWinter()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/ice/frost.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/ice/frostblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/ice/frost.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/ice/frostblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void PathOfSpirit()
{
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/spirit/chill.c");
    addResearchElement("lib/tutorial/guilds/scion/paths/sword/spirit/phantasmalblade.c");

    addChild("lib/tutorial/guilds/scion/paths/sword/spirit/chill.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
    addChild("lib/tutorial/guilds/scion/paths/sword/spirit/phantasmalblade.c",
        "lib/tutorial/guilds/scion/paths/sword/root.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("The Way of the Sword");
        Description("");
        Source("Scion of Dhuras Guild");
        addResearchElement("lib/tutorial/guilds/scion/paths/sword/root.c");
        TreeRoot("lib/tutorial/guilds/scion/paths/sword/root.c");

        SwordFocus();
        PathOfBlood();
        PathOfTheBolt();
        PathOfEvocation();
        PathOfFlame();
        PathOfWinter();
        PathOfSpirit();
    }
}
