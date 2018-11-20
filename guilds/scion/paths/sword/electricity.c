//*****************************************************************************
// Copyright (c) 2018 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/sparks.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shockblade.c");

    addChild("lib/guilds/scion/paths/sword/electricity/sparks.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
    addChild("lib/guilds/scion/paths/sword/electricity/shockblade.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/sweeping-shock.c");

    addChild("lib/guilds/scion/paths/sword/electricity/sweeping-shock.c",
        "lib/guilds/scion/paths/sword/electricity/shockblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shocking-tendrils.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/static-charge.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shocking-tendrils.c",
        "lib/guilds/scion/paths/sword/electricity/shockblade.c");
    addChild("lib/guilds/scion/paths/sword/electricity/static-charge.c",
        "lib/guilds/scion/paths/sword/electricity/sparks.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shock-brand.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shock-brand.c",
        "lib/guilds/scion/paths/sword/electricity/sweeping-shock.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/lightning.c");

    addChild("lib/guilds/scion/paths/sword/electricity/lightning.c",
        "lib/guilds/scion/paths/sword/electricity/sparks.c");
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/energized-blade.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/static-barrier.c");

    addChild("lib/guilds/scion/paths/sword/electricity/energized-blade.c",
        "lib/guilds/scion/paths/sword/electricity/shock-brand.c");
    addChild("lib/guilds/scion/paths/sword/electricity/static-barrier.c",
        "lib/guilds/scion/paths/sword/electricity/shocking-tendrils.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shocking-barrier.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/electrostatic-induction.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shocking-barrier.c",
        "lib/guilds/scion/paths/sword/electricity/shocking-tendrils.c");
    addChild("lib/guilds/scion/paths/sword/electricity/electrostatic-induction.c",
        "lib/guilds/scion/paths/sword/electricity/static-charge.c");
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/shocking-edge.c");

    addChild("lib/guilds/scion/paths/sword/electricity/shocking-edge.c",
        "lib/guilds/scion/paths/sword/electricity/energized-blade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/lightning-blast.c");

    addChild("lib/guilds/scion/paths/sword/electricity/lightning-blast.c",
        "lib/guilds/scion/paths/sword/electricity/lightning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/ionization.c");

    addChild("lib/guilds/scion/paths/sword/electricity/ionization.c",
        "lib/guilds/scion/paths/sword/electricity/electrostatic-induction.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/thunders-pommel.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/ionized-barrier.c");

    addChild("lib/guilds/scion/paths/sword/electricity/thunders-pommel.c",
        "lib/guilds/scion/paths/sword/electricity/shocking-edge.c");
    addChild("lib/guilds/scion/paths/sword/electricity/ionized-barrier.c",
        "lib/guilds/scion/paths/sword/electricity/static-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/electric-shroud.c");

    addChild("lib/guilds/scion/paths/sword/electricity/electric-shroud.c",
        "lib/guilds/scion/paths/sword/electricity/root.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/lightning-blade.c");

    addChild("lib/guilds/scion/paths/sword/electricity/lightning-blade.c",
        "lib/guilds/scion/paths/sword/electricity/shockblade.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/enhanced-discharge.c");

    addChild("lib/guilds/scion/paths/sword/electricity/enhanced-discharge.c",
        "lib/guilds/scion/paths/sword/electricity/ionization.c");
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/plasma-ball.c");

    addChild("lib/guilds/scion/paths/sword/electricity/plasma-ball.c",
        "lib/guilds/scion/paths/sword/electricity/lightning.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/static-shield.c");
    addResearchElement("lib/guilds/scion/paths/sword/electricity/plasma-barrier.c");

    addChild("lib/guilds/scion/paths/sword/electricity/static-shield.c",
        "lib/guilds/scion/paths/sword/electricity/electric-shroud.c");
    addChild("lib/guilds/scion/paths/sword/electricity/plasma-barrier.c",
        "lib/guilds/scion/paths/sword/electricity/ionized-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/tempest.c");

    addChild("lib/guilds/scion/paths/sword/electricity/tempest.c",
        "lib/guilds/scion/paths/sword/electricity/shocking-barrier.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/plasma-shield.c");

    addChild("lib/guilds/scion/paths/sword/electricity/plasma-shield.c",
        "lib/guilds/scion/paths/sword/electricity/static-shield.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/maelstrom.c");

    addChild("lib/guilds/scion/paths/sword/electricity/maelstrom.c",
        "lib/guilds/scion/paths/sword/electricity/lightning-blast.c");
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement("lib/guilds/scion/paths/sword/electricity/plasma-eruption.c");

    addChild("lib/guilds/scion/paths/sword/electricity/plasma-eruption.c",
        "lib/guilds/scion/paths/sword/electricity/enhanced-discharge.c");
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Bolt");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as electrical power.");

        addResearchElement("lib/guilds/scion/paths/sword/electricity/root.c");
        TreeRoot("lib/guilds/scion/paths/sword/electricity/root.c");

        FirstLevel();
        ThirdLevel();
        FifthLevel();
        SeventhLevel();
        NinthLevel();
        EleventhLevel();
        ThirteenthLevel();
        FifteenthLevel();
        SeventeenthLevel();
        NineteenthLevel();
        TwentyFirstLevel();
        TwentyThirdLevel();
        TwentyFifthLevel();
        TwentySeventhLevel();
        TwentyNinthLevel();
        ThirtyFirstLevel();
        ThirtyThirdLevel();
        ThirtyFifthLevel();
        ThirtySeventhLevel();
        ThirtyNinthLevel();
    }
}
