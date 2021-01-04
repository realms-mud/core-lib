//*****************************************************************************
// Copyright (c) 2021 - Allen Cummings, RealmsMUD, All rights reserved. See
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
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/flame-bolt.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/fire-brand.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/flame-bolt.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/fire-brand.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fire-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/searing-tendrils.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/fuel-the-flames.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/searing-tendrils.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fire-brand.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/fuel-the-flames.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/flame-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/burning-brand.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/burning-brand.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/sweeping-flames.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/fire-bolt.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/fire-bolt.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/flame-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/flaming-barrier.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/burning-brand.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/flaming-barrier.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/searing-tendrils.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/burning-barrier.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/scorching-mark.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/burning-barrier.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/searing-tendrils.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/scorching-mark.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fuel-the-flames.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/inferno-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/fireball.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/fireball.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fire-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/stoking-rage.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/stoking-rage.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/scorching-mark.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/ferianths-boon.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/blazing-barrier.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/ferianths-boon.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/blazing-edge.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/blazing-barrier.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/flaming-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/fire-shroud.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/fire-shroud.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/searing-brand.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/searing-brand.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fire-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/enhanced-blaze.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/enhanced-blaze.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/stoking-rage.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno-spear.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/inferno-spear.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fireball.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/burning-shield.c", WeaponType));
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno-barrier.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/burning-shield.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fire-shroud.c", WeaponType));
    addChild(sprintf("guilds/scion/paths/%s/flame/inferno-barrier.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/blazing-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/inferno.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/burning-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno-shield.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/inferno-shield.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/burning-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/conflagration.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/conflagration.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/fireball.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("guilds/scion/paths/%s/flame/inferno-mark.c", WeaponType));

    addChild(sprintf("guilds/scion/paths/%s/flame/inferno-mark.c", WeaponType),
        sprintf("guilds/scion/paths/%s/flame/enhanced-blaze.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
public void reset(int arg)
{
    if (!arg)
    {
        researchTree::reset(arg);
        Name("Path of the Flame");
        Source("Scion of Dhuras Guild");
        Description("This skill provides the user with the "
            "knowledge to express their raw magical energy as flames.");
        Setup();

        if (WeaponType)
        {
            addResearchElement(sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType));
            TreeRoot(sprintf("guilds/scion/paths/%s/flame/root.c", WeaponType));

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
