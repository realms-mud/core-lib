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
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/ice-bolt.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/ice-bolt.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frost-tendrils.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/frost-tendrils.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/ice-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/sweeping-frost.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/ice-javelin.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/ice-javelin.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/ice-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frost-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-reserve.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/freezing-brand.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/frost-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-reserve.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/freezing-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-boon.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/freezing-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/chill-the-blood.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frigid-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frost-wave.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/frost-wave.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/ice-javelin.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/winters-rage.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/winters-rage.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/freezing-mark.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/winters-boon.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frozen-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-call.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/winters-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/icy-edge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/frozen-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-call.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-reserve.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/ice-shroud.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-finess.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/ice-shroud.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-finess.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-boon.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/glacial-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/glacial-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/wind-chill.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/wind-chill.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/winters-rage.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/call-of-winter.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/call-of-winter.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-wave.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/freezing-shield.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/icy-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-might.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/freezing-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/ice-shroud.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/icy-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frozen-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-might.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-call.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/ice-storm.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-endurance.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/ice-storm.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/freezing-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-endurance.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-finess.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/ice-shield.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/ice-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/freezing-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/blizzard.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/blizzard.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frost-wave.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/icy-mark.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/icy-mark.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/wind-chill.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-fury.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-fury.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-might.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/scions-strength.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/scions-strength.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/scions-endurance.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/arctic-rage.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/arctic-rage.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/icy-mark.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/frigid-blast.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/frigid-blast.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/arctic-rage.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/bitter-frost.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/bitter-frost.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/frigid-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/ice/crushing-chill.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/ice/crushing-chill.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/ice/bitter-frost.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of the Frost");
    Source("Scion of Dhuras Guild");
    Description("This skill provides the user with the "
        "knowledge to express their raw magical energy as ices.");
    SetupResearch();

    if (WeaponType)
    {
        addResearchElement(sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));
        TreeRoot(sprintf("/guilds/scion/paths/%s/ice/root.c", WeaponType));

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
