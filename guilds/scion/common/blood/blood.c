//*****************************************************************************
// Copyright (c) 2025 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/soulspike.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/soulspike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/choking-tendrils.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/choking-tendrils.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soulspike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/sweeping-torment.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/soul-shear.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/soul-shear.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soulspike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/malefic-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-reserve.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soul-brand.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/malefic-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/choking-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-reserve.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/enervating-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-boon.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/enervating-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/choking-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/parasitic-charge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scourge-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/sanguine-blast.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/sanguine-blast.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soul-shear.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/enervation.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/enervation.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/leechs-promise.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/corrupting-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-call.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/tortured-curse.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/wicked-edge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/corrupting-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/malefic-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-call.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-reserve.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/sanguine-shroud.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-finess.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/sanguine-shroud.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-finess.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-boon.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/malefic-strike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/malefic-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soulstrike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/malefic-discharge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/malefic-discharge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/enervation.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/carnage.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/carnage.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soul-shear.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/soul-shield.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/nefarious-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-might.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/soul-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/sanguine-shroud.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/nefarious-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/corrupting-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-might.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-call.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/bloodswarm.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-endurance.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/bloodswarm.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/enervating-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-endurance.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-finess.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/shield-of-corruption.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/shield-of-corruption.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/soul-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/destruction.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/destruction.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/sanguine-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/crimson-eruption.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/crimson-eruption.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/malefic-discharge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-fury.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-fury.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-might.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/scions-strength.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/scions-strength.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/scions-endurance.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/metastasis.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/metastasis.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/crimson-eruption.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/infectious-miasma.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/infectious-miasma.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/metastasis.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/septicemic-strike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/septicemic-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/infectious-miasma.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/blood/ulcerative-blight.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/blood/ulcerative-blight.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/blood/septicemic-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of Blood");
    Source("Scion of Dhuras Guild");
    Description("This skill provides the user with the knowledge to "
        "express their raw magical energy as blood magic.");
    SetupResearch();

    if (WeaponType)
    {
        addResearchElement(sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));
        TreeRoot(sprintf("/guilds/scion/paths/%s/blood/root.c", WeaponType));

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
