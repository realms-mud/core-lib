//*****************************************************************************
// Copyright (c) 2024 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/sparks.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/sparks.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/shocking-tendrils.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/static-charge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/shocking-tendrils.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/static-charge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/sparks.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/sweeping-shock.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/lightning.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/lightning.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/sparks.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/energized-strike.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-reserve.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/energized-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shock-brand.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shocking-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-reserve.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/shocking-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-induction.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-boon.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/shocking-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shocking-tendrils.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-induction.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/static-charge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/energized-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/lightning-blast.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/lightning-blast.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/lightning.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/ionization.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/ionization.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/electrostatic-induction.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/thunders-boon.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-call.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/thunders-boon.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shocking-edge.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/static-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-call.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-reserve.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/electric-shroud.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-finess.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/electric-shroud.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-finess.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-boon.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/lightning-strike.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/lightning-strike.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shockstrike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/enhanced-discharge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/enhanced-discharge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/ionization.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/plasma-ball.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/plasma-ball.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/lightning.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/static-shield.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/plasma-barrier.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-might.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/static-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/electric-shroud.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/plasma-barrier.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/ionized-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-might.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-call.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/tempest.c", WeaponType));
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-endurance.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/tempest.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/shocking-barrier.c", WeaponType));
    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-endurance.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-finess.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/plasma-shield.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/plasma-shield.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/static-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/maelstrom.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/maelstrom.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/lightning-blast.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/plasma-eruption.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/plasma-eruption.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/enhanced-discharge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-fury.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-fury.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-might.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/scions-strength.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/scions-strength.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/scions-endurance.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FortyFifthLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/corona-discharge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/corona-discharge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/plasma-eruption.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftyFirstLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/enhanced-conductivity.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/enhanced-conductivity.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/corona-discharge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FiftySeventhLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-discharge.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-discharge.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/enhanced-conductivity.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SixtyThirdLevel()
{
    addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-condenser.c", WeaponType));

    addChild(sprintf("/guilds/scion/paths/%s/electricity/electrostatic-condenser.c", WeaponType),
        sprintf("/guilds/scion/paths/%s/electricity/electrostatic-discharge.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
protected void Setup()
{
    Name("Path of the Bolt");
    Source("Scion of Dhuras Guild");
    Description("This skill provides the user with the "
        "knowledge to express their raw magical energy as electrical power.");
    SetupResearch();

    if (WeaponType)
    {
        addResearchElement(sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));
        TreeRoot(sprintf("/guilds/scion/paths/%s/electricity/root.c", WeaponType));

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
