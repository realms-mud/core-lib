//*****************************************************************************
// Copyright (c) 2017-2026 - Allen Cummings, RealmsMUD, All rights reserved. See
//                      the accompanying LICENSE file for details.
//*****************************************************************************
inherit "/lib/modules/research/researchTree.c";

protected string WeaponType;

/////////////////////////////////////////////////////////////////////////////
protected void SetupResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
protected void AdditionalResearch()
{
}

/////////////////////////////////////////////////////////////////////////////
private void FirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/sweeping-energy.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energy-shard.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-reserve.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/mystic-brand.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-reserve.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-boon.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/eviscerating-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/mystic-charge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energized-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/ionization.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/ionization.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-conduit.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-call.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/dalreths-might.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-edge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/static-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-call.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-reserve.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-finess.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-finess.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-boon.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/power-strike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/power-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/ionization.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/plasma-ball.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/plasma-ball.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energy-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/energy-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-might.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/force-shroud.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/energy-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/kinetic-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-might.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-call.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/tempest.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-endurance.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/tempest.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-endurance.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-finess.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/plasma-shield.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/plasma-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/mystic-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/maelstrom.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/maelstrom.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/energy-storm.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/kinetic-discharge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-fury.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-fury.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-might.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/scions-strength.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/scions-strength.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/scions-endurance.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-condenser.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-condenser.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/plasma-eruption.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/magical-inductance.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/magical-inductance.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-condenser.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/kinetic-blast.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/kinetic-blast.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/magical-inductance.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/plasma-condenser.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/evocation/plasma-condenser.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/evocation/kinetic-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of the Beam");
    Source("Scion of Dhuras Guild");
    Description("This skill provides the user with the "
        "knowledge to express their raw magical energy as electrical power.");
    SetupResearch();

    if (WeaponType)
    {
        addResearchElement(sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));
        TreeRoot(sprintf("/guilds/scion/paths/%s/evocation/root.c", WeaponType));

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
        FortyFirstLevel();
        FortyThirdLevel();
        FortyFifthLevel();
        FiftyFirstLevel();
        FiftySeventhLevel();
        SixtyThirdLevel();
        AdditionalResearch();
    }
}
