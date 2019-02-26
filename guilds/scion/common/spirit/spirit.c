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
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/root.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/sweeping-caress.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/sweeping-caress.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/tendrils-of-laiwyth.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/tendrils-of-laiwyth.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/sweeping-caress.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-shard.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-shard.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spirit-bolt.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void EleventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-strike.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-sheath.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-strike.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spectral-brand.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-sheath.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/tendrils-of-laiwyth.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-barrier.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/tendrils-of-laiwyth.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/chill-the-blood.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void FifteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-edge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-edge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-strike.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void SeventeenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/shadow-storm.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/shadow-storm.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-shard.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void NineteenthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spirit-mark.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/nienwyns-boon.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/strangle-the-soul.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/nienwyns-boon.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spectral-edge.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/strangle-the-soul.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-sheath.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-shroud.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-shroud.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/root.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyFifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/brand-of-laiwyth.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/brand-of-laiwyth.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-brand.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentySeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/nienwyns-kiss.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/nienwyns-kiss.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spectral-rage.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void TwentyNinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-scourge.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spirit-scourge.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/shadow-storm.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFirstLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-shield.c", WeaponType));
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/shadow-barrier.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-shield.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spirit-shroud.c", WeaponType));
    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/shadow-barrier.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/strangle-the-soul.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyThirdLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/soul-blight.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/soul-blight.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/spectral-barrier.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyFifthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/shield-the-spirit.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/shield-the-spirit.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/soul-shield.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtySeventhLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-storm.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/spectral-storm.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/shadow-storm.c", WeaponType));
}

/////////////////////////////////////////////////////////////////////////////
private void ThirtyNinthLevel()
{
    addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/laiwyths-mark.c", WeaponType));

    addChild(sprintf("lib/guilds/scion/paths/%s/spirit/laiwyths-mark.c", WeaponType),
        sprintf("lib/guilds/scion/paths/%s/spirit/nienwyns-kiss.c", WeaponType));
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
            "knowledge to express their raw magical energy as ices.");
        Setup();

        if (WeaponType)
        {
            addResearchElement(sprintf("lib/guilds/scion/paths/%s/spirit/root.c", WeaponType));
            TreeRoot(sprintf("lib/guilds/scion/paths/%s/spirit/root.c", WeaponType));

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
