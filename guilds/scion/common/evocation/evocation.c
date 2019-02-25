//*****************************************************************************
// Copyright (c) 2019 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected string WeaponType;

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void AdditionalResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/root.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/ionization.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/ionization.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/power-strike.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/power-strike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/ionization.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-ball.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-ball.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/energy-barrier.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/energy-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/tempest.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/tempest.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-shield.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-shield.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/maelstrom.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/maelstrom.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType));
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
        Setup();

        if (WeaponType)
        {
            addResearchElement(sprintf("lib/guilds/scion/paths/%s/evocation/root.c", WeaponType));
            TreeRoot(sprintf("lib/guilds/scion/paths/%s/evocation/root.c", WeaponType));

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
            AdditionalResearch();
        }
    }
}
